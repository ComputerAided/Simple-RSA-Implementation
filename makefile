# Compiler to use: gcc for C, g++ for C++
CC = g++

# Compiler flags
# -Wall for most warnings -g for debugging information
CFLAGS = -Wall -g

# target - name of the output file
TARGET = main

# deps - dependencies to create the output file
DEPS = main.cpp

# make all: compile and link source code to an execcutable
all: $(TARGET)
	$(CC) $(CFLAGS) -o $(TARGET) $(DEPS)

.PHONY: clean

clean:
	rm $(TARGET)
