#include "PokemonLeague.hpp"
BEGIN_GAME
CREATE ABILITY{
    NAME : "Bite",
    ACTION : START
            // Επιστπέυει το αντίπαλο pokemon στο pokeball
        

                    IF AND ( GET_HP(ATTACKER) > 50, GET_HP(DEFENDER) > 50) DO
                        SHOW "Name: " << GET_NAME(DEFENDER)<< "Type: " << GET_TYPE(DEFENDER)
                    END
            END
}CREATE ABILITY{
    NAME : "Solar",
    ACTION : START
        // Για 5 γύποςρ κάνει 8 damage στον αντίπαλο (DEFENDER)
        FOR 5 ROUNDS DO
            DAMAGE DEFENDER 8 END
                END
} CREATE ABILITY{
    NAME : "Slash",
    ACTION : START
        // Κάνει 22 damage στον αντίπαλο (DEFENDER)
        DAMAGE DEFENDER 22 END
} CREATE ABILITY{
    NAME : "Blaze",
    ACTION : START
        // Κάνει heal στον εαςτό τος (ATTACKER)
        HEAL ATTACKER 30 END
} CREATE POKEMON{
    NAME : "C",
    TYPE : "Fire",
    HP : 100
} CREATE POKEMON{
    NAME : "K",
    TYPE : "Grass",
    HP : 100
}CREATE POKEMON{
    NAME : "P",
    TYPE : "Electric",
    HP : 100
} DEAR "C" LEARN[ABILITY_NAME(Bite) ABILITY_NAME(Solar) ABILITY_NAME(Slash) ABILITY_NAME(Blaze)] DEAR "P" LEARN[ABILITY_NAME(Bite) ABILITY_NAME(Slash)
                                                                                                                                        ABILITY_NAME(Electric_Shock)] 
 DEAR "K" LEARN[ABILITY_NAME(Bite) ABILITY_NAME(Slash) ABILITY_NAME(Solar)
                                                                                                                                        ABILITY_NAME(Electric_Shock)]                                                                                                                                       
                                                                                                                                        DUEL
END_GAME 

