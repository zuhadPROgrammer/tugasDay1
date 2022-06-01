#include <iostream>
#include <conio.h>
#include <time.h>
#include <stdlib.h>
#include "color.hpp"			// import header from the same folder named color
#include <vector>
using namespace std;

#define goUp 72
#define goDown 80
#define goLeft 75
#define goRight 77

void header () {
	string arrowKeyTxt = " ARROW KEYS ";
	cout << "============================\n";
	cout << "|[       WELCOME TO       ]|\n";
	cout << "|[   pokemon unity lite!  ]|\n";
	cout << "|[        by: zuhad       ]|\n";
	cout << "============================\n";
	cout << "how to play? \n";
	cout << "> use" + dye::red(arrowKeyTxt) + "to control the character\n";
	cout << "> your character is " + dye::red("&") + "\n";
	cout << "> press " + dye::red("'esc'") + " to exit\n";
	cout << "> get " + dye::red("8") +" exp to finish the game.\n\n";
}

struct pokemons {
	int pokeId;
	int hp;
	string name;
	string type;
	string skill[3];
	int damage[3];
};

int main() {
    int panjangPeta = 20; // x
    int lebarPeta = 16; // y
	int exp=0;

    int map[lebarPeta][panjangPeta] = {							// 1 = ground (stepped v)
        {11,12,13,8,8,8,8,8,1,1,1,6,6,6,6,1,1,8,3,3},				// 2 = bush (stepped v)
        {2,2,1,1,1,8,8,1,1,1,6,6,6,6,6,6,1,1,3,3},				// 3 = pond (stepped v)
        {2,1,1,1,1,1,8,1,1,1,6,6,6,6,6,6,1,1,1,3},				// 8 = stone (stepped x)
        {2,1,1,1,1,1,1,1,1,1,1,6,5,5,6,1,1,1,1,2},				// 5 = trunk (stepped x)
        {2,2,2,1,1,1,1,1,1,1,1,1,5,5,1,1,1,1,1,1},				// 6 = leaves (stepped x)
        {2,2,2,2,1,1,1,1,2,2,1,1,5,5,1,1,1,1,1,1},				// 11, 12,= exp txt;
        {2,2,8,8,1,1,1,3,3,3,2,1,1,1,1,1,1,1,1,1},				// 13 = exp display;
        {8,8,1,1,1,1,3,3,3,3,3,1,1,1,1,1,1,1,6,6},
        {1,1,1,1,1,1,3,3,3,3,3,2,1,1,1,1,1,6,6,6},
        {3,3,1,1,1,1,1,3,3,3,2,1,1,1,1,1,6,6,6,6},
        {3,3,3,1,1,1,1,1,2,2,8,8,8,8,1,1,6,6,6,6},
        {3,1,1,1,1,8,8,8,8,8,8,1,1,1,1,1,6,6,5,7},
        {2,2,2,1,1,1,1,1,1,1,1,1,1,1,1,1,1,6,5,7},
        {2,2,8,8,8,8,8,1,1,1,1,1,8,8,8,1,1,1,5,7},
        {2,2,8,8,8,2,1,1,1,1,8,8,8,3,3,1,1,1,5,7},
        {8,8,8,8,2,2,2,1,1,2,2,3,3,3,3,3,1,1,5,7},
    };

	int charPositionY, charPositionX;

	pokemons pokemon[] = {
		{1, 60, "Bulbasaur", "ground", "tackle", "leech seed", "seed bomb", 10, 20, 30},
		{2, 58, "Squirtle", "water", "tail whip", "water gun", "hydro pump", 10, 20, 30},
		{3, 60, "Caterpie", "ground", "tackle", "string shot", "bug bite", 10, 15, 25},
		{4, 50, "Ekans", "ground", "leer", "acid spray", "belch", 10, 25, 40},
		{5, 70, "Psyduck", "water", "scrach", "confusion", "aqua tail", 10, 20, 35},
		{6, 80, "Pikachu", "mine", "thunder shock", "spark", "thunder bolt", 15, 30, 40}
	};

	header();

	charPositionX=9;															// spawn position
	charPositionY=2;
	cout << "you spawn at (" << (charPositionX+1) << "," << (charPositionY+1) << ") coordinate";

	int userMove;
	do {
		cout << "\npress your arrow to move: ";
		userMove = (getch());													// input user's move

		if (userMove==goUp && map[charPositionY-1][charPositionX]<4) {			// move up
			charPositionY-=1;
			charPositionY < 0 ? charPositionY = 0 : charPositionY;
		}
		else if (userMove== goDown && map[charPositionY+1][charPositionX]<4) {		// move down
			charPositionY+=1;
			charPositionY > 15 ? charPositionY = 15 : charPositionY;
		}
		else if (userMove==goLeft && map[charPositionY][charPositionX-1]<4) {		// move left
			charPositionX-=1;
			charPositionX < 0 ? charPositionX = 0 : charPositionX;
		}
		else if (userMove==goRight && map[charPositionY][charPositionX+1]<4) {		// move right
			charPositionX+=1;
			charPositionX > 19 ? charPositionX = 19 : charPositionX;
		}
		else if (userMove==27) {
			cout << "\n\nthanks for playing this game!\n\n";
			exit(0);
		}

		cout << "\n";
		int charCoordinate=map[charPositionY][charPositionX];
		system("CLS");
		for (int i=0; i<lebarPeta; i++) {										//render grafik
			for (int j=0; j<panjangPeta; j++) {
				if (charPositionX==j && charPositionY==i && charCoordinate<4) {
					cout << dye::colorize("& ", "red");
				} else if (map[i][j]==1) {
					cout << dye::colorize ("_ ", "grey");
				} else if (map[i][j]==2) {
					cout << dye::colorize ("m ", "light_green");
				} else if (map[i][j]==3) {
					cout << dye::colorize ("~ ", "aqua");
				} else if (map[i][j]==8) {
					cout << dye::colorize ("G ", "light_grey");
				} else if (map[i][j]==5) {
					cout << dye::colorize ("| ", "purple");
				} else if (map[i][j]==6) {
					cout << dye::colorize ("O ", "yellow");
				} else if (map[i][j]==7) {
					cout << ("  ");
				} else if (map[i][j]==11) {
					cout << dye::red("Ex");
				} else if (map[i][j]==12) {
					cout << dye::red("p:");
				} else if (map[i][j]==13) {
					cout << dye::red(exp) << " ";
				}
			}
			cout << "\n";
		}

		if (charCoordinate==2 || charCoordinate==3) {							// generate random number
		int probPokemon;
		srand (time(NULL));
		probPokemon = rand() % 10;

		if (probPokemon<3) {							// if number < 3, pokemon found!
			char fightOrRun;
			cout << "\n\nyou found pokemon!\n";
			cout << "what will you do?\n1) fight\n2) run\n";
			cout << "decision: ";
			cin >> fightOrRun;							// get input from user without enter
			system("CLS");

			if (fightOrRun=='1') {
				for (int i=0; i<5; i++) {
					probPokemon++;
					if (probPokemon==10) {
						probPokemon==0;
					}
					if (charCoordinate==2) {
						if (pokemon[probPokemon].type=="ground") {
							cout << "\n\nyou will fight " << pokemon[probPokemon].name << endl;
							break;
						}
					} else if (charCoordinate==3) {
						if (pokemon[probPokemon].type=="water") {
							cout << "\n\nyou will fight " << pokemon[probPokemon].name << endl;
							break;
						}
					}
				}

			cout << "your available pokemon is: " << pokemon[5].name << endl;

			int hpUserPokemon, hpRandomPokemon;
			hpUserPokemon = pokemon[5].hp;
			hpRandomPokemon = pokemon[probPokemon].hp;

				while (hpRandomPokemon>0) {
					cout << endl << dye::yellow(pokemon[5].name) << "   vs   " << dye::blue(pokemon[probPokemon].name) << endl;
					cout << "hp: " << hpUserPokemon << "         hp: " << hpRandomPokemon << endl;
					cout << "\nskills: \n";
					for (int i=0; i<3; i++) {
						cout << i+1 << ") "<< pokemon[5].skill[i] << endl;
					}

					cout << "choose skill: ";
					int chosenSkill;
					cin >> chosenSkill;
					chosenSkill--;
					system("CLS");
					cout << endl << pokemon[5].name << " is using " << pokemon[5].skill[chosenSkill] << endl;
					cout << pokemon[probPokemon].name <<"'s hp " << dye::red("-") << dye::red(pokemon[5].damage[chosenSkill]) <<endl << endl;
					cout << pokemon[probPokemon].name << " is using " << pokemon[probPokemon].skill[chosenSkill] << endl;
					cout << pokemon[5].name <<"'s hp " << dye::red ("-") << dye::red(pokemon[probPokemon].damage[chosenSkill]) <<endl;
					hpRandomPokemon-=pokemon[5].damage[chosenSkill];
					hpUserPokemon-=pokemon[probPokemon].damage[chosenSkill];
				}

				if (hpRandomPokemon<=0) {
					cout << endl << dye::yellow(pokemon[5].name) << "   vs   " << dye::blue(pokemon[probPokemon].name) << endl;
					if (hpRandomPokemon<0)
						hpRandomPokemon=0;
					cout << "hp: " << hpUserPokemon << "         hp: " << hpRandomPokemon << endl;
					hpRandomPokemon = pokemon[probPokemon].hp;
					cout << endl << pokemon[probPokemon].name << " defeated!\n";
					cout << "gained " + dye::aqua("1") + " exp!\n";
					exp++;
					if (exp==8) {
						string continueOrNot;
						cout << dye::green("\n    congratulation!    \n");
						cout << "you finished the game!\n\n";

						cout << "continue(y/n)? ";
						cin >> continueOrNot;

						if (continueOrNot!="y" && continueOrNot!="Y") {
							cout << "\n\nthanks for playing this game!\n\n";
							exit(0);
						}
					}
				}
			}
		}
	}
	} while (userMove!=27);
}