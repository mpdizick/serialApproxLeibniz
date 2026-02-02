# Makefile for Pi Approximation Program
# CSCI 473 - Homework 2
# Spring 2025

# Compiler and flags
CC = gcc
CFLAGS = -Wall -Wextra -O2 -std=c99 -D_POSIX_C_SOURCE=199309L -D_GNU_SOURCE
LDFLAGS = -lm -lrt

# Target executable name
TARGET = pi_approx

# Source files
SRCS = main.c pi_functions.c
OBJS = $(SRCS:.c=.o)
HEADERS = pi_functions.h

# Default target
all: $(TARGET)

# Build the executable
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS) $(LDFLAGS)
	@echo "Build complete! Run with: ./$(TARGET) <n>"

# Compile main.c
main.o: main.c $(HEADERS)
	$(CC) $(CFLAGS) -c main.c

# Compile pi_functions.c
pi_functions.o: pi_functions.c $(HEADERS)
	$(CC) $(CFLAGS) -c pi_functions.c

# Clean build artifacts
clean:
	rm -f $(OBJS) $(TARGET)
	@echo "Cleaned build artifacts"

# Clean and rebuild
rebuild: clean all

# Run with a default value (for testing)
test: $(TARGET)
	./$(TARGET) 1000000

# Help target
help:
	@echo "Available targets:"
	@echo "  all      - Build the program (default)"
	@echo "  clean    - Remove object files and executable"
	@echo "  rebuild  - Clean and rebuild"
	@echo "  test     - Build and run with n=1000000"
	@echo "  help     - Show this help message"

.PHONY: all clean rebuild test help