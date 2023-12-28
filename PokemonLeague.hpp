#include <iostream>
#include <vector>
#include <string>

#define BEGIN_GAME     \
    int main()         \
    {                  \
        Pokemon *temp; \
        Pokemons temp_pokemons; \
        Ability *tempa; \
        Abilities temp_abilities; \

#define END_GAME \
    ;            \
    return 0;    \
    }
#define CREATE ;
#define POKEMON temp = new Pokemon
#define POKEMONS temp_pokemons
#define ABILITY tempa =  new Ability
#define ABILITIES temp_abilities
#define NAME name
#define TYPE type
#define HP healthPoints

class Pokemon
{
private:
    std::string name;
    std::string type;
    int healthPoints;

public:
    Pokemon(){};
    ~Pokemon(){};

    Pokemon(std::string name, std::string type, int healthPoints)
        : name(name), type(type), healthPoints(healthPoints) {}

    void print()
    {
        std::cout << "Name: " << name << std::endl;
        std::cout << "Type: " << type << std::endl;
        std::cout << "Health Points: " << healthPoints << std::endl;
    }
};



class Pokemons
{
public:
private:
    Pokemon *arr[1];

public:
    Pokemons() { arr[0] = new Pokemon; }
    ~Pokemons() {}
    Pokemon *operator[](Pokemon *index)
    {
        return arr[0];
    }
};


class Ability
{
private:
    std::string name;
};

class Abilities
{};
