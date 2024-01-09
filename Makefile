# Makefile

# Compiler to use
CXX = g++

# Compiler flags
CXXFLAGS = -Wall -Wextra -std=c++11

# Name of the output executable
TARGET = myprogram

# Default target
all: $(TARGET)

# Link the object files into a binary
$(TARGET): main.o
	$(CXX) $(CXXFLAGS) -o $(TARGET) main.o

# Compile the source files into object files
main.o: main.cpp Classes_n_Funcs.hpp PokemonLeague.hpp
	$(CXX) $(CXXFLAGS) -c main.cpp

# Clean target
clean:
	rm -f *.o $(TARGET)

# Run target
run: all
	./$(TARGET)
