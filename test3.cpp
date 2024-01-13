#include "PokemonLeague.hpp"
BEGIN_GAME
CREATE ABILITY{
    NAME : "Bite",
    ACTION : START
        IF AND(GET_HP(DEFENDER) > 30, GET_HP(DEFENDER) < 70) DO DAMAGE DEFENDER 20 END
            END
} CREATE ABILITY{
    NAME : "Solar",
    ACTION : START
            // Για 5 γύποςρ κάνει 8 damage στον αντίπαλο (DEFENDER)
            IF GET_HP(DEFENDER) <= 20 DO DAMAGE DEFENDER 10 ELSE_IF GET_HP(DEFENDER) <= 50 DO DAMAGE DEFENDER 20 ELSE
                                                                                               DAMAGE DEFENDER 30 END
                                                                                                    END
} CREATE ABILITY{
    NAME : "Slash",
    ACTION : START
                IF GET_HP(ATTACKER) <= 30 DO IF GET_TYPE(ATTACKER) !=
        "Fire" DO HEAL ATTACKER 20 ELSE
            HEAL ATTACKER 30 END
                END
                END
} CREATE ABILITY{
    NAME : "Tough_Claws",
    ACTION : START FOR 5 ROUNDS DO IF AND(GET_HP(DEFENDER) > 10, GET_HP(DEFENDER) < 80) DO DAMAGE DEFENDER 20 END END
        END} 
CREATE ABILITY{
    NAME : "Blaze",
    ACTION : START
                AFTER 2 ROUNDS DO POKEBALL ATTACKER-- -
            a
                SHOW GET_HP(ATTACKER)
                    SHOW "Name: "
        << GET_NAME(DEFENDER) << "Type: " << GET_TYPE(DEFENDER) END END
} CREATE POKEMONS[POKEMON{NAME : "Ho Oh", TYPE : "Fire", HP : 120}, POKEMON{NAME : "Bulbasaur", TYPE : "Grass", HP : 85}]
DEAR "Ho Oh" LEARN[ABILITY_NAME(Bite) ABILITY_NAME(Solar) ABILITY_NAME(Slash) ABILITY_NAME(Blaze)] DEAR "Bulbasaur" LEARN[ABILITY_NAME(Bite) ABILITY_NAME(Slash)
                                                                                                                                         ABILITY_NAME(Solar)] DUEL
    END_GAME