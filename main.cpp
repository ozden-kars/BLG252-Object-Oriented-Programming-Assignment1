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
#include <fstream>

#include "pokemon.h"

using namespace std;

//-------------Do Not Change These Global Variables-------------//
int NAME_COUNTER = 0;   //Use this to keep track of the enemy names
int POK_COUNTER = 0;    //Use this to keep track of the pokemon names
int PLAYER_POKEMON_ATTACK = 20; //You don't have to use this variable but its here if you need it
int ENEMY_POKEMON_ATTACK = 10;  //You don't have to use this variable but its here if you need it
//--------------------------------------------------------------//

//---If Necessary Add Your Global Variables Here---// 
// 
//
//
//-------------------------------------------------//

//-------------Do Not Change These Function Definitions-------------//
string* readEnemyNames(const char*);
string* readPokemonNames(const char*);
player characterCreate(string, int);
void mainMenu();
void fightEnemy(player*, string*, string*);
void catchPokemon(player*, string*);
//------------------------------------------------------------------//

//---If Necessary Add Your Function Definitions Here---// 
//
//
//
//-----------------------------------------------------//

//-------------Do Not Change This Function-------------//
int main(int argc, char* argv[]){
	system("clear");

    //---Creating Enemy and Pokemon Name Arrays---//
    string* enemyNames = readEnemyNames(argv[1]);         
    string* pokemonNames = readPokemonNames(argv[2]);

    string playerName;
    int pokemonChoice;

    cout << "Welcome to the Pokemon Game! \n" << endl;
    cout << "Please enter your name: "; 
    cin >> playerName;
    cout << "Please choose one of these pokemons as your pokemon: \n1- Bulbasaur \n2- Charmender \n3- Squirtle \nChoice: ";
    cin >> pokemonChoice;

    //---Character Creation--//
    player newPlayer = characterCreate(playerName, pokemonChoice);
    
    int menuChoice;

    while(true){
        mainMenu(); 
        cin>>menuChoice;

        switch (menuChoice){
        case 1:
            fightEnemy(&newPlayer, enemyNames, pokemonNames);
            break;
        case 2:
            catchPokemon(&newPlayer, pokemonNames);
            break;
        case 3:
            cout<<newPlayer.showPokemonNumber()<<endl;
            break;
        case 4:
            cout<<newPlayer.showPokeballNumber()<<endl;
            break;
        case 5:
            cout<<newPlayer.showBadgeNumber()<<endl;
            break;
        case 6:
            cout << endl;
            cout << "------- Pokedex -------" <<endl;
            newPlayer.playerPokedex.printPokedex();
            break;
        case 7:
            //---Deletes Dynamic Arrays From Memory and Exits---//
            delete[] enemyNames;
            delete[] pokemonNames;
            return EXIT_SUCCESS;
            break;
  
        default:
            cout << "Please enter a valid number!!!" << endl;
            break;
        }
    }
    return EXIT_FAILURE;
};
//-----------------------------------------------------//

//-------------Code This Function-------------//
string* readEnemyNames(const char* argv){
    int size = 0;
    ifstream enemyFile(argv);
    if (!enemyFile.is_open()) {
        cerr << "Error opening file: " << "enemyNames.txt" << endl;
        return NULL;
    }
    enemyFile >> size; 
    std::string* enemyNames = new std::string[size];

    for (int i = 0; i < size; ++i) {
        enemyFile >> enemyNames[i];
    }

    enemyFile.close();
    return enemyNames;
};
//-----------------------------------------------------//

//-------------Code This Function-------------//
string* readPokemonNames(const char* argv){
    int size = 0;
    ifstream pokemonFile(argv);
    if (!pokemonFile.is_open()) {
        cerr << "Error opening file: " << "pokemonNames.txt" << endl;
        return NULL;
    }
    pokemonFile >> size; 
    std::string* pokemonNames = new std::string[size];

    for (int i = 0; i < size; ++i) {
        pokemonFile >> pokemonNames[i];
    }

    pokemonFile.close();
    return pokemonNames;
};
//-----------------------------------------------------//

//-------------Code This Function-------------//
player characterCreate(string playerName, int pokemonChoice){
    string player_pokemon_name[3] = {"Bulbasaur","Charmender", "Squirtle"};
    string pokeomon_name = player_pokemon_name[pokemonChoice-1];
    pokemon new_pokemon{pokeomon_name,20,100}; 
    player new_player{playerName,new_pokemon}; 
    return new_player;
};
//--------------------------------------------//

//-------------Do Not Change This Function-------------//
void mainMenu(){
    std::cout << std::endl;
    std::cout << "-------- Menu --------" << std::endl;
    std::cout << "1. Fight for a badge" << std::endl;
    std::cout << "2. Catch a Pokemon" << std::endl;
    std::cout << "3. Number of Pokemons" << std::endl;
    std::cout << "4. Number of Pokeballs " << std::endl;
    std::cout << "5. Number of Badges" << std::endl;
    std::cout << "6. Pokedex" << std::endl;
    std::cout << "7. Exit" << std::endl;
    std::cout << std::endl;
    std::cout << "Choice: ";
}
//-----------------------------------------------------//

//-------------Code This Function-------------//
void fightEnemy(player* newPlayer, string* enemyNames, string* pokemonNames){
    
    pokemon enemy_pokemon(pokemonNames[POK_COUNTER], 10, 100);
    enemy* new_enemy = new enemy(enemyNames[NAME_COUNTER], enemy_pokemon);
    cout << "You encounter with " << enemyNames[NAME_COUNTER] << " and his/her pokemon " << pokemonNames[POK_COUNTER] << endl;
    cout << pokemonNames[POK_COUNTER] << " Health: 100 Attack: 10\n" << endl;
    cout << "1- Fight\n2- Runaway\nChoice: ";
    int fight_choice;
    cin >> fight_choice;

    while (fight_choice == 1 && newPlayer->getPokemon().get_hpValue() > 0 && new_enemy->getPokemon().get_hpValue() > 0) {
        newPlayer->getPokemon().set_hpValue(newPlayer->getPokemon().get_hpValue() - ENEMY_POKEMON_ATTACK);
        new_enemy->getPokemon().set_hpValue(new_enemy->getPokemon().get_hpValue() - PLAYER_POKEMON_ATTACK);
        cout << "Your Pokemon's Health: " << newPlayer->getPokemon().get_hpValue() << endl;
        cout << enemyNames[NAME_COUNTER] << " Pokemon's Health: " << new_enemy->getPokemon().get_hpValue() << "\n" << endl;
        cout << "1- Fight\n2- Runaway\nChoice: ";
        cin >> fight_choice;
        if (newPlayer->getPokemon().get_hpValue() > new_enemy->getPokemon().get_hpValue() && ( new_enemy->getPokemon().get_hpValue()  <= 0)) {
        cout << "You Won!\n";
        newPlayer->battleWon();
        newPlayer->playerPokedex.updatePokedex(enemy_pokemon);
        }
        else if (newPlayer->getPokemon().get_hpValue()<  new_enemy->getPokemon().get_hpValue()  && (newPlayer->getPokemon().get_hpValue() <= 0)) {
            cout << "You Lost:(\n";
            newPlayer->playerPokedex.updatePokedex(enemy_pokemon);
        }
    }
    if(fight_choice == 2){
        cout << "Your Pokemon's Health: " << newPlayer->getPokemon().get_hpValue() << endl;
        cout << enemyNames[NAME_COUNTER] << " Pokemon's Health: " << new_enemy->getPokemon().get_hpValue() << "\n" << endl;
        cout << "You Runaway\n";
        newPlayer->playerPokedex.updatePokedex(enemy_pokemon);
    }

    POK_COUNTER++;
    NAME_COUNTER++;
    delete new_enemy;
};
//--------------------------------------------//

//-------------Code This Function-------------//
void catchPokemon(player* newPlayer, string* pokemonNames){
    int catch_choice;
    pokemon new_pokemon {pokemonNames[POK_COUNTER],10,100};
    cout <<"You encounter with " << new_pokemon.get_name() <<" Health: " << new_pokemon.get_hpValue() << " Attack: " << new_pokemon.get_atkValue() <<"\n\n";
    cout << "1- Catch\n2- Runaway\nChoice: ";
    cin >> catch_choice;
    if(catch_choice == 1){
        cout << "You catch " << new_pokemon.get_name() <<"\n";
        newPlayer->playerPokedex.updatePokedex(new_pokemon);
        
    } else{
        cout << "You runaway\n\n"; 
    }
    POK_COUNTER++;

};
//--------------------------------------------//
