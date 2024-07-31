# Default values for parameters
VERTICES ?= 5
EDGES ?= 7
SEED ?= 1

CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -O2
PROF_FLAGS = -pg
COVERAGE_FLAGS = -fprofile-arcs -ftest-coverage

# Define the target executable and source file
TARGET = EulerCircle
SRC = EulerCircle.cpp

all: $(TARGET)

# Rule to build the executable
$(TARGET): $(SRC)
	$(CXX) $(CXXFLAGS) $(SRC) -o $(TARGET)

# Rule to run the executable with parameters
run: $(TARGET)
	./$(TARGET) -v $(VERTICES) -e $(EDGES) -s $(SEED)

# Rule to build and profile the executable, then generate the report
profile_code: $(SRC)
	$(CXX) $(CXXFLAGS) $(PROF_FLAGS) $(SRC) -o $(TARGET)
	./$(TARGET) -v $(VERTICES) -e $(EDGES) -s $(SEED)
	gprof $(TARGET) gmon.out > profile_report.txt
	rm -f gmon.out
	cat profile_report.txt

coverage_report: $(SRC)
	$(CXX) $(CXXFLAGS) $(COVERAGE_FLAGS) $(SRC) -o $(TARGET)
	./$(TARGET) -v $(VERTICES) -e $(EDGES) -s $(SEED)
	gcov $(SRC) > coverage_report.txt
	cat coverage_report.txt

# Clean rule to remove generated files
clean:
	rm -f $(TARGET) gmon.out profile_report.txt coverage_report.txt
