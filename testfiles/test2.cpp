#include "../src/PokemonLeague.hpp"
BEGIN_GAME
CREATE ABILITIES[
    ABILITY{NAME : "Electric_Shock",
            ACTION : START IF GET_HP(ATTACKER) < 30 DO
                                                     HEAL ATTACKER 25 ELSE HEAL
                                                         ATTACKER 15 END
                                                             END},
    ABILITY{NAME : "Blaze", ACTION : START DAMAGE DEFENDER 22 END}]
    CREATE ABILITY { NAME: "Lightning_Rod", ACTION: START IF GET_HP(ATTACKER) < 30 DO HEAL ATTACKER 25 ELSE HEAL ATTACKER 15 END END }
CREATE ABILITY { NAME: "Solar_Power", ACTION: START POKEBALL ATTACKER ---a DAMAGE DEFENDER 20 END }

CREATE POKEMON { NAME: "Pikachu", TYPE: "Electric", HP: 120 }
CREATE POKEMON { NAME: "Squirtle", TYPE: "Water", HP: 100 }
CREATE POKEMONS [ POKEMON{ NAME: "Ho Oh", TYPE: "Fire", HP: 120 }, POKEMON{ NAME: "Bulbasaur", TYPE: "Grass", HP: 85 } ]

DEAR "Pikachu" LEARN [ ABILITY_NAME(Electric_Shock) ABILITY_NAME(Lightning_Rod) ]
DEAR "Ho Oh" LEARN [ ABILITY_NAME(Electric_Shock) ABILITY_NAME(Blaze) ABILITY_NAME(Lightning_Rod) ABILITY_NAME(Drought) ]
DEAR "Squirtle" LEARN [ ABILITY_NAME(Electric_Shock) ABILITY_NAME(Solar_Power) ABILITY_NAME(Lightning_Rod) ]

DUEL
END_GAME