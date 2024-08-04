# Compiler and flags
CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -pthread

# Source files and executable
SRC = singleton.cpp
OBJ = $(SRC:.cpp=.o)
EXE = singleton

# Default rule to build the executable
all: $(EXE)

# Rule to build the executable
$(EXE): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $@ $^

# Rule to build object files
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Rule to clean up generated files
clean:
	rm -f $(OBJ) $(EXE) 

# Phony targets
.PHONY: all clean
