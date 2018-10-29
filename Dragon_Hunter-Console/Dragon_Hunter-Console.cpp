// Dragon_Hunter-Console.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include "Game.h"
#include "Game.cpp"
#include <string>
#include <cstdlib>

using namespace std;

string title = "############## Dragon Hunter ##############";
string mainMenu = "# 1. New Game | 2. Bestiary | 3. Exit #";
string line = "##############################################";
string enemy = "Choose your enemy:\n1. Goblin | 2. Bandit | 3. Warewolf | 4. Orc | 5. Dragon  ||| 6. Bestiary | 7. Your stats\nChoose option: ";
string battleMenu = "1. Attack | 2. Potion\nChoose option: ";
int choice;

int main()
{
	Character player;
	Monster goblin("Goblin", 100, 10, 0, 10);
	Monster bandit("Bandit", 200, 50, 10, 50);
	Monster werewolf("Werewolf", 400, 100, 50, 200);
	Monster orc("Orc", 800, 250, 150, 500);
	Monster dragon("Dragon", 1600, 500, 500, 1000);
	CharacterAttack *wsk;
	//wsk = &k
	//wsk-> show();

mm:
	cout << title << endl << mainMenu << endl << line << endl;
	cout << "Choose option: ";
	cin >> choice;
	if (choice == 1) {
		player.create();
		player.show();

	}
	else if (choice == 2) {
		cout << "###--- BESTIARY ---###" << endl << endl;
		goblin.show();
		bandit.show();
		werewolf.show();
		orc.show();
		dragon.show();
		goto mm;
	}
	else if (choice == 3) {
		exit(0);
	}
	else {
		cout << "Wrong value. Try again." << endl << endl;
		goto mm;
	}

bt:
	cout << enemy;
	cin >> choice;
	switch (choice) {
	case 1:
		while (true) {
			cout << battleMenu;
			cin >> choice;
			if (choice == 1) {
				wsk = &player;
				AllAttack(wsk);
				wsk = &goblin;
				AllAttack(wsk);
			}
			else if (choice == 2) {

			}
			else {
				cout << "Wrong value. Try again." << endl;
			}
		}
		break;
	case 2:
		break;
	case 3:
		break;
	case 4:
		break;
	case 5:
		break;
	case 6:
		break;
	case 7:
		break;
	default:
		cout << "Wrong value. Try again." << endl << endl;
		goto bt;
		break;
	}
	return 0;
}