all: build run

build:
	@echo "Building hello.cpp.."
	g++ -std=c++17 -Wall main.cpp Classes_n_Funcs.hpp -o game.out
run:
	./game.out
testc:
	@echo "Building test.c"
	gcc -Wall main.cpp -o main.out

clean:
	@echo "Cleaning executables.."
	*.out
	
ssh_kiwi:
	ssh kiwi.csd.uoc.gr