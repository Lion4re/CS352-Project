/**
 * @file    classes_n_funcs.cpp
 * @author  Davanos Ioannis (4622) Papageridis Vasileios (4710)
 * 
 * @brief   Implementation of the classes and functions
 * @date    13-01-2024
 * 
 * @see     Compile using supplied Makefile by running: make
 *
 * @copyright Copyright (c) 2024
 * 
 */
#include "PokemonLeague.hpp"

std::vector<void (*)()> actions;
std::vector<Pokemon *> pokemons;
std::vector<Ability *> abilities;
std::vector<Pokemon *> pokemonsInGame;
int AbilityToLearn[1];

Heal heal;
Damage damage;
Take pokeball;
Actions *effects = new Actions();
LastMacroUsed last_macro_used = NONE;


Round::Round(){};
Round::~Round(){};

void Round::Switch()
{
    int temp = AttackerIndex;
    AttackerIndex = DefenderIndex;
    DefenderIndex = temp;
}

void Round::nextRound()
{
    Switch();
    round++;
}

int Round::getAttackerIndex()
{
    return AttackerIndex;
}

int Round::getDefenderIndex()
{
    return DefenderIndex;
}

int Round::getRound()
{
    return round;
}

Round *game = new Round();


Ability::Ability(){};
Ability::~Ability(){};

Ability::Ability(std::string name, void (*action)())
    : name(name), action(action)
{

    if (hasSpaces(name))
    {
        throw std::invalid_argument("Ability with name: " + name + " has spaces in it");
    }

    abilities.push_back(this);
}

Ability::Ability(std::string name)
{
    count++;
    this->name = "--ABILITY_WITH_NO_NAME--" + std::to_string(count);
    abilities.push_back(this);
};

void Ability::get_action()
{
    return action();
}

bool Ability::hasSpaces(const std::string &str)
{
    return str.find(' ') != std::string::npos;
}

std::string Ability::getAbilityName()
{
    return name;
}

void Ability::printer()
{
    std::cout << "Ability name: " << name << "\n" << std::endl;
}

Ability *Ability::operator,(Ability *ability_){}

std::ostream &operator<<(std::ostream &os, Ability *ability_temp)
{
    os << ability_temp->getAbilityName();
    return os;
}

int Ability::count = 0;



Pokemon::Pokemon(){};
Pokemon::~Pokemon(){};

Pokemon::Pokemon(std::string name, std::string type, int healthPoints)
    : name(name), type(type), healthPoints(healthPoints), maxHealthPoints(healthPoints), inPokeball(1)
{
    if (searchPokemonName(name) != nullptr)
    {
        throw std::invalid_argument("Pokemon with name: " + name + " is duplicate");
    }
    pokemons.push_back(this);
}

void Pokemon::print()
{
    std::cout << "\n\n############################" << std::endl;
    std::cout << "Name: " << name << std::endl;
    std::cout << "Health Points: " << healthPoints << std::endl;
    std::cout << (inPokeball == 1 ? "Pokemon out of Pokeball" : "Pokemon in Pokeball") << std::endl;
    std::cout << "############################\n"
                << std::endl;
}

int Pokemon::getInPokeball()
{
    return inPokeball;
}

void Pokemon::setInPokeball(int inPokeball)
{
    this->inPokeball = inPokeball;
}

void Pokemon::printName()
{
    std::cout << name << std::endl;
}

std::string Pokemon::getType()
{
    return type;
}

std::string Pokemon::getName()
{
    return name;
}

int Pokemon::getHealth()
{
    return healthPoints;
}

int Pokemon::getMaxHealthPoints()
{
    return maxHealthPoints;
}

std::vector<Ability *> Pokemon::getAbilities()
{
    return abilities;
}

void Pokemon::receiveDamage(int damage)
{
    healthPoints = std::max(healthPoints - damage, 0);
}

void Pokemon::heal(int heal)
{
    healthPoints = std::min(healthPoints + heal, maxHealthPoints);
#ifdef DEBUG
    std::cout << "Heal: " << heal << std::endl;
#endif
}

void Pokemon::update()
{
    if (this->getType() == "Grass" && !check())
    {
#ifdef DEBUG
        std::cout << "Grass Type: Heal 5% of max health points" << std::endl;
#endif
        this->heal(static_cast<int>(this->getMaxHealthPoints() * 0.05f));
    }

    for (auto &action : this->pokemonactions)
    {
        if (action->actions.empty() == false)
        {
            (*(action->actions.front()))();
            action->actions.erase(action->actions.begin());
        }
    }
}

bool Pokemon::isAlive()
{
    return healthPoints > 0;
}

int Pokemon::addAbility(Ability *ability)
{
    abilities.push_back(ability);
    return 0;
}

std::vector<Actions *> Pokemon::getActions()
{
    return pokemonactions;
}

Pokemon *Pokemon::operator,(Pokemon *pokemon_)
{
    return pokemon_;
}

Pokemon *learner = new Pokemon;



Pokemons::Pokemons() { arr[0] = new Pokemon; }
Pokemons::~Pokemons() {}
Pokemon *Pokemons::operator[](Pokemon *index)
{
    return arr[0];
}



Abilities::Abilities() { arr[0] = new Ability; }
Abilities::~Abilities() {}
Ability *Abilities::operator[](Ability *index)
{
    return arr[0];
}



Damage::Damage(){};
Damage::~Damage(){};

Damage::Damage(Pokemon *pokemon)
{
    this->pokemon = pokemon;
}

void Damage::setDamage(int damage)
{
    this->damage = damage;
}

int Damage::getDamage()
{
    return damage;
}

int Damage::operator,(int damage)
{
    setDamage(damage);
    do_damage(pokemon);
    return 0;
}

void Damage::do_damage(Pokemon *defender)
{
    float damage = getDamage();
    Pokemon *attacker = pokemonsInGame.at(game->getAttackerIndex());
#ifdef DEBUG
    std::cout << "type of attacker is " << attacker->getType() << "and the name is" << attacker->getName() << std::endl;
    std::cout << "---------------------------------------------------------------------------------------------------------" << std::endl;
    std::cout << "type of defender is " << defender->getType() << "and the name is" << defender->getName() << std::endl;
#endif

    float increasedDamage = 0;
    float reducedDamage = 0;

    if (defender->getType() == "Electric")
    {
        if (attacker->getType() == "Fire")
        {
            reducedDamage = damage * 0.30f;
#ifdef DEBUG
            std::cout << "Fire vs Electric: Damage reduced by " << reducedDamage << std::endl;
#endif
        }
        else if (attacker->getType() != "Fire")
        {
            reducedDamage = damage * 0.20f;
#ifdef DEBUG
            std::cout << "Non-Fire vs Electric: Damage reduced by " << reducedDamage << std::endl;
#endif
        }
    }
    if (attacker->getType() == "Fire")
    {
        if (defender->getType() == "Electric")
        {
            increasedDamage = damage * 0.20f;
#ifdef DEBUG
            std::cout << "Fire vs Electric: Damage increased by " << increasedDamage << std::endl;
#endif
        }
        else if (defender->getType() != "Electric")
        {
            increasedDamage = damage * 0.15f;
#ifdef DEBUG
            std::cout << "Fire vs Non-Electric: Damage increased by " << increasedDamage << std::endl;
#endif
        }
    }
    if (attacker->getType() == "Water")
    {
        increasedDamage = damage * 0.07f;
#ifdef DEBUG
        std::cout << "Water Type: Damage increased by " << increasedDamage << std::endl;
#endif
    }
    if (attacker->getType() == "Grass")
    {
        if (check())
        {
            increasedDamage = damage * 0.07f;
#ifdef DEBUG
            std::cout << "Grass Type with Check: Damage increased by " << increasedDamage << std::endl;
#endif
        }
    }

    if (defender->getType() == "Water")
    {
        reducedDamage = damage * 0.07f;
#ifdef DEBUG
        std::cout << "Defender Water Type: Damage reduced by " << reducedDamage << std::endl;
#endif
    }
#ifdef DEBUG
    std::cout << "Damage: " << getDamage() << std::endl;
#endif
    damage = damage + increasedDamage - reducedDamage;
#ifdef DEBUG
    std::cout << "Final damage: " << damage << std::endl;
#endif
    defender->receiveDamage(damage);

    increasedDamage = 0;
    reducedDamage = 0;
}



bool check()
{
    if (game->getRound() % 2 == 1)
    { // perritos
        return true;
    }
    else
    { // artios
        return false;
    }
}



Heal::Heal(){};
Heal::~Heal(){};

Heal::Heal(Pokemon *pokemon)
{
    this->pokemon = pokemon;
};

void Heal::setHeal(int heal)
{
    this->heal = heal;
}

int Heal::getHeal()
{
    return heal;
}

int Heal::operator,(int heal)
{
    setHeal(heal);
    pokemon->heal(getHeal());
    return 0;
}



Pokeball::Pokeball() {}
Pokeball::~Pokeball() {}
Pokeball::Pokeball(int val) : pokeball_value(val) {}

int Pokeball::getPokeballValue()
{
    return pokeball_value;
}

void Pokeball::setPokeballValue(int val)
{
    pokeball_value = val;
}

Pokeball *Pokeball::operator--()
{
    return this;
}

Pokeball Pokeball::operator-() const
{
    Pokeball a(1);
    return a;
}

Pokeball a;
Pokeball _(2);



Take::Take(){};
Take::~Take(){};
Take::Take(Pokemon *pokemon)
{
    this->pokemon = pokemon;
}

Pokeball *Take::operator,(Pokeball *pokeball)
{ // ---a
    pokemon->setInPokeball(pokeball->getPokeballValue() == 1);
    return pokeball;
}

Pokeball Take::operator,(Pokeball pokeball)
{ // -a
    pokemon->setInPokeball(pokeball.getPokeballValue() == 1);
    return pokeball;
}


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

Pokemon *searchPokemon(Pokemon *x, int t)
{
    return x;
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

void printPokemons()
{
    for (auto &p : pokemons)
    {
        p->printName();
    }
}

void printAbilities(Pokemon *pokemon)
{
    if (pokemon == nullptr)
    {
        throw std::runtime_error("Pokemon is nullptr");
    }

    std::cout << "Pokemon name: " << pokemon->getName() << std::endl;

    const auto &abilities = pokemon->getAbilities();
    if (abilities.empty())
    {
        throw std::runtime_error("You have no abilities");
    }

    for (const auto &a : abilities)
    {
        a->printer();
    }
}

void select_pokemons()
{
    std::string name;

    for (int player = 1; player <= 2; player++)
    {
        do
        {
            std::cout << "\nPlayer" << player << " select pokemon:" << std::endl;
            std::cout << "-----------------------" << std::endl;
            printPokemons();
            std::cout << "-----------------------" << std::endl;
            std::getline(std::cin, name);
        } while (searchPokemonName(name) == nullptr);

        pokemonsInGame.push_back(new Pokemon(*searchPokemonName(name)));
    }
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
    for (int i = 0; i < num && result; i++)
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
    for (int i = 0; i < num && !result; i++)
    {
        result = result || va_arg(valist, int);
    }
    va_end(valist);
    return result;
}

void select_ability(Pokemon *pokemon, Ability *ability)
{
    std::string abilty_name;
    std::cout << "-----------------------" << std::endl;
    if(pokemon->getAbilities().empty())
    {
        std::string errorMessage = pokemon->getName() + " has no abilities";
        throw std::runtime_error(errorMessage);
    }
    for (const auto &ability : pokemon->getAbilities())
    {
        std::cout << ability->getAbilityName() << std::endl;
    }
    std::cout << "-----------------------" << std::endl;

    std::getline(std::cin, abilty_name);

    while (searchAbilityName(pokemon, abilty_name) == nullptr)
    {
        std::getline(std::cin, abilty_name);
    }

    ability = searchAbilityName(pokemon, abilty_name);
    ability->get_action();
};

int pokemon_to_learn(Pokemon *pokemon, std::string ability_)
{
    if (pokemon != nullptr)
    {
        for (const auto &ability : abilities)
        {
            if (ability->getAbilityName() == ability_)
            {
                pokemon->addAbility(ability);
#ifdef DEBUG
                std::cout << ability->getAbilityName() << std::endl;
#endif
                return 0;
            }
        }
    }
    else
    {
        return 1;
    }
    return 0;
}

void duel()
{
    std::cout << "------------------------------ POKEMON THE GAME ------------------------------" << std::endl;

    select_pokemons();
#ifdef DEBUG
    std::cout << "pokemon in game size is " << pokemons.size() << std::endl;
#endif
    Pokemon *Pokemon1 = pokemonsInGame.at(0);
    Pokemon *Pokemon2 = pokemonsInGame.at(1);
    Ability *ability;
    while (Pokemon1->isAlive() && Pokemon2->isAlive())
    {
        std::cout << "\n\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n"
                  << "Round: " << game->getRound() << "\n"
                  << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n";
#ifdef DEBUG
        std::cout << "Attacker: " << pokemonsInGame.at(game->getAttackerIndex()) << std::endl;
        std::cout << "Defender: " << pokemonsInGame.at(game->getDefenderIndex()) << std::endl;
#endif
        if (Pokemon1->getInPokeball() == 1)
        {
            std::cout << Pokemon1->getName() << "(Player1) select ability:" << std::endl;
            select_ability(Pokemon1, ability);
            Pokemon1->print();
            Pokemon2->print();
        }
        else
        {
            std::cout << Pokemon1->getName() << "(Player1) has not a pokemon out of pokeball so he can't cast an ability." << std::endl;
        }

        Pokemon1->update();
        game->Switch();
        std::cout << "\n\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << std::endl;
#ifdef DEBUG
        std::cout << "Attacker: " << pokemonsInGame.at(game->getAttackerIndex()) << std::endl;
        std::cout << "Defender: " << pokemonsInGame.at(game->getDefenderIndex()) << std::endl;
#endif

        if (Pokemon2->isAlive())
        {
            if (Pokemon2->getInPokeball() == 1)
            {
                std::cout << Pokemon2->getName() << "(Player2) select ability:" << std::endl;
                select_ability(Pokemon2, ability);
                Pokemon1->print();
                Pokemon2->print();
            }
            else
            {
                std::cout << Pokemon2->getName() << "(Player2) has not a pokemon out of pokeball so he can't cast an ability." << std::endl;
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
    std::cout << "\n\n Do you want to play again? (y/n)" << std::endl;
    std::string answer;
    std::getline(std::cin, answer);
    if (answer == "y" || answer == "Y" || answer == "yes" || answer == "YES" || answer == "Yes")
    {
        pokemonsInGame.clear();
        game = new Round();
        duel();
    }
    else
    {
        std::cout << "Goodbye!" << std::endl;
        std::cout << "\n-------------------------POKEMON_THE_GAME-------------------------" << std::endl;
        std::cout <<  "------------------------------THE_END-------------------------" << std::endl;
        std::cout << "Credits to Davanos Ioannis and Papageridis Vasileios\n\n" << std::endl;
    }
}