
#include "PokemonLeague.hpp"

BEGIN_GAME
CREATE POKEMON{ NAME: "name", TYPE: "type", HP: 1245}
CREATE POKEMONS [ POKEMON{ NAME: "Pikachu", TYPE: "Fire", HP: 35}, POKEMON{  NAME: "hi", TYPE: "Fire", HP: 35}];
//CREATE ABILITY{ NAME: "rawr"};
std::cout << GET_TYPE(temp_pokemon);
select_pokemons();
END_GAME