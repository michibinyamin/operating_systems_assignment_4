# Default values for parameters
VERTICES ?= 5
EDGES ?= 7
SEED ?= 1234

CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -O2

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

# Clean rule to remove generated files
clean:
	rm -f EulerCircle