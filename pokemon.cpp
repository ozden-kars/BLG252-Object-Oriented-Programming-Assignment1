//--- 2023-2024 Spring BLG 252E Object Oriented Programing Assignment 1 ---//
//--------------------------//
//---Name & Surname: Özden KARS
//---Student Number: 150220733
//--------------------------//

//-------------Do Not Add New Libraries-------------//
//-------------All Libraries Needed Were Given-------------//
#include <iostream>
#include <stdio.h>
#include <string.h>

#include "pokemon.h"

using namespace std;

//-------------You Can Add Your Functions Down Below-------------//

pokemon::pokemon(){
    name = "noname";
    hpValue = 100;
    atkValue = 20;
}

pokemon::pokemon(string name, int atkvalue, int hpvalue){
    this->name = name;
    this->hpValue = hpvalue;
    this->atkValue = atkvalue;
}

pokemon::pokemon(const pokemon& original):name{original.name},hpValue{original.hpValue},atkValue{original.atkValue}{};

bool pokedex::updatePokedex(pokemon& newPokemon){
    if (value == 0){
        pokedexArray[0] = newPokemon;
        value++;
        return true;
        
    } else {
        int i;
        for(i = 0; i < value; i++){
            if(pokedexArray[i].get_name() == newPokemon.get_name()){
                return false;
            }
        }
        pokedexArray[value] = newPokemon;
        value++;
        return true;
    }
}



void pokedex::printPokedex(){
    for(int i = 0; i < value;i++){
        std::cout << pokedexArray[i].get_name() << endl;
    }
}

int pokedex::get_value(){return this->value;};

pokemon* pokedex::get_pokeArray(){return this->pokedexArray;}; 

player::player() {
    this->name ="noname";
    this->pokemonNumber = 0;
    this->pokeballNumber = 10;
    this->badgeNumber = 0;
    pokemon playerpokemon;
    this->playerPokemon = playerpokemon;
}

player::player(string name_v, pokemon& playerpokemon) : name(name_v),  pokemonNumber(0), pokeballNumber(10), badgeNumber(0), playerPokemon(playerpokemon){}

int player::showPokemonNumber() {
    return this->pokemonNumber;
}

int player::showPokeballNumber(){return this->pokeballNumber;};

int player::showBadgeNumber(){return this->badgeNumber;};

pokemon& player::getPokemon(){return this->playerPokemon;}; // most important function

void player::battleWon(){
    badgeNumber++;
    pokeballNumber += 3;
    pokeballNumber++;
}

void player::catchPokemon(){
    pokemonNumber++;
    pokeballNumber--;
    pokemonNumber++; 
}

enemy::enemy(){
    pokemon enemy_pokemon;
    this->name ="noname";
    this->enemyPokemon = enemy_pokemon;
}

enemy::enemy(const string& name_v, pokemon& pokemon_v): name{name_v},enemyPokemon{pokemon_v}{}

string enemy::getName(){return this->name;};

pokemon& enemy::getPokemon(){return this->enemyPokemon;}; // most important function
