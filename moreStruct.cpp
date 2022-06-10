#include <iostream>

using namespace std;

struct hero {
	string heroName;
	int hp;
	string skill[3];
	int damageSkill[3];
	int choosenSkill;

	void battleWith (hero *enemy) {
		int hpEnemy = enemy->hp;
		int userSkill = choosenSkill;
		cout << heroName << " attack " << enemy->heroName << " using " << skill[userSkill] << "\n";
		enemy->hp -= damageSkill[userSkill];
		cout << enemy->heroName << "'s hp drop from " << hpEnemy << " to " << enemy->hp << "\n";

	}
};

int main () {
	hero khaleed;
	khaleed.heroName = "Khaleed";
	khaleed.hp = 2700;
	khaleed.skill[0] = "desert tornado";
	khaleed.skill[1] = "quicksand guard";
	khaleed.skill[2] = "raging sandstorm";
	khaleed.damageSkill[0] = 250;
	khaleed.damageSkill[1] = 325;
	khaleed.damageSkill[2] = 400;

	hero balmond;
	balmond.heroName = "Balmond";
	balmond.hp = 2800;
	balmond.skill[0] = "soul lock";
	balmond.skill[1] = "cyclone sweep";
	balmond.skill[2] = "lethal counter";
	balmond.damageSkill[0] = 150;
	balmond.damageSkill[1] = 225;
	balmond.damageSkill[2] = 300;

	do {
		cout  << "\n" << khaleed.heroName << "'s skills: \n";
		for (int i=0; i<3; i++) {
			cout << i+1 << ". " << khaleed.skill[i] << "\n";
			if (i==2)
				cout << "4. runnn wkwkwk\n";
		}
		cout << "[P1] what skill do you wanna use? ";
		cin >> khaleed.choosenSkill;
		khaleed.choosenSkill--;
		if (khaleed.choosenSkill==3)
			break;
		khaleed.battleWith(&balmond);

		cout  << "\n" << balmond.heroName << "'s skills: \n";
		for (int i=0; i<3; i++) {
			cout << i+1 << ". " << balmond.skill[i] << "\n";
			if (i==2)
				cout << "4. runnn wkwkw\n";
		}

		cout << "[P2] what skill do you wanna use? ";
		cin >> balmond.choosenSkill;
		balmond.choosenSkill--;
		if (balmond.choosenSkill==3)
			break;
		balmond.battleWith(&khaleed);
	} while (khaleed.choosenSkill!=3 && balmond.choosenSkill!=3);

}
