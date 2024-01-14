# Compiler to use
CXX = g++

# Compiler flags
CXXFLAGS =  -g

# Executable name
TARGET = pokemon_battle

# Object files
OBJS = main.o classes_n_funcs.o

# Header files
HEADERS = src/PokemonLeague.hpp src/Classes_n_Funcs.hpp

# Default target
all: $(TARGET)

# Rule to link the program
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)

# Rule to compile main.cpp
main.o: src/main.cpp $(HEADERS)
	$(CXX) $(CXXFLAGS) -c src/main.cpp

# Rule to compile classes_n_funcs.cpp
classes_n_funcs.o: src/classes_n_funcs.cpp $(HEADERS)
	$(CXX) $(CXXFLAGS) -c src/classes_n_funcs.cpp

# Rule to compile and run test1
test1:
	$(CXX) $(CXXFLAGS) -o test1.out testfiles/test1.cpp src/classes_n_funcs.cpp
	./test1.out

# Rule to compile and run test2
test2:
	$(CXX) $(CXXFLAGS) -o test2.out testfiles/test2.cpp src/classes_n_funcs.cpp
	./test2.out

# Rule to compile and run test3
test3:
	$(CXX) $(CXXFLAGS) -o test3.out testfiles/test3.cpp src/classes_n_funcs.cpp
	./test3.out

clean:
ifeq ($(OS),Windows_NT)
	del /F /Q *.o *.out *.exe
else
	rm -f *.o *.out *.exe
endif

# Phony targets
.PHONY: all clean test1 test2 test3