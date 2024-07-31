# Makefile for hello.c

# Variables
CC = gcc
CFLAGS = -Wall -Wextra -std=c11
TARGET = hello
VALGRIND = valgrind --leak-check=full --show-leak-kinds=all

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
	$(VALGRIND) ./$(TARGET)

# Rule to clean up generated files
clean:
	rm -f $(TARGET)

# Phony targets
.PHONY: all run valgrind clean
