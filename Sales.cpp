/**
 * @file Sales.cpp
 * @author Unathi Tshakalisa, Nathan Chisadza 
 * @brief Implementation of the Sales class, responsible for handling customer orders and repurchases in the nursery system
 * @version 0.1
 * @date 2025-10-29
 *
 * @copyright Copyright (c) 2025
 *
 */

#include "Sales.h"
#include <iostream>
#include "CustomerCare.h"
#include "Customer.h"
#include "Order.h"


/**
 * @brief Construct a new Sales object
 * @param s Pointer to the staff member
 */
Sales::Sales(Staff* s) : Roles(s->getNursery(), s->getName(), s) {}


/**
 * @brief Destroy the Sales object
 */
Sales::~Sales() {}


/**
 * @brief Get the type of staff role
 * @return string The type of staff role
 */
string Sales::getType() {
  return Roles::getType() + ": Sales";
}

/**
 * @brief Get the job description for this staff role.
 */
std::string Sales::jobDesc() {
  return Roles::jobDesc() + "\nAdditionally, Sales staff are responsible for assisting customers with their purchases.";
}

/**
 * @brief Handle customer requests for orders and repurchases
 * @param req The customer request
 * @param customer Pointer to the customer
 */
void Sales::handleCustomer(Request req, Customer* customer) {
  if (!customer) {
    std::cout << "Error: No customer assigned. Cannot proceed.\n";
    return;
  }

  if (!nursery) {
    std::cout << "Error: Nursery is not available. Please try again later.\n";
    return;
  }

  if (req.getRequest() == "Order") {
    std::cout << "I am " << name << " and I will be assisting you.\n\n";

    // Cart: plant name -> quantity ordered
    std::map<std::string, int> cart;

    bool ordering = true;
    while (ordering) {
      // Get current available inventory
      auto inventory = nursery->getGarden()->viewAvailable();

      if (inventory.empty()) {
        std::cout << "Unfortunately, we currently have no plants available for sale.\n";
        return;
      }

      std::string inventoryList = printAll(inventory);
      std::cout << inventoryList << "\tPlease enter the number of the plant you'd like to add below,\n"
                << "\tfollowed by the quantity.\n"
                << "\te.g.) Number: 1 \n\tQuantity: 5\n\n";

      int maxIndex = static_cast<int>(inventory.size());

      int plantId = readIntInRange(1, maxIndex, "\tNumber: ", inventoryList + "\nPlease enter a valid number: ");

      auto it = inventory.begin();
      std::advance(it, plantId - 1);
      const std::string& plantName = it->first;
      int availableQty = it->second;

      std::cout << "You selected: " << plantName << " (Available: " << availableQty << ")\n";

      int quantity = readIntInRange(1, availableQty,
                                    "Quantity: ", "Please enter a valid quantity (>= 1 and <= available stock): ");

      cart[plantName] += quantity;

      std::cout << "\nCurrent order contents:\n";
      if (cart.empty()) {
        std::cout << "\t<No plants added yet>\n";
      } else {
        int idx = 1;
        for (const auto& [name, qty] : cart) {
          std::cout << "\t" << idx++ << ") " << name << " x " << qty << "\n";
        }
      }

      std::cout << "\nWould you like to:\n"
                << "\t1) Add more plants.\n"
                << "\t2) Remove a plant from order.\n"
                << "\t3) Place your order.\n"
                << "\t4) Cancel order.\n";

      int next = readIntInRange(1, 4, "Please enter a number: ", "Please enter a valid number (1-3): ");

      switch (next) {
        case 1: {
          break;
        }

        case 2: {
          if (cart.empty()) {
            std::cout << "There are no plants in your order to remove.\n";
            break;
          }

          std::cout << "\nWhich plant would you like to remove?\n";
          int idx = 1;
          std::vector<std::string> cartKeys;
          for (const auto& [name, qty] : cart) {
            std::cout << "\t" << idx << ") " << name << " x " << qty << "\n";
            cartKeys.push_back(name);
            ++idx;
          }

          int removeChoice = readIntInRange(1, static_cast<int>(cartKeys.size()),
                                            "Enter number of plant to remove: ", "Please enter a valid number.\n");

          const std::string& toRemove = cartKeys[removeChoice - 1];
          cart.erase(toRemove);
          std::cout << "Removed " << toRemove << " from your order.\n";
          break;
        }

        case 3: {
          if (cart.empty()) {
            std::cout << "Your order is empty. No order placed.\n";
            ordering = false;
            break;
          }

          Order* order = new Order();
          order->setCustomer(customer);
          order->setStaff(this);

          for (const auto& item : cart) {
            const string& name = item.first;
            int qty = item.second;
            vector<Garden*> plants = nursery->getGarden()->get(name, qty);
            for (auto plant : plants) {
              Plant* plantPtr = dynamic_cast<Plant*>(plant);
              if (!plantPtr) {
                std::cout << "Error: plant is not of type Plant*\n";
                return;
              }
              order->addPlant(plantPtr);
            }
          }

          order->purchase(nursery->getDay());
          customer->addOrder(order);  // via mediator???
          std::cout << "Thanks for shopping with GoF Nursery.\n"
                       "Advice on your plants is attached in the receipt :)\n";
          ordering = false;
          break;
        }
        case 4:
          std::cout << "Purchasing logic. Thanks for shopping with GoF Nursery.\n"
                       "Hope to see you again soon :)\n";
          ordering = false;
          break;

        default:
          std::cout << "Error in request case switch!\n";
          ordering = false;
          break;
      }
    }
  } else if (req.getRequest() == "Repurchase") {
    vector<Order*> history = customer->getOrderHistory();
    if (history.empty()) {
      std::cout << "You have no previous orders to repurchase.\n";
      return;
    }

    std::cout << "Your previous orders:\n";
    for (size_t i = 0; i < history.size(); ++i) {
      std::cout << "\t" << (i + 1) << ") " << history[i]->printOldOrder() << "\n";
    }

    int choice = readIntInRange(1, history.size(), "Select an order to repurchase: ", "Please enter a valid number.\n");

    Order* oldOrder = history[choice - 1];
    map<Plant*, int> oldPlants = oldOrder->getPlants();
    Order* newOrder = new Order();  // use copy constructor
    newOrder->setStaff(this);
    newOrder->setCustomer(customer);

    for (const auto& plantPair : oldPlants) {
      Plant* oldPlant = plantPair.first;
      int quantity = plantPair.second;
      vector<Garden*> newPlants = nursery->getGarden()->get(oldPlant->getName(), quantity);
      for (auto p : newPlants) {
        Plant* plantPtr = dynamic_cast<Plant*>(p);
        if (!plantPtr) {
          std::cout << "Error: plant is not of type Plant*\n";
          return;
        }
        newOrder->addPlant(plantPtr);
      }
    }

    newOrder->purchase(nursery->getDay());
    customer->addOrder(newOrder);

    std::cout << "Order repurchased successfully.\n";
    std::cout << "Thanks for shopping with GoF Nursery.\n"
                 "Advice on your plants is attached in the receipt :)\n";

  } else if (successor) {
    successor->handleCustomer(req, customer);
  } else {
    std::cout << "No staff could handle the request.\n";
  }
}


/**
 * @brief Receive and handle messages from other staff members
 * @param m The message content
 * @param from The sender of the message
 * @param group The nursery group context
 * @param type The type of message
 */
void Sales::receive(string m, People* from, Nursery* group, string type) {
  if (!(from || group)) return;
  std::cout << "[Sales::receive] from: " << (from ? from->getName() : std::string("unknown")) << ", type: " << type
            << ", msg: " << m << std::endl;
}


/**
 * @brief Update method for plant state changes (stub)
 * @param p Pointer to the plant that has been updated
 */
void Sales::update(Plant* p) {} // stubbed

/**
 * @brief Handle plant-related tasks (stub)
 * @param p Pointer to the plant to handle
 */
void Sales::handlePlant(Plant* p) {} // stubbed