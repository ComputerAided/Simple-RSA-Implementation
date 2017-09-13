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
SOURCES = $(wildcard *.cpp $(LIBDIR)/*.cpp)
#HEADERS = $(SOURCES:.cpp=.h)
OBJECTS = $(SOURCES:.cpp=.o)

# make all: compile and link source code to an execcutable
%.o: %.c
	$(CC) -c $(CFLAGS) $(CPPFLAGS) $< -o $@

all: $(OBJECTS)
	echo "Sources are $(SOURCES); objects are $(OBJECTS)"
	$(CC) $(CFLAGS) $(CPPFLAGS) -o $(TARGET) $^

.PHONY: clean

clean:
	rm -f $(TARGET) $(OBJECTS)
