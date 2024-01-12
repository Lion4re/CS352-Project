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
class Equip;
class Pokeball;
class Take;
Pokemon *searchPokemonName(std::string name);
Ability *searchAbilityName(std::string name);

typedef void (*Action)();
std::vector<Action *> actions;
std::vector<Pokemon *> pokemons;
std::vector<Ability *> abilities;
std::vector<Pokemon *>pokemonsInGame;
int AbilityToLearn[1];

class Round
{
private:
    int round = 0;
    int AttackerIndex = 0;
    int DefenderIndex = 1;

public:
    Round(){};
    ~Round(){};

    void Switch()
    {
        int temp = AttackerIndex;
        AttackerIndex = DefenderIndex;
        DefenderIndex = temp;
    }

    void nextRound()
    {
        Switch();
        round++;
    }

    int getAttackerIndex()
    {
        return AttackerIndex;
    }

    int getDefenderIndex()
    {
        return DefenderIndex;
    }

    int getRound()
    {
        return round;
    }
};
Round *game = new Round();

class Actions
{
public:
    std::vector<void (*)()> actions;
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
    Ability(){};
    ~Ability(){};

    Ability(std::string name, void (*action)())
        : name(name), action(action)
    {

        if (hasSpaces(name))
        {
            throw std::invalid_argument("Ability with name: " + name + " has spaces in it");
        }

        abilities.push_back(this);
    }

    Ability(std::string name)
    {
        count++;
        this->name = "--ABILITY_WITH_NO_NAME--" + std::to_string(count);
        abilities.push_back(this);
    };
    

    void get_action()
    {
        return action();
    }

    bool hasSpaces(const std::string &str)
    {
        return str.find(' ') != std::string::npos;
    }

    std::string getAbilityName()
    {
        return name;
    }

    void printer()
    {
        std::cout << "Ability name: " << name << "\n" << std::endl;
    }

    Ability *operator,(Ability *ability_);
};

std::ostream &operator<<(std::ostream &os, Ability *ability_temp) {
    os << ability_temp->getAbilityName();
    return os;
}



int Ability::count = 0;

class Pokemon
{
private:
    std::string name;
    std::string type;
    int healthPoints;
    int maxHealthPoints;
    int inPokeball; // 0 = not in pokeball, 1 = in pokeball
    std::vector<Ability *> abilities;
    

public:
    std::vector<Actions *> pokemonactions;
    Pokemon(){};
    ~Pokemon(){};

    Pokemon(std::string name, std::string type, int healthPoints)
        : name(name), type(type), healthPoints(healthPoints)
    {
        if (searchPokemonName(name) != nullptr)
        {
            throw std::invalid_argument("Pokemon with name: " + name + " is duplicate");
        }

        this->maxHealthPoints = healthPoints;
        this->inPokeball = 0;
        pokemons.push_back(this);
    }

    // Pokemon(Pokemon *pokemon)
    //     : name(pokemon->getName()), type(pokemon->getType()), healthPoints(pokemon->getHealth())
    // {
    //     this->maxHealthPoints = healthPoints;
    //     this->inPokeball = 0;
    // }

    void print()
    {
        std::cout << "Name: " << name << std::endl;
        std::cout << "Health Points: " << healthPoints << std::endl;
        if (inPokeball == 0)
        {
            std::cout << "Pokemon out of Pokeball" << std::endl;
        }
        else
        {
            std::cout << "Pokemon in Pokeball" << std::endl;
        }
    }

    int getInPokeball()
    {
        return inPokeball;
    }

    void setInPokeball(int inPokeball)
    {
        this->inPokeball = inPokeball;
    }

    void printName()
    {
        std::cout << name << std::endl;
    }

    std::string getType()
    {
        return type;
    }

    std::string getName()
    {
        return name;
    }

    int getHealth()
    {
        return healthPoints;
    }

    int getMaxHealthPoints()
    {
        return maxHealthPoints;
    }

    std::vector<Ability *> getAbilities()
    {
        return abilities;
    }

    void receiveDamage(int damage)
    {
        healthPoints -= damage;
        if (healthPoints < 0)
        {
            healthPoints = 0;
        }
    }

    void heal(int heal)
    {
        healthPoints += heal;
        if (healthPoints > maxHealthPoints)
        {
            healthPoints = maxHealthPoints;
        }
    }

    bool check()
    {
        if (game->getRound() % 3 == 0)
        { // perritos
            return true;
        }
        else
        { // artios
            return false;
        }
    }

    void update()
    {
        if (this->getType() == "Grass" && !check())
        {
            this->heal(static_cast<int>(this->getMaxHealthPoints() * 0.05f));
        }

        for (unsigned i = 0; i < this->pokemonactions.size(); i++)
        {
            if ((pokemonactions[i]->actions.empty()) != false)
            {
                (*(pokemonactions[i]->actions.front()))();
                pokemonactions[i]->actions.erase(pokemonactions[i]->actions.begin() + 0);
            }
        }
    }

    bool isAlive()
    {
        if (healthPoints > 0)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    int addAbility(Ability *ability)
    {
        abilities.push_back(ability);
        return 0;
    }

    std::vector<Actions *> getActions()
    {
        return pokemonactions;
    }


    Pokemon *operator,(Pokemon *pokemon_){
        return pokemon_;
    }
};

Pokemon *learner = new Pokemon;

std::ostream &operator<<(std::ostream &os, Pokemon *pokemon_temp) {
    os << pokemon_temp->getName();
    return os;
}

class Pokemons
{
private:
    Pokemon *arr[1];

public:
    Pokemons() { arr[0] = new Pokemon; }
    ~Pokemons() {}
    Pokemon *operator[](Pokemon *index)
    {
        return arr[0];
    }
};



class Abilities
{
private:
    Ability *arr[1];

public:
    Abilities() { arr[0] = new Ability; }
    ~Abilities() {}
    Ability *operator[](Ability *index)
    {
        return arr[0];
    }
};

class Damage
{
private:
    int damage;
    Pokemon *pokemon;

public:
    Damage(){};
    ~Damage(){};

    Damage(Pokemon *pokemon)
    {
        this->pokemon = pokemon;
    }

    void setDamage(int damage)
    {
        this->damage = damage;
    }

    int getDamage()
    {
        return damage;
    }

    int operator,(int damage)
    {
        Pokemon *attacker = pokemonsInGame.at(game->getAttackerIndex());
        //Pokemon *defender = pokemonsInGame[(game->getDefenderIndex())];
        do_damage(pokemon, attacker, damage);
        return 0;
    }

    void do_damage(Pokemon *defender, Pokemon *attacker, float damage)
    {
        float damageMultiplier = 1.0f;

        if (attacker->getType() == "Electric")
        {
            if (defender->getType() == "Fire")
            {
                damageMultiplier -= 0.30f;
            }
            else if (defender->getType() != "Electric")
            {
                damageMultiplier -= 0.20f;
            }
        }
        else if (attacker->getType() == "Fire")
        {
            if (defender->getType() == "Electric")
            {
                damageMultiplier += 0.20f;
            }
            else if (defender->getType() != "Fire")
            {
                damageMultiplier += 0.15f;
            }
        }
        else if (attacker->getType() == "Water")
        {
            damageMultiplier += 0.07f;
            attacker->receiveDamage(static_cast<int>(getDamage() * (-0.07f)));
        }
        else if (attacker->getType() == "Grass")
        {
            if (check())
            {
                damageMultiplier += 0.07f;
            }
        }

        int finalDamage = static_cast<int>(getDamage() * damageMultiplier);
        defender->receiveDamage(finalDamage);
    }

    bool check()
    {
        if (game->getRound() % 3 == 0)
        { // perritos
            return true;
        }
        else
        { // artios
            return false;
        }
    }
};

class Heal
{
private:
    int heal;
    Pokemon *pokemon;

public:
    Heal(){};
    ~Heal(){};

    Heal(Pokemon *pokemon)
    {
        this->pokemon = pokemon;
    };

    void setHeal(int heal)
    {
        this->heal = heal;
    }

    int getHeal()
    {
        return heal;
    }

    int operator,(int heal)
    {
        pokemon->heal(getHeal());
        return 0;
    }
};

class Pokeball
{
    int pokeball_value;

public:
    Pokeball() {}
    Pokeball(int val) : pokeball_value(val)
    {
    }
    ~Pokeball()
    {
    }

    Pokeball *operator--()
    {
        return this;
    }

    Pokeball operator-() const
    {
        Pokeball a(1);
        return a;
    }

    int getPokeballValue()
    {
        return pokeball_value;
    }
};

Pokeball a;  
Pokeball _(2);

class Take
{
private:
    Pokemon *pokemon;

public:
    Take() {}
    ~Take() {}
    Take(Pokemon *pokemon)
    {
        this->pokemon = pokemon;
    }

    Pokeball *operator,(Pokeball *pokeball)
    { // ---a
        if (pokeball->getPokeballValue() == 1)
        {
            pokemon->setInPokeball(1);
        }
        else
        {
            pokemon->setInPokeball(0);
        }
        return pokeball;
    }
};

Pokemon *searchPokemonName(std::string name)
{
    for (auto &p : pokemons)
    {
        if (p->getName() == name)
        {
            return p;
        }
    }
    return nullptr; // Return nullptr if Pokemon is not found
}

Ability *searchAbilityName(Pokemon *pokemon, std::string name)
{
    for (auto &a : pokemon->getAbilities())
    {
        if (a->getAbilityName() == name)
        {
            return a;
        }
    }
    return nullptr; // Return nullptr if Pokemon is not found
}

Ability *searchAbilityName(std::string name)
{
    for (auto &a : abilities)
    {
        if (a->getAbilityName() == name)
        {
            return a;
        }
    }
    return nullptr; // Return nullptr if Pokemon is not found
}

Pokemon *searchPokemon(Pokemon *x, int t)
{
    return x;
}

void printPokemons()
{
    for (auto &p : pokemons)
    {
        p->printName();
    }
}

void printAbilities(Pokemon *pokemon)
{
    if(pokemon == nullptr)
    {
        throw std::runtime_error("Pokemon is nullptr");
    }else{
        std::cout << "Pokemon name: " << pokemon->getName() << std::endl;
    }
    if (pokemon->getAbilities().empty())
    {
        throw std::runtime_error("You have no abilities");
    }
    for (auto &a : pokemon->getAbilities())
    {
        a->printer();
    }
}

void printPokemonInfo(Pokemon *pokemon)
{
    pokemon->print();
}

void select_pokemons()
{
   char name[40];

    //perimenei input onoma kapoiou wizard apo player 1

    std::cout << "\nPlayer1 select wizard:" << std::endl;
    std::cout << "-----------------------" << std::endl;
    printPokemons();
    std::cout << "-----------------------" << std::endl;
    std::cin.getline(name, sizeof(name));

    while (searchPokemonName(name) == nullptr) {
        std::cout << "\nPlayer1 select pokemon:" << std::endl;
        std::cout << "-----------------------" << std::endl;
        printPokemons();
        std::cout << "-----------------------" << std::endl;
        std::cin.getline(name, sizeof(name));
    }

     pokemonsInGame.push_back(new Pokemon(*searchPokemonName(name)));

    std::cout << "\nPlayer2 select wizard:" << std::endl;
    std::cout << "-----------------------" << std::endl;
    printPokemons();
    std::cout << "-----------------------" << std::endl;
    std::cin.getline(name, sizeof(name));

    while (searchPokemonName(name) == nullptr) {
        std::cout << "\nPlayer2 select pokemon:" << std::endl;
        std::cout << "-----------------------" << std::endl;
        printPokemons();
        std::cout << "-----------------------" << std::endl;
        std::cin.getline(name, sizeof(name));
    }

    pokemonsInGame.push_back(new Pokemon(*searchPokemonName(name)));
    name[0] = '\0';
}

/* Utility functions */

// Function to remove a comma from the end of a string
// Mainly used for removing the comma from the ATTACKER and DEFENDER macros
std::string removeTrailingComma(const std::string &str)
{
    if (!str.empty() && str.back() == ',')
        return str.substr(0, str.size() - 1);

    return str;
}

bool not_(bool x)
{
    return !x;
}

bool and_(int num, ...)
{
    va_list valist;
    va_start(valist, num);
    bool result = true;
    for (int i = 0; i < num; i++)
    {
        result = result && va_arg(valist, int);
    }
    va_end(valist);
    return result;
}

bool or_(int num, ...)
{
    va_list valist;
    va_start(valist, num);
    bool result = false;
    for (int i = 0; i < num; i++)
    {
        result = result || va_arg(valist, int);
    }
    va_end(valist);
    return result;
}

Ability *select_ability(Pokemon *pokemon)
{
   char spell_name[40];
    std::cout << "-----------------------" << std::endl;
    for (unsigned int i = 0; i < pokemon->getAbilities().size(); i++) {
        std::cout << pokemon->getAbilities().at(i)->getAbilityName() << std::endl;
    }
    std::cout << "-----------------------" << std::endl;

    std::cin.getline(spell_name, sizeof(spell_name));

    while (searchAbilityName(pokemon, spell_name) == nullptr) {
        std::cin.getline(spell_name, sizeof(spell_name));
    }

    return searchAbilityName(pokemon, spell_name);
};

int pokemon_to_learn(Pokemon *pokemon,std::string ability_)
{
    if(pokemon != nullptr)
    {
        for (unsigned int i = 0; i < abilities.size(); i++) {
        if (abilities[i]->getAbilityName() ==ability_) {
            pokemon->addAbility(abilities.at(i));
            std::cout << abilities[i]->getAbilityName() << std::endl;
            return 0;
        }
        }
    }else{
        return 1;
    }
    return 0;
}


void duel()
{
    std::cout << "------------------------------ POKEMON THE GAME ------------------------------" << std::endl;

    // for (int i = 0; i < 2; i++)
    // {
    //     select_pokemons(i);
    // }
    select_pokemons();
    //select_pokemons(1);
    std::cout << "pokemon in game size is " << pokemons.size() << std::endl;
    Pokemon *Pokemon1 = pokemonsInGame.at(0);
    Pokemon *Pokemon2 = pokemonsInGame.at(1);
    Ability *ability;
    while (Pokemon1->isAlive() && Pokemon2->isAlive())
    {
        Pokemon1->print();
            Pokemon2->print();
    std::cout << "\n\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << std::endl;
    std::cout << "Round: " << game->getRound() << std::endl;
    std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n" << std::endl;
        if (Pokemon1->getInPokeball() == 0)
        {
            std::cout << Pokemon1->getName() << "(Player1) select ability:" << std::endl;
            ability = select_ability(Pokemon1);
            ability->get_action();
            Pokemon1->print();
            Pokemon2->print();
        }
        else
        {
            std::cout << Pokemon1->getName() << "(Player1) has not a pokemon out of pokeball so he can't cast an ability." << std::endl;
        }

        Pokemon1->update();
        game->Switch();

        if (Pokemon2->isAlive())
        {
            if (Pokemon2->getInPokeball() == 0)
            {
                std::cout << Pokemon2->getName() << "(Player2) select ability:" << std::endl;
                select_ability(Pokemon2);
                Pokemon1->print();
                Pokemon2->print();
            }
            else
            {
                std::cout << Pokemon1->getName() << "(Player2) has not a pokemon out of pokeball so he can't cast an ability." << std::endl;
            }

            Pokemon2->update();
            game->nextRound();
        }
        else
        {
            break;
        }
    }

    std::cout << "\n\n------------------------------ THE DUEL IS OVER ------------------------------" << std::endl;
    std::string Name1 = Pokemon1->getName();
    std::string Name2 = Pokemon2->getName();
    if (Pokemon1->isAlive())
    {

        std::cout << "\n=== RIP -> (Player2)" << Name2 << "\n"
                  << Name1 << "(Player1) Wins!!!" << std::endl;
    }
    else
    {
        std::cout << "\n=== RIP -> (Player1)" << Name1 << "\n"
                  << Name2 << "(Player2) Wins!!!" << std::endl;
    }
}
