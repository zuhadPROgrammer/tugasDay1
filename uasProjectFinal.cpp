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
#define quit 27
#define pokemonStat 83
#define pokemonStat2 115

int mainMenu(int arrow) {
	int userMenuInput;
	int arrowAt=arrow;
	bool enter = true;
	do {
		system("CLS");
		cout << R"(
 .----------------.  .----------------.  .----------------.
| .--------------. || .--------------. || .--------------. |
| |  _______     | || |  _________   | || |   ______     | |
| | |_   __ \    | || | |  _   _  |  | || |  |_   __ \   | |
| |   | |__) |   | || | |_/ | | \_|  | || |    | |__) |  | |
| |   |  __ /    | || |     | |      | || |    |  ___/   | |
| |  _| |  \ \_  | || |    _| |_     | || |   _| |_      | |
| | |____| |___| | || |   |_____|    | || |  |_____|     | |
| |              | || |              | || |              | |
| |    Rescue    | || |     the      | || |   Princess   | |
| '--------------' || '--------------' || '--------------' |
 '----------------'  '----------------'  '----------------'
	)" << "\n";

		if(arrowAt==1) {
			cout << R"(
	 ____  __     __   _  _      ___
	(  _ \(  )   / _\ ( \/ )    /  _)
	 ) __// (_/\/    \ )  /     ) (_
	(__)  \____/\_/\_/(__/      \___)
)";
		} else {
			cout << R"(
	 ____  __     __   _  _
	(  _ \(  )   / _\ ( \/ )
	 ) __// (_/\/    \ )  /
	(__)  \____/\_/\_/(__/
)";
	}

		if (arrowAt==2) {
			cout << R"(
	 _  _  __  __ _  ____      ___
	/ )( \(  )(  ( \(_  _)    /  _)
	) __ ( )( /    /  )(      ) (_
	\_)(_/(__)\_)__) (__)     \___)
)";
		} else {
			cout << R"(
	 _  _  __  __ _  ____
	/ )( \(  )(  ( \(_  _)
	) __ ( )( /    /  )(
	\_)(_/(__)\_)__) (__)
)";
	}
	
		if (arrowAt==3) {
	 		cout << R"(
	 ____  _  _  __  ____      ___
	(  __)( \/ )(  )(_  _)    /  _)
	 ) _)  )  (  )(   )(      ) (_
	(____)(_/\_)(__) (__)     \___)
)";
		} else {
			cout << R"(
	 ____  _  _  __  ____
	(  __)( \/ )(  )(_  _)
	 ) _)  )  (  )(   )(
	(____)(_/\_)(__) (__)
)";
		}

		userMenuInput = (getch());
		switch(userMenuInput) {
			case 80:
				arrowAt++;
				break;
			case 72:
				arrowAt--;
				break;
			case 13://224
				enter = false;
				break;
			default:
				break;
		}
		if (arrowAt>3) {
			arrowAt=3;
		} else if (arrowAt<1) {
			arrowAt=1;
		}
	}
	while (enter == true);
	return arrowAt;
}

void header () {
	string arrowKeyTxt = " ARROW KEYS ";
	system("CLS");
	cout << "============================\n";
	cout << "|[       WELCOME TO       ]|\n";
	cout << "|[   rescue the princess  ]|\n";
	cout << "|[        by: zuhad       ]|\n";
	cout << "============================\n";
	
	cout << "how to play? \n";
	cout << "> get the " << dye::red("key castle") << " and rescue the princess to win!\n";
	cout << "> use" + dye::red(arrowKeyTxt) + "to control the character\n";
	cout << "> your character is " + dye::red("&") + "\n";
	cout << "> press " << dye::red("'s'") << " for more information\n";
	cout << "> press " + dye::red("'esc'") + " to exit\n\n";
}

struct pokemons {
	int pokeId;
	int hp;
	string name;
	string type;
	string skill[3];
	int damage[3];
	int chosenSkill;

	void battleMechanism (pokemons *enemy) {
		int hpEnemy = enemy->hp;
		int userSkill = chosenSkill;
		cout << endl << name << " attack " << enemy->name << " using " << skill[userSkill] << "\n";
		enemy->hp -= damage[userSkill];
		if (enemy->hp <= 0)
			enemy->hp = 0;
		cout << enemy->name << "'s hp drop from " << dye::yellow(hpEnemy) << " to " << dye::red(enemy->hp)<< "\n";
		cout << endl;
		Sleep(1000);
	}
};

// monster declaration
pokemons pokemon[] = {
	{1, 60, "Bulbul", "ground", "tackle", "leech seed", "seed bomb", 10, 20, 30, 4},
	{2, 60, "Cici", "ground", "tackle", "string shot", "bug bite", 10, 15, 25, 4},
	{3, 50, "Larlar", "ground", "leer", "acid spray", "belch", 10, 25, 40, 3},
	{4, 58, "Kurkur", "water", "tail whip", "water gun", "hydro pump", 10, 20, 30, 4},
	{5, 70, "Sasa", "water", "scrach", "confusion", "aqua tail", 10, 20, 35, 5},
	{6, 90, "Juhjuh", "electric", "thunder shock", "spark", "thunder bolt", 15, 30, 40, 10}
};

string items[5] = {"orb", "small potion", "large potion", "key", "flower"};
int itemCounter[5] = {0, 0, 0, 0, 0};

void purchasing(int prices, int index, string things) {
	int price = prices;
	int indexThing = index;
	string bought = things;

	if (itemCounter[0] >= price) {
		itemCounter[index]++;
		itemCounter[0] -= price;
		cout << dye::blue(things) << dye::blue(" purchased!\n");
	}
	else {
		cout << dye::blue("sorry, you didn't have enough orbs!\n");
	}
}

int charPositionY=3, charPositionX=8;

void merchant () {
	int buyItem;
	cout << "\n::::::::::::::::::::\n";
	cout << "::   -merchant-   ::\n";
	cout << "::::::::::::::::::::\n";
	cout << "\nhello! wanna buy something?\n";
	cout << " 1. small healing potion (+40 hp)\t[1 orb]\n 2. large healing potion (+80 hp)\t[2 orbs]\n 3. castle key\t\t\t\t[5 orbs]\n\n";
	cout << "type the number to buy (0 for nothing): ";
	cin >> buyItem;
	
	
	
	switch (buyItem) {
		case 1:
			purchasing(1, 1, items[1]);
			break;
		case 2:
			purchasing(2, 2, items[2]);
			break;
		case 3:
			purchasing(5, 3, items[3]);
			break;
		case 0:
//			charPositionY+=1;
			break;
	}
	charPositionY+=1;
}


int backpack() {
	bool empty = true;
	system("CLS");
	cout << "\n::::::::::::::::::::::::\n";
	cout << ":::    -backpack-    :::\n";
	cout << "::::::::::::::::::::::::\n";
	for (int i=0; i<5; i++) {
		if (itemCounter[i]!=0) {
			cout << "- " << items[i] << "   : " << itemCounter[i] << "\n";
			empty = false;
		}
	}
	if (empty == true) {
		cout << "your backpack is empty!\n";
	}
	cout << "\n\ntype anything to back..";
}

void healing (int potionAscii) {
	int userConsuming = potionAscii;

	if (pokemon[5].hp<80) {
		if (userConsuming == 100) {
			if (itemCounter[1] > 0) {
				pokemon[5].hp += 40;
				itemCounter[1]--;
				cout << "consuming small healing potion... \n";
				Sleep(2000);
				cout << dye::green("juhjuh recover 40 hp!\n");
			}
			else {
				cout << "you don't have small potion, go buy some!\n";
			}
		} else if (userConsuming == 68) {
			if (itemCounter[2]>0) {
				pokemon[5].hp += 80;
				itemCounter[2]--;
				cout << "consuming large healing potion... \n";
				Sleep(2000);
				cout << dye::green("juhjuh recover 80 hp!\n");
			}
			else {
				cout << "you don't have large potion, go buy some!\n";
			}
		}
		if (pokemon[5].hp > 80) {
			pokemon[5].hp = 80;
		}
	}
	else {
		cout << "juhjuh is already fully recovered!\n";
	}
}

int door() {
	system("CLS");
	if (itemCounter[3]>0) {
		cout << "\nentering castle, please wait..\n";
		Sleep(5000);
		system("CLS");
		cout << dye::purple("princess is free now, you finished the game!\n");
		cout << "\n\n\ntype something to exit";
		getch();
		exit(0);
	}
	else {
		cout << dye::red("you don't have the key!\n");
		Sleep(1000);
	}
}

void pikachuDead() {
	cout << "pikachu died:(\n";
	cout << "\n\ntype anything to continue..";
	getch();
	getch();
 	system("CLS");
	cout << "\nit means you lose!\n";
	cout << "\n\ntype anything to continue..";
	getch();
	system("CLS");
	cout << "\nyou cant even protect your pet\n";
	cout << "\n\ntype anything to continue..";
	getch();
	system("CLS");
	cout << "\nhow about saving princess?\n";
	cout << "\n\ntype anything to continue..";
	getch();
	system("CLS");
	cout << "\nhow pathetic.";
	Sleep(3000);
}

void infoList() {
	system("CLS");
	cout << "\n:::::::::::::::::::::::::\n";
	cout << ":::   -how to play-   :::\n";
	cout << ":::::::::::::::::::::::::\n";
	cout << "> go to " << dye::green("m") << " or " << dye::aqua("~") << " to find monster\n";
	cout << "> enter the castle to rescue the princess\n";
	cout << "> " << dye::blue("&") << " is a merchant\n";
	cout << "> if your pet die, you lose\n";
	cout << "> press 'Esc' to quit the game\n";
	cout << "> keys shortcut: \n";
	cout << "  [s] open status bar\n";
	cout << "  [b] open backpack\n";
	cout << "  [d] drink small potion\n";
	cout << "  [D] drink large potion\n";
	cout << "\n\ntype anything to go back..";
	getch();
}

int main () {
	int x;
	// variabel declaration
	int panjangPeta = 20; // x
    int lebarPeta = 16; // y
	int exp=0;

	// map matrix
	int map[lebarPeta][panjangPeta] = {							// 1 = ground (stepped v)
   		{11,12,13,8,8,8,8,8,1,1,30,21,21,21,28,1,1,8,3,3},		// 2 = bush (stepped v)
		{14,15,16,1,1,8,8,1,1,1,29,21,21,22,23,1,1,1,3,3},		// 3 = pond (stepped v)
		{2,1,1,1,1,1,8,1,1,1,23,25,25,23,23,1,1,1,1,3},			// 8 = stone (stepped x)
    	{2,1,1,1,1,1,1,1,1,1,24,26,21,27,1,1,1,1,1,2},   		// 5 = trunk (stepped x)
    	{2,2,2,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},				// 6 = leaves (stepped x)
    	{2,2,2,2,1,1,1,1,2,2,1,1,1,1,1,1,1,1,1,1},				// 11, 12,= exp txt;
    	{2,2,8,8,1,1,1,3,3,3,2,1,1,1,-99,1,1,1,1,1},			// 13 = exp display;
    	{8,8,1,1,1,1,3,3,3,3,3,1,1,1,1,1,1,1,6,6},              // 21 = top roof
    	{1,1,1,1,1,1,3,3,3,3,3,2,1,1,1,1,1,6,6,6},              // 22 = bottom corner roof
    	{3,3,1,1,1,1,1,3,3,3,2,1,1,1,1,1,6,6,6,6},              // 23 = wall1 (| )
    	{3,3,3,1,1,1,1,1,2,2,8,8,8,8,1,1,6,6,6,6},              // 24 = wall2 (|_)
    	{3,1,1,1,1,8,8,8,8,8,8,1,1,1,1,1,6,6,5,7},              // 25 = window
    	{2,2,2,1,1,1,1,1,1,1,1,1,1,1,1,1,1,6,5,7},              // 26 = pintu (H_)
    	{2,2,8,8,8,8,8,1,1,1,1,1,8,8,8,1,1,1,5,7},              // 27 = wall3 (|/)
    	{2,2,8,8,8,2,1,1,1,1,8,8,8,3,3,1,1,1,5,7},              // 28 = top corner roof
    	{8,8,8,8,2,2,2,1,1,2,2,3,3,3,3,3,1,1,5,7},              // 29 = bottom right roof
    };                                                          // 14, 15, 16 display hp

    int arrowMenu=1;
    main_menu:;
    int menuChosen = mainMenu(arrowMenu);
    if (menuChosen==3) {
    	exit(0);
	} else if (menuChosen==2) {
		infoList();
		arrowMenu=2;
		goto main_menu;
	} else if (menuChosen==1) {
	    // call and print header
	    header();
	}
    
    int usersMove;
    
//    do {
	while (1) {
    	cout << "\npress your arrow to move: ";
		usersMove= (getch());
		cout << "\n";
		
		if (usersMove==goUp && map[charPositionY-1][charPositionX]<4) {			// move up
			charPositionY-=1;
		}
		if (usersMove== goDown && map[charPositionY+1][charPositionX]<4) {		// move down
			charPositionY+=1;
		}
		if (usersMove==goLeft && map[charPositionY][charPositionX-1]<4) {		// move left
			charPositionX-=1;
		}
		if (usersMove==goRight && map[charPositionY][charPositionX+1]<4) {		// move right
			charPositionX+=1;
		}
		if (usersMove==goUp && map[charPositionY-1][charPositionX]==26) {			// go in
			door();
			Sleep(1000);
		}
		if (usersMove==quit) {
			cout << "\n\nthanks for playing this game!\n\n";
			break;
		}
		if (usersMove==66 || usersMove==98) {
			backpack();
			getch();
		}
		if (usersMove==83 || usersMove==115) {
			infoList();
		}
		if (usersMove==100 || usersMove == 68) {
			healing(usersMove);
			Sleep(1500);
		}
		
		system("CLS");

		int charCoordinate=map[charPositionY][charPositionX];
		// render map
		for (int i=0; i<lebarPeta; i++) {
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
					cout << dye::blue("&") << " ";  // merchant
				} else if (map[i][j]==14) {
					cout << dye::red("Hp");
				} else if (map[i][j]==15) {
					cout << dye::red(" :");
				} else if (map[i][j]==16) {
					cout << dye::red(pokemon[5].hp);
				}
			}
			cout << "\n";
		}
		
		if (charCoordinate==-99) {
			system("cls");
   			merchant();
		}

		// randomize monster to appear
		int probAppear, probPokemon, decision;
		if (charCoordinate==2 || charCoordinate==3) {
			srand (time(NULL));
			probAppear = rand() % 10;               // generate number 0-10
			if (probAppear<3) {
				system("cls");
				cout << dye::red("\nyou found monster!\n");
				cout << "what will you do?\n1) fight\n2) run\n";
				cout << "decision: ";
				cin >> decision;					// input user's desicion
				
				if (decision==1) {
					if (charCoordinate==2) {
						probPokemon = rand() % 3;
						cout << "\nyou will fight " << dye::red(pokemon[probPokemon].name) << endl;
					}
					else if (charCoordinate==3) {
						probPokemon = (rand() % 2) + 3;
						cout << "\n\nyou will fight " << dye::red(pokemon[probPokemon].name) << endl;
					}
					cout << "your pet " << pokemon[5].name << " is ready to fight!\n\n";
					Sleep(2000);
					
					//battle mechanism
					system("CLS");
					int enemyHp = pokemon[probPokemon].hp;
					for (int i=0; enemyHp>0;) {
						cout << pokemon[5].name << "\tvs\t" << pokemon[probPokemon].name << "\n";
						cout << "hp: " << dye::green(pokemon[5].hp) << "\t\thp: " << dye::purple(pokemon[probPokemon].hp) << "\n\n";
						
						cout << "skills: \n";                       // print pokemon's skill
						for (int i=0; i<3; i++) {
							cout << i+1 << ") "<< pokemon[5].skill[i] << "\n";
						}
						cout <<  "choose skill: ";
						cin >> pokemon[5].chosenSkill;

						system("CLS");

						pokemon[5].chosenSkill--;
						pokemon[probPokemon].chosenSkill = pokemon[5].chosenSkill;

							pokemon[5].battleMechanism(&pokemon[probPokemon]);
						if (pokemon[probPokemon].hp!=0) {
							pokemon[probPokemon].battleMechanism(&pokemon[5]);
						}

						if (pokemon[5].hp <=0) {
							pikachuDead();
							goto exit;
						}
						
						// enemy defeated!
						if (pokemon[probPokemon].hp <= 0) {
							pokemon[probPokemon].hp = enemyHp;                //restore enemy's hp to normal
							cout << "\n" << dye::red(pokemon[probPokemon].name) << " defeated!\n\n";
							exp++;
							itemCounter[0]+=2;
							cout << "you gained:\n";
							cout << dye::blue("1") << " exp!\n";
							cout<< dye::yellow("2") << " orbs!\n";
							Sleep(1500);
							break;
						}
					}
				}
			}
		}
	}
	while (usersMove!=quit);
	exit:;
}

