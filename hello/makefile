# Makefile for hello.c

# Variables
CC = gcc
CFLAGS = -g -Wall -Wextra -std=c11
TARGET = hello 
VALGRIND = valgrind --leak-check=full --show-leak-kinds=all
VALGRIND_GDB = valgrind --leak-check=full --vgdb=yes --vgdb-error=0


# Default target
all: $(TARGET)

# Rule to build the target
$(TARGET): hello.c
	$(CC) $(CFLAGS) -o $(TARGET) hello.c

# Rule to run the program
run: $(TARGET)
	./$(TARGET)

# Rule to run the program with Valgrind
valgrind: $(TARGET)
	$(VALGRIND) ./hello world

# Rule to run the program with Valgrind with gdb
valgrind_gdb: $(TARGET)
	$(VALGRIND_GDB) ./hello world

# Rule to clean up generated files
clean:
	rm -f $(TARGET)

# Phony targets
.PHONY: all run valgrind clean
