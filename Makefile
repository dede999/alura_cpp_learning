# Compiler flags
CXXFLAGS = -O3
COVERAGE_FLAGS = --coverage -g -O0 -fprofile-arcs -ftest-coverage

# Directories
BIN_DIR = bin
COVERAGE_DIR = coverage
BUILD_DIR = build

%: %.cpp
	g++ $< $(CXXFLAGS) -o $(BIN_DIR)/$@

play_guessing_game: guessing_game
	./$(BIN_DIR)/guessing_game

forca: forca.cpp headers/forca/*.cpp
	g++ forca.cpp headers/forca/*.cpp $(CXXFLAGS) -o $(BIN_DIR)/forca

accounts: accounts.cpp headers/accounts/*.cpp
	g++ accounts.cpp headers/accounts/*.cpp $(CXXFLAGS) -o $(BIN_DIR)/accounts

play_forca: forca
	./$(BIN_DIR)/forca

see_accounts: accounts
	./$(BIN_DIR)/accounts

# Regular test target
test: test/main.cpp test/utils/*.cpp headers/**/*.cpp test/forca/*.cpp
	g++ $+ $(CXXFLAGS) -o $(BIN_DIR)/test
	./$(BIN_DIR)/test

# Test with coverage
test-coverage: test/main.cpp test/utils/*.cpp headers/**/*.cpp test/forca/*.cpp
	@mkdir -p $(BIN_DIR) $(COVERAGE_DIR)
	g++ test/main.cpp test/utils/*.cpp headers/forca/*.cpp test/forca/*.cpp $(COVERAGE_FLAGS) -o $(BIN_DIR)/test-coverage
	./$(BIN_DIR)/test-coverage

# Generate coverage report
coverage: test-coverage
	@echo "Generating coverage report..."
	@mkdir -p $(COVERAGE_DIR)
	lcov --capture --directory . --output-file $(COVERAGE_DIR)/coverage.info --ignore-errors inconsistent,unsupported,format,count
	lcov --remove $(COVERAGE_DIR)/coverage.info '/usr/*' '*/test/*' '/Library/*' '/opt/*' --output-file $(COVERAGE_DIR)/coverage_filtered.info --ignore-errors inconsistent,unsupported,format,count,unused
	genhtml $(COVERAGE_DIR)/coverage_filtered.info --output-directory $(COVERAGE_DIR)/html --ignore-errors inconsistent,unsupported,format,count
	@echo "Coverage report generated in $(COVERAGE_DIR)/html/index.html"

# Clean coverage files
clean-coverage:
	rm -f *.gcno *.gcda *.gcov
	rm -rf $(COVERAGE_DIR)

clean:
	rm -f $(BIN_DIR)/*
	rm -f *.gcno *.gcda *.gcov
	rm -rf $(COVERAGE_DIR)

# Install coverage tools (macOS)
install-coverage-tools:
	@echo "Installing lcov..."
	@if command -v brew >/dev/null 2>&1; then \
		brew install lcov; \
	else \
		echo "Homebrew not found. Please install lcov manually."; \
	fi

all: guessing_game forca accounts