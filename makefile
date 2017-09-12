# Compiler to use: gcc for C, g++ for C++
CC = g++

# libdir - directory containing libraries replace for folder
LIBDIR = C:/

# Compiler flags
# -Wall for most warnings -g for debugging information
CFLAGS = -Wall -g
CPPFLAGS =

# target - name of the output file
# Select to name output file main, otherwise name after enclosing directory
#TARGET = main
TARGET = $(lastword $(subst /, ,$(CURDIR)))

# sources - dependencies to create the output file
SOURCES = $(wildcard *.c *.cpp $(LIBDIR)/*.c $(LIBDIR)/*.cpp)

# make all: compile and link source code to an execcutable
%.o: %.c $(HEADERS) Makefile
	$(CC) $(CFLAGS) $(CPPFLAGS) $(TARGET_ARCH) -c -o $@ $<;

all: $(TARGET)
	$(CC) $(CFLAGS) -o $(TARGET) $(DEPS)

.PHONY: clean

clean:
	rm $(TARGET)
