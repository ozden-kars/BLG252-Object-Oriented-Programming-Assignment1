//--- 2023-2024 Spring BLG 252E Object Oriented Programing Assignment 1 ---//
//--------------------------//
//---Name & Surname:
//---Student Number:
//--------------------------//

#ifndef _H
#define _H

//-------------Do Not Add New Libraries-------------//
//-------------All Libraries Needed Were Given-------------//
#include <iostream>
#include <stdio.h>
#include <string.h>

using namespace std;

//-------------Do Not Add Any New Class(es)-------------//
//int POKEMON_HP = 100;

class pokemon{
    //-------------Do Not Change Given Variables-------------//
    //-------------You Can Add New Variables If Neccessary-------------//
    private:
        string name;
        int hpValue;
        int atkValue;
    public:
        friend class player;
        pokemon();
        pokemon(string, int, int);
        pokemon(const pokemon&);
        string get_name(){return this->name;};
        int get_hpValue(){return this->hpValue;};
        int get_atkValue(){return this->atkValue;};
        void set_hpValue(int hpvalue) {this->hpValue = hpvalue; };
};

class pokedex{
    //-------------Do Not Change Given Variables-------------//
    //-------------You Can Add New Variables If Neccessary-------------//
    private:
        pokemon pokedexArray[100];
        int value;
    public:
        pokedex(){value = 0;};
        int get_value();
        pokemon* get_pokeArray(); 
        bool updatePokedex(pokemon& newPokemon); // true if it is updated
        void printPokedex();
};

class player{
    private:
    //-------------Do Not Change Given Variables-------------//
    //-------------You Can Add New Variables If Neccessary-------------//
        string name;
        int pokemonNumber;
        int pokeballNumber;
        int badgeNumber;
        pokemon playerPokemon;
    public:
        pokedex playerPokedex;
        player();
        player(string name, pokemon& playerpokemon);
        int showPokemonNumber();
        int showPokeballNumber();
        int showBadgeNumber();
        pokemon& getPokemon();
        void battleWon();
        void catchPokemon(); 
        
};

class enemy{
    //-------------Do Not Change Given Variables-------------//
    //-------------You Can Add New Variables If Neccessary-------------//
    private:
        string name;
        pokemon enemyPokemon;
    public:
        enemy();
        enemy(const string& name_v, pokemon& pokemon_v);
        pokemon& getPokemon();
        string getName();
        
};

#endif