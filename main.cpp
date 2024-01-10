#include "PokemonLeague.hpp"

BEGIN_GAME
CREATE POKEMON{ NAME: "name", TYPE: "type", HP: 1245}
CREATE POKEMONS [ POKEMON{ NAME: "Pikachu", TYPE: "Fire", HP: 35}, POKEMON{  NAME: "hi", TYPE: "Fire", HP: 35} , POKEMON{  NAME: "hello", TYPE: "Water", HP: 35}];
CREATE ABILITY{
    NAME : "Expelliarmus",
    ACTION : START
            IF GET_HP(ATTACKER) < 30 DO 
            HEAL ATTACKER 25 
            ELSE 
            HEAL ATTACKER 15 
            END
        END
}
//CREATE ABILITY{ NAME: "rawr"};

DUEL
SHOW GET_HP(ATTACKER)
END_GAME