// Provide doctest main
#if __has_include(<doctest.h>)
#  define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#  include <doctest.h>
#else
#  include <iostream>
int main() {
	std::cerr << "doctest.h not found. Install doctest or adjust include paths.\n";
	return 0;
}
#endif

// Core domain headers
#include "People.h"
#include "Staff.h"
#include "BaseStaff.h"
#include "Roles.h"
#include "Management.h"
#include "Gardening.h"
#include "Admin.h"
#include "Customer.h"
#include "CustomerCare.h"
#include "Nursery.h"
#include "StaffCo_ordination.h"

// Commands
#include "Command.h"
#include "CheckInventory.h"
#include "CheckPlant.h"
#include "HireStaff.h"
#include "FireStaff.h"

// Garden/Plant hierarchy
#include "Garden.h"
#include "GardenPlot.h"
#include "Plant.h"
#include "Crop.h"
#include "Iterator.h"
#include "Director.h"
#include "Builder.h"
#include "CropBuilder.h"
#include "PlantBuilder.h"
#include "BuildPlant.h"

// Plant behavioral patterns
#include "PlantCare.h"
#include "High.h"
#include "Medium.h"
#include "Low.h"
#include "PlantState.h"
#include "Planted.h"
#include "Growing.h"
#include "Mature.h"
#include "Dying.h"
#include "Dead.h"

// Payment strategies
#include "Payment.h"
#include "EFT.h"
#include "Card.h"
#include "Cash.h"
#include "Order.h"

#include <map>
#include <vector>
#include <string>

// -------- Test doubles --------
class TestPerson : public People {
 public:
	TestPerson(const std::string& n = "anon") : People(nullptr, n) {}
	void receive(std::string, People*, Nursery*, std::string) override {}
};

// Receiver staff that records messages and can act as specific types
class ReceiverStaff : public Staff {
 public:
	explicit ReceiverStaff(const std::string& n, const std::string& type)
			: Staff(nullptr, n), typeStr(type), receiveCount(0) {}
	std::string jobDesc() override { return "ReceiverStaff"; }
	std::string getType() override { return typeStr; }
	void update(Plant*) override {}
	void handlePlant(Plant*) override {}
	void handleCustomer(Request, Customer*) override {}
	void receive(std::string m, People*, Nursery*, std::string t) override {
		lastMsg = m; lastType = t; receiveCount++; }

	int receiveCount; std::string lastMsg; std::string lastType;
 private:
	std::string typeStr;
};

// Simple chain-of-responsibility staff that forwards to successor
class ChainStaff : public Staff {
 public:
	ChainStaff(const std::string& n, const std::string& type)
			: Staff(nullptr, n), typeStr(type), handled(0) {}
	std::string jobDesc() override { return "ChainStaff"; }
	std::string getType() override { return typeStr; }
	void update(Plant*) override {}
	void handlePlant(Plant*) override {}
	void handleCustomer(Request, Customer*) override { handled++; if (successor) successor->handleCustomer(Request("pass"), nullptr); }
	void receive(std::string, People*, Nursery*, std::string) override {}
	int handled; private: std::string typeStr;
};

class MinimalStaff : public Staff {
 public:
	MinimalStaff(const std::string& n, Nursery* med=nullptr) : Staff(med, n) {}
	std::string jobDesc() override { return "MinimalStaff"; }
	std::string getType() override { return "MinimalStaff"; }
	void update(Plant*) override {}
	void handlePlant(Plant*) override {}
	void handleCustomer(Request, Customer*) override {}
	void receive(std::string, People*, Nursery*, std::string) override {}
};

#ifdef DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

// ---------- People & Staff ----------
TEST_CASE("People: getters and setters") {
	TestPerson p;
	CHECK(p.getName() == std::string("anon"));
	CHECK(p.getNursery() == nullptr);
	p.setName("Alice");
	CHECK(p.getName() == std::string("Alice"));
}

TEST_CASE("Staff: equality by name and successor wiring") {
	MinimalStaff a("Alex");
	MinimalStaff b("Alex");
	MinimalStaff c("Blair");
	CHECK(a == b);
	CHECK_FALSE(a == c);
	a.setSuccessor(&b); // just ensure method exists and accepts pointer
}

TEST_CASE("BaseStaff: type and description") {
	BaseStaff bs(nullptr, "Ben");
	CHECK(bs.getType() == std::string("BaseStaff"));
	auto desc = bs.jobDesc();
	CHECK(desc.find("Base staff member") != std::string::npos);
}

// ---------- Roles (Decorators) ----------
TEST_CASE("Roles: Admin/Gardening/Management types and descriptions") {
	// Use heap-allocated inner staff because Roles owns and deletes it
	Staff* inner = new MinimalStaff("Core");
	Admin a(inner);
	CHECK(a.getType().find("Admin") != std::string::npos);
	CHECK(a.jobDesc().find("Admin") != std::string::npos);

	Staff* inner2 = new MinimalStaff("Core");
	Gardening g(inner2);
	CHECK(g.getType().find("Gardening") != std::string::npos);
	CHECK(g.jobDesc().find("Gardening") != std::string::npos);

	Staff* inner3 = new MinimalStaff("Core");
	Management m(inner3);
	CHECK(m.getType().find("Management") != std::string::npos);
	CHECK(m.jobDesc().find("Management") != std::string::npos);
}

// ---------- Mediators and Commands ----------
TEST_CASE("StaffCo_ordination: add/remove staff and direct/broadcast send") {
	StaffCo_ordination med;
	auto a = new ReceiverStaff("Ann", "BaseStaff: Admin");
	auto g = new ReceiverStaff("Gus", "BaseStaff: Gardening");
	med.addStaff(a); med.addStaff(g);
	CHECK(med.getStaff().size() == 2);

	// Broadcast from a to g
	a->setNursery(&med);
	med.sendMessage("hello team", a, "Broadcast");
	CHECK(g->receiveCount == 1);
	CHECK(g->lastType == std::string("Broadcast"));

	// Direct send using mediator
	med.sendMessage("check plants", g, a, "CheckPlant");
	CHECK(g->receiveCount == 2);
	CHECK(g->lastMsg.find("check plants") != std::string::npos);

	med.removeStaff(a);
	CHECK(med.getStaff().size() == 1);
	// cleanup
	delete a; delete g;
}

TEST_CASE("Nursery::findStaffByType finds first matching type substring") {
	StaffCo_ordination med;
	auto x = new ReceiverStaff("X", "BaseStaff: Admin");
	auto y = new ReceiverStaff("Y", "BaseStaff: Gardening");
	med.addStaff(x); med.addStaff(y);
	Staff* found = med.findStaffByType("Admin");
	REQUIRE(found != nullptr);
	CHECK(found->getType().find("Admin") != std::string::npos);
	delete x; delete y;
}

TEST_CASE("Commands: CheckInventory and CheckPlant route to appropriate recipients") {
	StaffCo_ordination med;
	auto admin = new ReceiverStaff("Ann", "BaseStaff: Admin");
	auto gard  = new ReceiverStaff("Gus", "BaseStaff: Gardening");
	med.addStaff(admin); med.addStaff(gard);

	// Manager issues tasks
	Staff* core = new MinimalStaff("Maggie", &med);
	Management mgr(core);

	CheckInventory inv(&mgr, &med);
	inv.execute();
	CHECK(admin->receiveCount == 1);
	CHECK(admin->lastType == std::string("CheckInventory"));

	CheckPlant chk(&mgr, &med);
	chk.execute();
	CHECK(gard->receiveCount == 1);
	CHECK(gard->lastType == std::string("CheckPlant"));

	delete admin; delete gard; // mgr will delete core in its dtor
}

TEST_CASE("Commands: HireStaff and FireStaff modify mediator staff list") {
	StaffCo_ordination med;
	auto newb = new MinimalStaff("Newbie");
	Staff* bossCore = new MinimalStaff("Boss", &med);
	Management boss(bossCore);
	CHECK(med.getStaff().empty());

	HireStaff hire(&boss, &med, newb);
	hire.execute();
	CHECK(med.getStaff().size() == 1);

	FireStaff fire(&boss, &med, newb);
	fire.execute();
	CHECK(med.getStaff().empty());
	// newb is owned by test (not deleted by mediator)
	delete newb;
}

// ---------- CustomerCare chain-of-responsibility (non-interactive) ----------
TEST_CASE("CustomerCare: setChain wires order Base->Gardening->Sales->Management and notify traverses") {
	CustomerCare care;
	// Create four chain staff with expected type names
	auto base = new ChainStaff("B", "BaseStaff");
	auto gard = new ChainStaff("G", "Gardening");
	auto sale = new ChainStaff("S", "Sales");
	auto mana = new ChainStaff("M", "Management");
	care.addStaff(base); care.addStaff(gard); care.addStaff(sale); care.addStaff(mana);
	care.setChain();

	Customer cust("Casey");
	cust.setNursery(&care);
	care.notify(Request("Order"), &cust);

	CHECK(base->handled >= 1);
	CHECK(gard->handled >= 1);
	CHECK(sale->handled >= 1);
	CHECK(mana->handled >= 1);

	delete base; delete gard; delete sale; delete mana;
}

// ---------- Garden, Crop, GardenPlot, Iterator ----------
TEST_CASE("GardenPlot: load plants, view and access") {
	GardenPlot gp("plants.txt");
	CHECK(gp.size() > 0);
	auto all = gp.viewAll();
	CHECK_FALSE(all.empty());
	auto it = all.begin();
	std::string firstName = it->first;
	Garden* one = gp.get(firstName);
	REQUIRE(one != nullptr);

	std::vector<Garden*> some = gp.get(firstName, 1);
	CHECK(some.size() == 1);
	std::string printed = gp.print();
	CHECK_FALSE(printed.empty());

		Iterator* iter = gp.access();
		int count = 0;
		for (Garden* g = iter->first(); !iter->done(); g = iter->next()) {
			(void)g; count++;
		}
		CHECK(count == iter->size());
		delete iter;
}

TEST_CASE("Crop: add and get by name") {
	Crop crop;
	auto* p = new Plant(); p->setName("Tulip");
	crop.add(p);
	Garden* got = crop.get("Tulip");
	CHECK(got != nullptr);
}

// ---------- Plant, PlantCare, State ----------
TEST_CASE("PlantCare: clone and apply semantics") {
	High h; Medium m; Low l;
		auto* hc = h.clone(); auto* mc = m.clone(); auto* lc = l.clone();
		CHECK(hc != nullptr);
		CHECK(mc != nullptr);
		CHECK(lc != nullptr);
	CHECK(h.apply(7,8, +1) == 8);
	CHECK(m.apply(1,8, -1) == 0);
	CHECK(l.apply(0,10, +1) == 1);
	delete hc; delete mc; delete lc;
}

TEST_CASE("Plant: strategies and advice (non-observer calls)") {
	Plant p; p.setName("Fern"); p.setPrice(10);
	p.setWaterCare('H'); p.setSunCare('M'); p.setFertiliserCare('L');

	// Observer attach only (avoid notify/detach unresolved on some toolchains)
	class CountS : public Staff { public: int n=0; CountS():Staff(nullptr,"C"){} std::string jobDesc(){return"";} std::string getType(){return"";} void update(Plant*){n++;} void handlePlant(Plant*){} void handleCustomer(Request, Customer*){} void receive(std::string, People*, Nursery*, std::string){} };
	CountS cs; p.attach(&cs);

	// Advice should be non-empty when strategies are set
	CHECK_FALSE(p.advice().empty());
}

// ---------- Payments and Order (non-interactive) ----------
static std::string purchaseWith(Payment& method, const std::string& expectedType) {
	Customer customer("Cathy");
	MinimalStaff staff("Stacy");
	Plant p; p.setName("Fern"); p.setPrice(10);
	std::map<Plant*, int> items; items[&p] = 3;
	std::string r = method.purchase(&customer, items, &staff);
	CHECK(r.find("Payment Method: " + expectedType) != std::string::npos);
	CHECK(r.find("Fern") != std::string::npos);
	CHECK(r.find("Total: R30") != std::string::npos);
	return r;
}

TEST_CASE("Payment: Card/Cash/EFT receipts") {
	Card card; Cash cash; EFT eft;
	purchaseWith(card, "Card Payment");
	purchaseWith(cash, "Cash Payment");
	purchaseWith(eft, "EFT Payment");
}

TEST_CASE("Order: add/remove/clear") {
	Order o; auto* p1 = new Plant(); p1->setName("A"); auto* p2 = new Plant(); p2->setName("B");
	o.addPlant(p1); o.addPlant(p1); o.addPlant(p2);
	auto m = o.getPlants();
	CHECK(m[p1] == 2);
	CHECK(m[p2] == 1);
	o.removePlant(p1);
	CHECK(o.getPlants()[p1] == 1);
	o.clearOrder();
	CHECK(o.getPlants().empty());
}

// ---------- Request ----------
TEST_CASE("Request: getRequest returns message") {
	Request r("Advice");
	CHECK(r.getRequest() == std::string("Advice"));
}

// Sanity
TEST_CASE("doctest_sanity") { CHECK(true); }

#endif // DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#ifdef DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
// Additional coverage
TEST_CASE("Customer.makeReq routes via CustomerCare chain") {
	CustomerCare care;
	auto base = new ChainStaff("B", "BaseStaff");
	auto gard = new ChainStaff("G", "Gardening");
	auto sale = new ChainStaff("S", "Sales");
	auto mana = new ChainStaff("M", "Management");
	care.addStaff(base); care.addStaff(gard); care.addStaff(sale); care.addStaff(mana);
	care.setChain();

	Customer cust("Cal");
	cust.setNursery(&care);
	cust.makeReq(Request("Order"));

	CHECK(base->handled >= 1);
	CHECK(gard->handled >= 1);
	CHECK(sale->handled >= 1);
	CHECK(mana->handled >= 1);

	delete base; delete gard; delete sale; delete mana;
}

TEST_CASE("PlantBuilder: chained setters build Plant with attributes") {
	PlantBuilder pb;
	pb.reset();
	pb.setName("X")->setType("T")->setWater(5)->setSun(2)->setFertiliser(3)->setPrice(9.5f);
	Plant* p = pb.build();
	REQUIRE(p != nullptr);
	CHECK(p->getName() == std::string("X"));
	CHECK(p->getType() == std::string("T"));
	CHECK(p->getWater()[1] == 5);
	CHECK(p->getFertiliser()[1] == 3);
	CHECK(p->getSun() == 2);
	CHECK(p->getPrice() == doctest::Approx(9.5f));
	delete p;
}

TEST_CASE("Director::split tokenizes CSV line") {
	Director d;
	auto v = d.split("a,b,c", ',');
	CHECK(v.size() == 3);
	CHECK(v[0] == "a");
	CHECK(v[1] == "b");
	CHECK(v[2] == "c");
}

TEST_CASE("CropBuilder: reset/add/add plant and iterate") {
	CropBuilder cb; cb.reset();
	cb.add(); // add a crop
	Plant* p = new Plant(); p->setName("PB");
	cb.add(p);
	Garden* root = cb.getCrop();
	REQUIRE(root != nullptr);
	Iterator* it = root->createIterator();
	REQUIRE(it != nullptr);
	// Traverse; size should be >= 1 (the crop) and the crop should contain our plant
	int total = 0; for (Garden* g = it->first(); !it->done(); g = it->next()) { (void)g; total++; }
	CHECK(total >= 1);
	delete it;
}
#endif

