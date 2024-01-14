# Pokemon Duel Game

Domain-Specific Language (DSL) Project for the course CS-352: Software Engineering, University of Crete, Department of Computer Science, 2023-2024. <br>
This project is a Pokémon battle simulator, where the player can choose a team of Pokémon and battle against the Pokémon League.<br>
The game is written in C++14 (version 201402) and the text-editor used is Visual Studio Code.

## Team Members
- Davanos Ioannis (4622)
- Papageridis Vasilis (4710)

## Project Description
The Pokémon Battle Simulation project is focused on developing a specialized domain-specific language (DSL) for simulating Pokémon battles, as inspired by the popular animated series. This new language is designed to compile into C++, leveraging header files to translate its unique syntax into valid C++ code. The language itself is whitespace-agnostic, much like C++, and programs in this DSL begin with a `BEGIN_GAME` declaration and conclude with `END_GAME`.<br>
Key features include the ability to define individual Pokémon with attributes like name, type, and health points (HP), and the creation of Pokémon abilities through commands such as DAMAGE, HEAL, and POKEBALL. Additionally, the language accommodates various control structures like IF, ELSE_IF, and FOR loops.<br>
Pokémon types, including Electric, Fire, Water, and Grass, play a crucial role in determining battle dynamics, influencing resistance and vulnerabilities in combat. The battle simulation is conducted through console commands, where the outcome hinges on the HP of the Pokémon, ending when one side loses all its HP.<br>
The project uniquely integrates C++ capabilities, such as operator overloading and temporary instances, to effectively execute the DSL's syntax. A detailed example within the document illustrates a complete Pokémon battle scenario, showcasing the language's functionality and the expected simulation output.<br>
More details can be found in the provided PDF : [DSL_Pokemon_Description.pdf].

## File Structure
The project consists of several files, each serving a specific role in the game's development:

- `main.cpp`: The main driver code that initializes and runs the game.
- `classes_n_funcs.cpp`: Contains the implementations of various classes and functions used in the game.
- `Classes_n_Funcs.hpp`: The header file for classes_n_funcs.cpp, declaring all the classes and functions.
- `PokemonLeague.hpp`: A header file that defines the Pokémon League and its associated elements.
- `test1.cpp`, `test2.cpp`, `test3.cpp`: These files contain the test cases for the game, ensuring that different aspects of the game logic are working as intended.
- `Makefile`: A file used for compiling the project, providing an efficient way to manage the build process.

## Prerequisites

Make sure you have a C++14 compiler and `make` installed on your system.

## How to Run the Game

1. Open a terminal in the project directory.
2. Run `make` to compile the game.
3. Run `./pokemon_battle` to start the game.

## How to Run the Tests

This project includes three tests. You can run them with the following commands:

1. `make test1` to run the first test.
2. `make test2` to run the second test.
3. `make test3` to run the third test.

After running a test, you can use `make clean` to remove the test executable and clean up the project directory.

Enjoy the game!