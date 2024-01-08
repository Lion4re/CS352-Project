#include "Classes_n_Funcs.hpp"
#pragma once


#define BEGIN_GAME     \
    int main()         \
    {                  \
    Pokemon *temp_pokemon;     \
    Ability *temp_ability;    \
    Pokemons temp_pokemons; \
    Abilities temp_abilities; \

        
#define END_GAME \
    ;            \
    return 0;    \
    }
#define CREATE ;
#define POKEMON temp_pokemon = new Pokemon
#define POKEMONS temp_pokemons
#define ABILITY temp_ability =  new Ability
#define ABILITIES temp_abilities
#define NAME name
#define TYPE type
#define HP healthPoints


#define GET_NAME(pokemon) searchPokemon(pokemon)->getName();
#define GET_TYPE(pokemon) searchPokemon(pokemon)->type
#define GET_HP(pokemon) searchPokemon(pokemon)->healthPoints


#define IS_IN_POKEBALL(pokemon) 
#define POKEBALL
#define ATTACKER +
#define DEFENDER +
#define DAMAGE ; damage = 
#define HEAL ; heal =
#define START {
#define END }
#define ACTION
#define IF
#define ELSE_IF
#define ELSE
#define DO
#define FOR
#define ROUNDS
#define AFTER
#define SHOW
#define DEAR
#define LEARN
#define ABILITY_NAME(ability_name)
#define DUEL

