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
#define pokemonStat 83
#define pokemonStat2 115

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
	int chosenSkill;
	int goldContained;
	
	void battleMechanism (pokemons *enemy) {
		int hpEnemy = enemy->hp;
		int userSkill = chosenSkill;
		cout << endl << name << " attack " << enemy->name << " using " << skill[userSkill] << "\n";
		enemy->hp -= damage[userSkill];
		if (enemy->hp <= 0)
			enemy->hp = 0;
		cout << enemy->name << "'s hp drop from " << dye::yellow(hpEnemy) << " to " << dye::red(enemy->hp)<< "\n";
		cout << endl;
	}
};

int main() {
    int panjangPeta = 20; // x
    int lebarPeta = 16; // y
	int exp=0;

    int map[lebarPeta][panjangPeta] = {							// 1 = ground (stepped v)
        {11,12,13,8,8,8,8,8,1,1,30,21,21,21,28,1,1,8,3,3},		// 2 = bush (stepped v)
        {2,2,1,1,1,8,8,1,1,1,29,21,21,22,23,1,1,1,3,3},			// 3 = pond (stepped v)
        {2,1,1,1,1,1,8,1,1,1,23,25,25,23,23,1,1,1,1,3},			// 8 = stone (stepped x)
        {2,1,1,1,1,1,1,1,1,1,24,26,21,27,1,1,1,1,1,2},   		// 5 = trunk (stepped x)
        {2,2,2,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},				// 6 = leaves (stepped x)
        {2,2,2,2,1,1,1,1,2,2,1,1,1,1,1,1,1,1,1,1},				// 11, 12,= exp txt;
        {2,2,8,8,1,1,1,3,3,3,2,1,1,1,-99,1,1,1,1,1},				// 13 = exp display;
        {8,8,1,1,1,1,3,3,3,3,3,1,1,1,1,1,1,1,6,6},              // 21 = top roof
        {1,1,1,1,1,1,3,3,3,3,3,2,1,1,1,1,1,6,6,6},              // 22 = bottom corner roof
        {3,3,1,1,1,1,1,3,3,3,2,1,1,1,1,1,6,6,6,6},              // 23 = wall1 (| )
        {3,3,3,1,1,1,1,1,2,2,8,8,8,8,1,1,6,6,6,6},              // 24 = wall2 (|_)
        {3,1,1,1,1,8,8,8,8,8,8,1,1,1,1,1,6,6,5,7},              // 25 = window
        {2,2,2,1,1,1,1,1,1,1,1,1,1,1,1,1,1,6,5,7},              // 26 = pintu (H_)
        {2,2,8,8,8,8,8,1,1,1,1,1,8,8,8,1,1,1,5,7},              // 27 = wall3 (|/)
        {2,2,8,8,8,2,1,1,1,1,8,8,8,3,3,1,1,1,5,7},              // 28 = top corner roof
        {8,8,8,8,2,2,2,1,1,2,2,3,3,3,3,3,1,1,5,7},              // 29 = bottom right roof
    };

	int charPositionY, charPositionX;

	pokemons pokemon[] = {
		{1, 60, "Bulbasaur", "ground", "tackle", "leech seed", "seed bomb", 10, 20, 30, 4},
		{2, 58, "Squirtle", "water", "tail whip", "water gun", "hydro pump", 10, 20, 30, 4},
		{3, 60, "Caterpie", "ground", "tackle", "string shot", "bug bite", 10, 15, 25, 4},
		{4, 50, "Ekans", "ground", "leer", "acid spray", "belch", 10, 25, 40, 3},
		{5, 70, "Psyduck", "water", "scrach", "confusion", "aqua tail", 10, 20, 35, 5},
		{6, 80, "Pikachu", "electric", "thunder shock", "spark", "thunder bolt", 15, 30, 40}
	};

	header();

	charPositionX=11;															// spawn position
	charPositionY=4;
	cout << "you spawn right in front of ur house!\n";

	int userMove;
	do {
		cout << "\npress your arrow to move: ";
		userMove = (getch());													// input user's move

		if (userMove==goUp && map[charPositionY-1][charPositionX]<4) {			// move up
			charPositionY-=1;
			charPositionY < 0 ? charPositionY = 0 : charPositionY;
		}
		if (userMove== goDown && map[charPositionY+1][charPositionX]<4) {		// move down
			charPositionY+=1;
			charPositionY > 15 ? charPositionY = 15 : charPositionY;
		}
		if (userMove==goLeft && map[charPositionY][charPositionX-1]<4) {		// move left
			charPositionX-=1;
			charPositionX < 0 ? charPositionX = 0 : charPositionX;
		}
		if (userMove==goRight && map[charPositionY][charPositionX+1]<4) {		// move right
			charPositionX+=1;
			charPositionX > 19 ? charPositionX = 19 : charPositionX;
		}
		if (userMove==27) {
			cout << "\n\nthanks for playing this game!\n\n";
			exit(0);
		}
		if (userMove==83 || userMove==115) {
			cout << "\nPikachu's Stats: \n";
			cout << "hp: " << pokemon[5].hp << "\n";
			cout << "type: " << pokemon[5].type << "\n";
			cout << "level: " << "1" << "\n";
			getch();
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
				} else if (map[i][j]==21) {
					cout << "__";              	// roof
				} else if (map[i][j]==22) {
					cout << "_/";                // corner roof
				} else if (map[i][j]==23) {
					cout << "| ";                // wall1
				} else if (map[i][j]==24) {
					cout << "|_";                // wall2
				} else if (map[i][j]==25) {
					cout << "= ";                // window
				} else if (map[i][j]==26) {
					cout << "H_";                // door
				} else if (map[i][j]==27) {
					cout << "|/";                // wall3
				} else if (map[i][j]==28) {
					cout << ". ";                // top right roof
				} else if (map[i][j]==29) {
					cout << "/_";                // bottom right roof
				} else if (map[i][j]==30) {
					cout << " _";		         // top left roof
				} else if (map[i][j]==-99) {
					cout << dye::blue("&") << " ";  // doctor
				}
			}
			cout << "\n";
		}

		if (charCoordinate==-99) {
			cout << "hallo \n";
		}

		if (charCoordinate==2 || charCoordinate==3) {							// generate random number
		int probPokemon;
		srand (time(NULL));
		probPokemon = rand() % 15;

		cout << endl << probPokemon << endl;
		if (probPokemon<5) {							// if number < 3, pokemon found!
			char fightOrRun;
			system("CLS");
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

//new battle mechanism
			int hpProbPokemon = pokemon[probPokemon].hp;
			for (int i=0; pokemon[probPokemon].hp>=0 && i==0;) {
				cout << "skills: \n";
				for (int i=0; i<3; i++) {                               //print users pokemon skills
					cout << i+1 << ") "<< pokemon[5].skill[i] << endl;
				}
				cout << "choose skill: ";
				cin >> pokemon[5].chosenSkill;
				pokemon[5].chosenSkill--;
				pokemon[probPokemon].chosenSkill = pokemon[5].chosenSkill;

				pokemon[5].battleMechanism(&pokemon[probPokemon]);
				pokemon[probPokemon].battleMechanism(&pokemon[5]);
				
				if (pokemon[probPokemon].hp<=0 || pokemon[5].hp<=0) {
					i++;
				}
			}
			if (pokemon[probPokemon].hp<=0) {
				pokemon[probPokemon].hp = hpProbPokemon;
				exp++;
				cout << "you gained " << dye::blue("1") << " exp!\n";
			}

//finished the game
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
//			else if (fightOrRun=='2') {
//				continue;
//				}
//		}
	}
	} while (userMove!=27);
}
