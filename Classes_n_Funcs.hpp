#include <iostream>
#include <vector>
#include <string>

class Pokemon;
class Ability;
class Pokemons;
class Abilities;
class Round;
class Damage;
class Heal;
class Equip;

std::vector<Pokemon *> pokemons;
std::vector<Ability *> abilities;
std::vector<Pokemon *> pokemonsInGame;


Pokemon *searchPokemon(Pokemon *x){
    for (auto& p : pokemons) {
            if (p == x) {
                return p;
            }
        }
    return nullptr; // Return nullptr if Pokemon is not found
}


class Pokemon
{
private:
    std::string name;
    std::string type;
    int healthPoints;
    int maxHealthPoints;

public:
    Pokemon(){};
    ~Pokemon(){};

    Pokemon(std::string name, std::string type, int healthPoints)
        : name(name), type(type), healthPoints(healthPoints) {
            this->maxHealthPoints = healthPoints;
            pokemons.push_back(this);
        }

    void print()
    {
        std::cout << "Name: " << name << std::endl;
        std::cout << "Type: " << type << std::endl;
        std::cout << "Health Points: " << healthPoints << std::endl;
    }

    std::string getType(){
        return type;
    }

    std::string getName(){
        return name;
    }

    int getMaxHealthPoints(){
        return maxHealthPoints;
    }

    void receiveDamage(int damage){
        healthPoints -= damage;
        if(healthPoints < 0){
            healthPoints = 0;
        }
    }

    void heal(int heal){
        healthPoints += heal;
        if (healthPoints > maxHealthPoints) {
                healthPoints = maxHealthPoints;
        } 
    }
};


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
    
class Ability
{
private:
    std::string name;
public:
    Ability(){};
    ~Ability(){};

    Ability(std::string name)
        : name(name) {
            abilities.push_back(this);
        }

    void print()
    {
        std::cout << "Name: " << name << std::endl;
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


class Round{
    private:
        int round=0;
        int AttackerIndex = 0;
        int DefenderIndex = 1;
    public:
        Round(){};
        ~Round(){};

        void Switch(){
            int temp = AttackerIndex;
            AttackerIndex = DefenderIndex;
            DefenderIndex = temp;
        }

        void nextRound(){
            round++;
        }

        int getAttackerIndex(){
            return AttackerIndex;
        }

        int getDefenderIndex(){
            return DefenderIndex;
        }

        int getRound(){
            return round;
        }
};

Round *game = new Round;

class Damage{
    private:
        int damage;
        Pokemon defender;
    public:
        Damage(){};
        ~Damage(){};

        void setDamage(int damage){
            this->damage = damage;
        }

        int getDamage(){
            return damage;
        }

        int operator+(int damage){
            //Pokemon *attacker = Players.at(game->getAttackerIndex());
            //do_damage(defender,attacker,damage);
            return 0;
        }

        void do_damage(Pokemon defender, Pokemon *attacker, int damage){
            float damageMultiplier = 1.0f;

        if (attacker->getType() == "Electric") {
            if (defender.getType() == "Fire") {
                damageMultiplier -= 0.30f;
            } else if (defender.getType() != "Electric") {
                damageMultiplier -= 0.20f;
            }
        } else if (attacker->getType() == "Fire") {
            if (defender.getType() == "Electric") {
                damageMultiplier += 0.20f;
            } else if (defender.getType() != "Fire") {
                damageMultiplier += 0.15f;
            }
        } else if (attacker->getType() == "Water") {
            damageMultiplier += 0.07f;
            attacker->receiveDamage(static_cast<int>(getDamage() *(-0.07f)));
        } else if (attacker->getType() == "Grass") {
            bool isSunny = check();
            if (isSunny) {
                damageMultiplier += 0.07f;
            } else {
                attacker->heal(static_cast<int>(attacker->getMaxHealthPoints() * 0.05f));
            }
        }

        int finalDamage = static_cast<int>(getDamage() * damageMultiplier);
        defender.receiveDamage(finalDamage);
    }

        bool check(){
            if(game->getRound() % 3 == 0){ //perritos 
                return true;
            }else{ //artios
                return false;
            }
        }

};

class Heal{
    private:
        int heal;
        Pokemon pokemon;
    public:
        Heal(){};
        ~Heal(){};

        void setHeal(int heal){
            this->heal = heal;
        }

        int getHeal(){
            return heal;
        }

        int operator+(int heal){
            pokemon.heal(getHeal());
            return 0;
        }


};

class Equip{
    private: Pokemon *pokemon;
    public:
        Equip(){}
        ~Equip(){}
        Equip(Pokemon *pokemon){
            this->pokemon = pokemon;
        }

};