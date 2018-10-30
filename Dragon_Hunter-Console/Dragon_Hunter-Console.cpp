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
	Player player;
	Character goblin("Goblin", 100, 10, 0, 10);
	Character bandit("Bandit", 200, 50, 10, 50);
	Character werewolf("Werewolf", 400, 100, 50, 200);
	Character orc("Orc", 800, 250, 150, 500);
	Character dragon("Dragon", 1600, 500, 500, 1000);
	Character *wsk;
	//wsk = &k
	//wsk-> show();//

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
				wsk = &goblin;
				cout << player.name << " attacked " << wsk->name << endl;
				wsk->currentHP = wsk->currentHP - (player.str - wsk->def);
				cout << wsk->name << " hp is now " << wsk->currentHP << endl;
				cout << wsk->name << " attacked " << player.name << endl;
				player.currentHP = player.currentHP - (wsk->str - player.def);
				cout << player.name << " hp is now " << player.currentHP << endl;
				if (player.currentHP <= 0) {
					cout << "Game Over" << endl;
					return false;
				}
				else if (wsk->currentHP <= 0) {
					cout << wsk->name << " died. You earn " << wsk->exp << " experience points.";
					player.exp += wsk->exp;
					if (player.exp >= player.nextExp) {
						player.exp -= player.nextExp;
						player.levelUp();
					}
					return false;
				}
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
	cout << "Play again?" << endl;
	cout << "1. Yes | 2. No" << endl;
	cin >> choice;
	if (choice == 1) {
		goto mm;
	}
	else if (choice == 2) {
		exit(0);
	}
	else {
		cout << "Wrong value. Try again." << endl << endl;
	}
	return 0;
}