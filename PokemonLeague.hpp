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


#define GET_NAME(pokemon) searchPokemon(pokemon 0)->getName();
#define GET_TYPE(pokemon) searchPokemon(pokemon 1)->getType();
#define GET_HP(pokemon) searchPokemon(pokemon 2)->getHealth();
#define IS_IN_POKEBALL(pokemon) searchPokemon(pokemon 3)->getInPokeball();



#define POKEBALL
#define ATTACKER pokemonsInGame[game->getAttackerIndex()],
#define DEFENDER pokemonsInGame[game->getDefenderIndex()],
#define DAMAGE ; damage = 
#define HEAL ; heal =
#define START []() {
#define END ; }


#define ACTION


#define IF if(
#define ELSE_IF ;} else if(
#define ELSE ;} else {
#define DO {


#define FOR
#define ROUNDS
#define AFTER
#define SHOW ; std::cout << std::endl <<
#define DEAR
#define LEARN ; pokemon_learn = find_wizard(


#define ABILITY_NAME(ability_name)


#define DUEL ; duel();

