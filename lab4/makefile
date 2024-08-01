# Makefile for compiling the threading example

# Compiler
CC = gcc

# Compiler flags
CFLAGS = -Wall -Wextra -pthread

# Target executable
TARGET = threading_example

# Source files
SRC = race.c

# Object files
OBJ = $(SRC:.c=.o)

# Default rule to build the target
all: $(TARGET)

# Rule to build the target from object files
$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^

# Rule to build object files from source files
%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<

# Helgrind check rule
helgrind: $(TARGET)
	valgrind --tool=helgrind ./$(TARGET)

# Clean rule to remove generated files
clean:
	rm -f $(TARGET) $(OBJ)


