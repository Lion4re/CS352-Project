/**
 * @file    PokemonLeague.hpp
 * @author  Davanos Ioannis (4622) Papageridis Vasileios (4710)
 *
 * @brief   Header file containing the macros used in the project
 * @date    13-01-2024
 *
 * @see     Compile using supplied Makefile by running: make
 *
 * @copyright Copyright (c) 2024
 *
 */
#pragma once
#include "Classes_n_Funcs.hpp"
extern Heal heal;
extern Damage damage;
extern Take pokeball;
extern Actions *effects;

enum LastMacroUsed
{
    NONE,
    FOR_MACRO,
    AFTER_MACRO
};
extern LastMacroUsed last_macro_used;

#define BEGIN_GAME              \
    int main()                  \
    {                           \
        Pokemon *temp_pokemon;  \
        Ability *temp_ability;  \
        Pokemons temp_pokemons; \
        Abilities temp_abilities;

#define END_GAME \
    ;            \
    return 0;    \
    }

#define CREATE ;
#define POKEMON temp_pokemon = new Pokemon
#define POKEMONS temp_pokemons
#define ABILITY temp_ability = new Ability
#define ABILITIES temp_abilities
#define NAME name
#define TYPE type
#define HP healthPoints

#define GET_NAME(pokemon) searchPokemon(pokemon 0)->getName()
#define GET_TYPE(pokemon) searchPokemon(pokemon 1)->getType()
#define GET_HP(pokemon) searchPokemon(pokemon 2)->getHealth()
#define IS_IN_POKEBALL(pokemon) searchPokemon(pokemon 3)->getInPokeball()

#define POKEBALL pokeball =
#define ATTACKER pokemonsInGame.at(game->getAttackerIndex()),
#define DEFENDER pokemonsInGame.at(game->getDefenderIndex()),

#define DAMAGE \
    ;          \
    damage =

#define HEAL \
    ;        \
    heal =

#define START []() {
#define AND(...) and_(countArgs(__VA_ARGS__), __VA_ARGS__)
#define OR(...) or_(countArgs(__VA_ARGS__), __VA_ARGS__)
#define NOT(x) not_(x)

#define END \
    ;       \
    }

#define ACTION action

#define IF if(

#define ELSE_IF \
    ;           \
    } else if(

#define ELSE \
    ;        \
    }        \
    else     \
    {

#define DO ) \
    {

#define FOR                                                                         \
    ;                                                                               \
    last_macro_used = FOR_MACRO;                                                    \
    effects = new Actions();                                                        \
    pokemonsInGame.at(game->getAttackerIndex())->pokemonactions.push_back(effects); \
    for(int i = 0; i <

#define ROUNDS                                                                                                \
    ;                                                                                                         \
        i++)                                                                                                  \
    {                                                                                                         \
        auto actionToPush = (last_macro_used != AFTER_MACRO) ? &(effects->action) : &(effects->empty_action); \
        effects->actions.push_back(actionToPush);                                                             \
    }                                                                                                         \
    effects->actions.pop_back();                                                                              \
    effects->actions.push_back(&(effects->action));                                                           \
    last_macro_used = NONE;                                                                                   \
    effects->action = [](

#define AFTER                                                                       \
    ;                                                                               \
    last_macro_used = AFTER_MACRO;                                                  \
    effects = new Actions();                                                        \
    pokemonsInGame.at(game->getAttackerIndex())->pokemonactions.push_back(effects); \
    for(int i = 0; i <=

#define SHOW               \
    ;                      \
    std::cout << std::endl <<

#define DEAR \
    ; learner = searchPokemonName(

#define LEARN ); \
    AbilityToLearn

#define ABILITY_NAME(ability_name) +pokemon_to_learn(learner, #ability_name)

#define DUEL \
    ;        \
    duel();
