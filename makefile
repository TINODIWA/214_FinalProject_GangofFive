CC = g++
CFLAGS = -g -fprofile-arcs -ftest-coverage

MAIN = main
TEST = test

OBJS = 
		

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