# Makefile for compiling a project with main.cpp and classes_n_funcs.cpp

# Compiler to use
CXX = g++

# Compiler flags
CXXFLAGS = -Wall -g

# Executable name
TARGET = my_program

# Object files
OBJS = main.o classes_n_funcs.o

# Header files
HEADERS = PokemonLeague.hpp Classes_n_Funcs.hpp

# Default target
all: $(TARGET)

# Rule to link the program
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)

# Rule to compile main.cpp
main.o: main.cpp $(HEADERS)
	$(CXX) $(CXXFLAGS) -c main.cpp

# Rule to compile classes_n_funcs.cpp
classes_n_funcs.o: classes_n_funcs.cpp $(HEADERS)
	$(CXX) $(CXXFLAGS) -c classes_n_funcs.cpp

# Clean target
clean:
	rm -f $(OBJS) $(TARGET)

# Phony targets
.PHONY: all clean
