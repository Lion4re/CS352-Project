/**
 * @file    Classes_n_Funcs.hpp
 * @author  Davanos Ioannis (4622) Papageridis Vasileios (4710)
 * 
 * @brief   Header file for the Classes and Functions used in the project
 * @date    13-01-2024
 * 
 * @see     Compile using supplied Makefile by running: make
 *
 * @copyright Copyright (c) 2024
 * 
 */
#ifndef CLASSES_N_FUNCS_HPP
#define CLASSES_N_FUNCS_HPP

#include <iostream>
#include <vector>
#include <string>
#include <stdarg.h>
#include <algorithm>
#include <cstdlib>
#include <iterator>
#include <cstddef>

template <typename... Args>
constexpr std::size_t countArgs(Args... args)
{
    return sizeof...(args);
}

class Pokemon;
class Ability;
class Pokemons;
class Abilities;
class Round;
class Damage;
class Heal;
class Pokeball;
class Take;

Pokemon *searchPokemonName(std::string name);
extern std::vector<void (*)()> actions;
extern std::vector<Pokemon *> pokemons;
extern std::vector<Ability *> abilities;
extern std::vector<Pokemon *> pokemonsInGame;
extern int AbilityToLearn[1];
bool check();

class Round
{
private:
    int round = 1;
    int AttackerIndex = 0;
    int DefenderIndex = 1;

public:
    Round();
    ~Round();

    void Switch();
    void nextRound();
    int getAttackerIndex();
    int getDefenderIndex();
    int getRound();
};

extern Round *game;

class Actions
{
public:
    std::vector<void (**)()> actions;
    void (*action)();
    void (*empty_action)() = []() {};
    Actions() {}
    ~Actions() {}
};

class Ability
{
private:
    std::string name;
    void (*action)();
    static int count;

public:
    Ability();
    ~Ability();
    Ability(std::string name, void (*action)());
    Ability(std::string name);

    void get_action();
    bool hasSpaces(const std::string &str);
    std::string getAbilityName();
    void printer();
    Ability *operator,(Ability *ability_);
};

std::ostream &operator<<(std::ostream &os, Ability *ability_temp);

// extern int Ability::count;

class Pokemon
{
private:
    std::string name;
    std::string type;
    int healthPoints;
    int maxHealthPoints;
    int inPokeball; // 0 = in pokeball, 1 = not in pokeball
    std::vector<Ability *> abilities;

public:
    std::vector<Actions *> pokemonactions;
    Pokemon();
    ~Pokemon();

    Pokemon(std::string name, std::string type, int healthPoints);
    void print();
    int getInPokeball();
    void setInPokeball(int inPokeball);
    void printName();
    std::string getType();
    std::string getName();
    int getHealth();
    int getMaxHealthPoints();
    std::vector<Ability *> getAbilities();
    void receiveDamage(int damage);
    void heal(int heal);
    void update();
    bool isAlive();
    int addAbility(Ability *ability);
    std::vector<Actions *> getActions();
    Pokemon *operator,(Pokemon *pokemon_);
};

extern Pokemon *learner;

class Pokemons
{
private:
    Pokemon *arr[1];

public:
    Pokemons();
    ~Pokemons();
    Pokemon *operator[](Pokemon *index);
};

class Abilities
{
private:
    Ability *arr[1];

public:
    Abilities();
    ~Abilities();
    Ability *operator[](Ability *index);
};

class Damage
{
private:
    int damage;
    Pokemon *pokemon;

public:
    Damage();
    ~Damage();
    
    Damage(Pokemon *pokemon);
    void setDamage(int damage);
    int getDamage();
    int operator,(int damage);
    void do_damage(Pokemon *defender);
};

bool check();

class Heal
{
private:
    int heal;
    Pokemon *pokemon;

public:
    Heal();
    ~Heal();

    Heal(Pokemon *pokemon);
    void setHeal(int heal);
    int getHeal();
    int operator,(int heal);
};

class Pokeball
{
    int pokeball_value;

public:
    Pokeball();
    ~Pokeball();
    Pokeball(int val);

    int getPokeballValue();
    void setPokeballValue(int val);
    Pokeball *operator--();
    Pokeball operator-() const;
};

extern Pokeball a;
extern Pokeball _;

class Take
{
private:
    Pokemon *pokemon;

public:
    Take();
    ~Take();
    Take(Pokemon *pokemon);

    Pokeball *operator,(Pokeball *pokeball);
    Pokeball operator,(Pokeball pokeball);
};

Pokemon *searchPokemonName(std::string name);
Pokemon *searchPokemon(Pokemon *x, int t);

Ability *searchAbilityName(Pokemon *pokemon, std::string name);


void printPokemons();
void printAbilities(Pokemon *pokemon);
void select_pokemons();

bool not_(bool x);
bool and_(int num, ...);
bool or_(int num, ...);

void select_ability(Pokemon *pokemon, Ability *ability);

int pokemon_to_learn(Pokemon *pokemon, std::string ability_);

void duel();

#endif