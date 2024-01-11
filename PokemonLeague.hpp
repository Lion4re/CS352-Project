#include "Classes_n_Funcs.hpp"
#pragma once
Heal heal;
Damage damage;
Actions *class_action = new Actions();

enum LastMacroUsed { NONE, FOR_MACRO, AFTER_MACRO };
LastMacroUsed last_macro_used = NONE;


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


#define GET_NAME(pokemon) searchPokemon(pokemon 0)->getName()
#define GET_TYPE(pokemon) searchPokemon(pokemon 1)->getType()
#define GET_HP(pokemon) searchPokemon(pokemon 2)->getHealth()
#define IS_IN_POKEBALL(pokemon) searchPokemon(pokemon 3)->getInPokeball()



#define POKEBALL pokeball = 
#define ATTACKER pokemonsInGame[game->getAttackerIndex()],
#define DEFENDER pokemonsInGame[game->getDefenderIndex()],
#define DAMAGE ; damage = 
#define HEAL ; heal =
#define START []() {
#define AND(...) and_(countArgs(__VA_ARGS__), __VA_ARGS__)
#define OR(...) or_(countArgs(__VA_ARGS__), __VA_ARGS__)
#define NOT(x) not_(x)   


#define END ; }


#define ACTION action


#define IF if(
#define ELSE_IF ;} else if(
#define ELSE ;} else {
#define DO ){


#define FOR ; \
    last_macro_used = FOR_MACRO; \
    class_action = new Action(); \
    std::string attackerWithoutComma = removeTrailingComma(ATTACKER); \
    pokemonsInGame[std::stoi(attackerWithoutComma)].actions.push_back(class_action); \
    for(int = 0; i < 

#define ROUNDS ; i++) { \
    if(last_macro_used == AFTER_MACRO){ \
        class_action->actions.push_back(&(class_action->empty_action)); \
    } \
    else(last_macro_used == FOR_MACRO){ \
        class_action->actions.push_back(&(class_action->action)); \
    } \
    last_macro_used = NONE; \
    class_action->action = []( 

#define AFTER ; \
    last_macro_used = AFTER_MACRO; \
    class_action = new Action(); \
    std::string attackerWithoutComma = removeTrailingComma(ATTACKER); \
    pokemonsInGame[std::stoi(attackerWithoutComma)].actions.push_back(class_action); \
    for(int = 0; i <


#define SHOW ; std::cout << std::endl <<
#define DEAR ; learner = searchPokemonName(


#define LEARN ); AbilityToLearn 


#define ABILITY_NAME(ability_name) +learner->addAbility(searchAbilityName(#ability_name))


#define DUEL ; duel();

