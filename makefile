CC = g++
CFLAGS = -g -fprofile-arcs -ftest-coverage

MAIN = main
TEST = test


OBJS = Garden.o Plant.o Crop.o PlantCare.o Nursery.o \
	CustomerCare.o People.o Staff.o Customer.o Request.o \
	Builder.o CropBuilder.o PlantBuilder.o BuildPlant.o \
	Director.o Iterator.o Payment.o EFT.o Card.o Cash.o \
	BaseStaff.o Roles.o Sales.o Gardening.o Admin.o Management.o \
	StaffCo_ordination.o Command.o CheckInventory.o \
	High.o Medium.o Low.o PlantState.o Planted.o \
	CheckPlant.o HireStaff.o FireStaff.o 
		

MAIN_OBJS = $(OBJS) Main.o

TEST_OBJS = $(OBJS) TestingMain.o

all: $(MAIN) $(TEST)

$(MAIN): $(MAIN_OBJS)
	$(CC) $(CFLAGS) $(MAIN_OBJS) -o $(MAIN)

$(TEST): $(TEST_OBJS)
	$(CC) $(CFLAGS) $(TEST_OBJS) -o $(TEST)

%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(MAIN) $(TEST) $(MAIN_OBJS) $(TEST_OBJS) *.gcno *.gcda *.gcov coverage.info
	rm -rf out

run-main: $(MAIN)
	./$(MAIN)

run-test: $(TEST)
	./$(TEST)

valgrind-main: $(MAIN)
	valgrind --leak-check=full --track-origins=yes ./$(MAIN)

valgrind-test: $(TEST)
	valgrind --leak-check=full --track-origins=yes ./$(TEST)

coverage-test: clean $(TEST)
	./$(TEST)
	lcov --capture --directory . --output-file coverage.info
	genhtml coverage.info --output-directory out
	@echo "Open coverage report: out/index.html"

coverage-main: clean $(MAIN)
	./$(MAIN)
	lcov --capture --directory . --output-file coverage.info
	genhtml coverage.info --output-directory out
	@echo "Open coverage report: out/index.html"

LINT_FLAGS = --quiet --linelength=120 --filter=-whitespace/line_length,-build/namespaces,-runtime/explicit
TIDY_FLAGS = -checks=clang-analyzer-*,-cppcoreguidelines-explicit-ctor,-modernize-use-explicit

lint:
	clang-format -i *.cpp *.h
	cpplint $(LINT_FLAGS) *.cpp *.h
# 	clang-tidy $(TIDY_FLAGS) *.cpp *.h -- -I
