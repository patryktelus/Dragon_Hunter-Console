// Dragon_Hunter-Console.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include "Game.h"
#include "Game.cpp"
#include <string>
#include <cstdlib>
#include <stdlib.h> 
#include <time.h>  

using namespace std;

string title = "############## Dragon Hunter ##############";
string mainMenu = "# 1. New Game | 2. Bestiary | 3. Exit #";
string line = "###########################################";
string enemy = "Choose your enemy:\n1. Goblin | 2. Bandit | 3. Warewolf | 4. Orc | 5. Dragon  ||| 6. Bestiary | 7. Your stats\nChoose option: ";
string battleMenu = "1. Attack | 2. Potion | 3. Run\nChoose option: ";
int choice;

Player player;
Character goblin("Goblin", 70, 10, 0, 25);
Character bandit("Bandit", 200, 50, 10, 100);
Character werewolf("Werewolf", 400, 100, 50, 250);
Character orc("Orc", 800, 250, 150, 700);
Character dragon("Dragon", 1600, 500, 500, 10000);
Character *wsk;


int main()
{
	srand(time(NULL));
mm:
	cout << title << endl << mainMenu << endl << line << endl;
	cout << "Choose option: ";
	cin >> choice;
	cout << endl;
	if (choice == 1) {
		player.create();
		player.show();
	}
	else if (choice == 2) {
		cout << "### BESTIARY ###" << endl << endl;
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
	cout << endl;
	switch (choice) {
	case 1:
		while (true) {
			wsk = &goblin;
			cout << battleMenu;
			cin >> choice;
			cout << endl;
			if (choice == 1) {
				cout << player.name << " attacked " << wsk->name << endl;
				if ((player.str - wsk->def) > 0) {
					wsk->currentHP = wsk->currentHP - (player.str - wsk->def);
				}
				else {
					cout << "You are too weak. You cannot hurt " << wsk->name << endl;
				}
				cout << wsk->name << " hp is now " << wsk->currentHP << endl << endl;
				cout << wsk->name << " attacked " << player.name << endl;
				if ((wsk->str - player.def) > 0) {
					player.currentHP = player.currentHP - (wsk->str - player.def);
				}
				else {
					cout << wsk->name << " cannot hurt you." << endl;
				}
				cout << player.name << " hp is now " << player.currentHP << endl << endl;
				if (player.currentHP <= 0) {
					cout << "Game Over!" << endl << endl;
					wsk->currentHP = wsk->hp;
					goto end;
					break;
				}
				else if (wsk->currentHP <= 0) {
					cout << wsk->name << " died. You earn " << wsk->exp << " experience points." << endl << endl;
					player.exp += wsk->exp;
					if (player.exp >= player.nextExp) {
						player.exp -= player.nextExp;
						player.levelUp();
					}
					wsk->currentHP = wsk->hp;
					break;
				}
			}
			else if (choice == 2) {
				player.potion();
				cout << wsk->name << " attacked " << player.name << endl;
				if ((wsk->str - player.def) > 0) {
					player.currentHP = player.currentHP - (wsk->str - player.def);
				}
				else {
					cout << wsk->name << " cannot hurt you." << endl;
				}
				cout << player.name << " hp is now " << player.currentHP << endl << endl;
				if (player.currentHP <= 0) {
					cout << "Game Over" << endl;
					wsk->currentHP = wsk->hp;
					break;
				}
				else if (wsk->currentHP <= 0) {
					cout << wsk->name << " died. You earn " << wsk->exp << " experience points." << endl << endl;
					player.exp += wsk->exp;
					if (player.exp >= player.nextExp) {
						player.exp -= player.nextExp;
						player.levelUp();
					}
					wsk->currentHP = wsk->hp;
					break;
				}
			}
			else if (choice == 3) {
				int r = rand() % 2;
				if (r == 0) {
					cout << "You did not escape." << endl << endl;
				}
				else if (r == 1) {
					cout << "You escaped." << endl << endl;
					wsk->currentHP = wsk->hp;
					goto bt;
				}
			}
			else {
				cout << "Wrong value. Try again." << endl << endl;
			}
		}
		goto bt;
		break;
	case 2:
		while (true) {
			wsk = &bandit;
			cout << battleMenu;
			cin >> choice;
			cout << endl;
			if (choice == 1) {
				cout << player.name << " attacked " << wsk->name << endl;
				if ((player.str - wsk->def) > 0) {
					wsk->currentHP = wsk->currentHP - (player.str - wsk->def);
				}
				else {
					cout << "You are too weak. You cannot hurt " << wsk->name << endl;
				}
				cout << wsk->name << " hp is now " << wsk->currentHP << endl << endl;
				cout << wsk->name << " attacked " << player.name << endl;
				if ((wsk->str - player.def) > 0) {
					player.currentHP = player.currentHP - (wsk->str - player.def);
				}
				else {
					cout << wsk->name << " cannot hurt you." << endl;
				}
				cout << player.name << " hp is now " << player.currentHP << endl << endl;
				if (player.currentHP <= 0) {
					cout << "Game Over!" << endl;
					wsk->currentHP = wsk->hp;
					break;
				}
				else if (wsk->currentHP <= 0) {
					cout << wsk->name << " died. You earn " << wsk->exp << " experience points." << endl << endl;
					player.exp += wsk->exp;
					if (player.exp >= player.nextExp) {
						player.exp -= player.nextExp;
						player.levelUp();
					}
					wsk->currentHP = wsk->hp;
					break;
				}
			}
			else if (choice == 2) {
				player.potion();
				cout << wsk->name << " attacked " << player.name << endl;
				if ((wsk->str - player.def) > 0) {
					player.currentHP = player.currentHP - (wsk->str - player.def);
				}
				else {
					cout << wsk->name << " cannot hurt you." << endl;
				}
				cout << player.name << " hp is now " << player.currentHP << endl << endl;
				if (player.currentHP <= 0) {
					cout << "Game Over" << endl;
					wsk->currentHP = wsk->hp;
					goto end;
					break;
				}
				else if (wsk->currentHP <= 0) {
					cout << wsk->name << " died. You earn " << wsk->exp << " experience points." << endl;
					player.exp += wsk->exp;
					if (player.exp >= player.nextExp) {
						player.exp -= player.nextExp;
						player.levelUp();
					}
					wsk->currentHP = wsk->hp;
					break;
				}
			}
			else if (choice == 3) {
				int r = rand() % 100;
				if (r <= 40) {
					cout << "You did not escape." << endl << endl;
				}
				else if (r > 40) {
					cout << "You escaped." << endl << endl;
					wsk->currentHP = wsk->hp;
					goto bt;
				}
			}
			else {
				cout << "Wrong value. Try again." << endl << endl;
			}
		}
		goto bt;
		break;
	case 3:
		while (true) {
			wsk = &werewolf;
			cout << battleMenu;
			cin >> choice;
			cout << endl;
			if (choice == 1) {
				cout << player.name << " attacked " << wsk->name << endl;
				if ((player.str - wsk->def) > 0) {
					wsk->currentHP = wsk->currentHP - (player.str - wsk->def);
				}
				else {
					cout << "You are too weak. You cannot hurt " << wsk->name << endl;
				}
				cout << wsk->name << " hp is now " << wsk->currentHP << endl << endl;
				cout << wsk->name << " attacked " << player.name << endl;
				if ((wsk->str - player.def) > 0) {
					player.currentHP = player.currentHP - (wsk->str - player.def);
				}
				else {
					cout << wsk->name << " cannot hurt you." << endl;
				}
				cout << player.name << " hp is now " << player.currentHP << endl << endl;
				if (player.currentHP <= 0) {
					cout << "Game Over!" << endl;
					wsk->currentHP = wsk->hp;
					break;
				}
				else if (wsk->currentHP <= 0) {
					cout << wsk->name << " died. You earn " << wsk->exp << " experience points." << endl << endl;
					player.exp += wsk->exp;
					if (player.exp >= player.nextExp) {
						player.exp -= player.nextExp;
						player.levelUp();
					}
					wsk->currentHP = wsk->hp;
					break;
				}
			}
			else if (choice == 2) {
				player.potion();
				cout << wsk->name << " attacked " << player.name << endl;
				if ((wsk->str - player.def) > 0) {
					player.currentHP = player.currentHP - (wsk->str - player.def);
				}
				else {
					cout << wsk->name << " cannot hurt you." << endl;
				}
				cout << player.name << " hp is now " << player.currentHP << endl << endl;
				if (player.currentHP <= 0) {
					cout << "Game Over" << endl;
					wsk->currentHP = wsk->hp;
					goto end;
					break;
				}
				else if (wsk->currentHP <= 0) {
					cout << wsk->name << " died. You earn " << wsk->exp << " experience points." << endl;
					player.exp += wsk->exp;
					if (player.exp >= player.nextExp) {
						player.exp -= player.nextExp;
						player.levelUp();
					}
					wsk->currentHP = wsk->hp;
					break;
				}
			}
			else if (choice == 3) {
				int r = rand() % 100;
				if (r <= 30) {
					cout << "You did not escape." << endl << endl;
				}
				else if (r > 30) {
					cout << "You escaped." << endl << endl;
					wsk->currentHP = wsk->hp;
					goto bt;
				}
			}
			else {
				cout << "Wrong value. Try again." << endl << endl;
			}
		}
		goto bt;
		break;
	case 4:
		while (true) {
			wsk = &orc;
			cout << battleMenu;
			cin >> choice;
			cout << endl;
			if (choice == 1) {
				cout << player.name << " attacked " << wsk->name << endl;
				if ((player.str - wsk->def) > 0) {
					wsk->currentHP = wsk->currentHP - (player.str - wsk->def);
				}
				else {
					cout << "You are too weak. You cannot hurt " << wsk->name << endl;
				}
				cout << wsk->name << " hp is now " << wsk->currentHP << endl << endl;
				cout << wsk->name << " attacked " << player.name << endl;
				if ((wsk->str - player.def) > 0) {
					player.currentHP = player.currentHP - (wsk->str - player.def);
				}
				else {
					cout << wsk->name << " cannot hurt you." << endl;
				}
				cout << player.name << " hp is now " << player.currentHP << endl << endl;
				if (player.currentHP <= 0) {
					cout << "Game Over!" << endl;
					wsk->currentHP = wsk->hp;
					break;
				}
				else if (wsk->currentHP <= 0) {
					cout << wsk->name << " died. You earn " << wsk->exp << " experience points." << endl << endl;
					player.exp += wsk->exp;
					if (player.exp >= player.nextExp) {
						player.exp -= player.nextExp;
						player.levelUp();
					}
					wsk->currentHP = wsk->hp;
					break;
				}
			}
			else if (choice == 2) {
				player.potion();
				cout << wsk->name << " attacked " << player.name << endl;
				if ((wsk->str - player.def) > 0) {
					player.currentHP = player.currentHP - (wsk->str - player.def);
				}
				else {
					cout << wsk->name << " cannot hurt you." << endl;
				}
				cout << player.name << " hp is now " << player.currentHP << endl << endl;
				if (player.currentHP <= 0) {
					cout << "Game Over" << endl;
					wsk->currentHP = wsk->hp;
					goto end;
					break;
				}
				else if (wsk->currentHP <= 0) {
					cout << wsk->name << " died. You earn " << wsk->exp << " experience points." << endl;
					player.exp += wsk->exp;
					if (player.exp >= player.nextExp) {
						player.exp -= player.nextExp;
						player.levelUp();
					}
					wsk->currentHP = wsk->hp;
					break;
				}
			}
			else if (choice == 3) {
				int r = rand() % 100;
				if (r <= 20) {
					cout << "You did not escape." << endl << endl;
				}
				else if (r > 20) {
					cout << "You escaped." << endl << endl;
					wsk->currentHP = wsk->hp;
					goto bt;
				}
			}
			else {
				cout << "Wrong value. Try again." << endl << endl;
			}
		}
		goto bt;
		break;
	case 5:
		while (true) {
			wsk = &dragon;
			cout << battleMenu;
			cin >> choice;
			cout << endl;
			if (choice == 1) {
				cout << player.name << " attacked " << wsk->name << endl;
				if ((player.str - wsk->def) > 0) {
					wsk->currentHP = wsk->currentHP - (player.str - wsk->def);
				}
				else {
					cout << "You are too weak. You cannot hurt " << wsk->name << endl;
				}
				cout << wsk->name << " hp is now " << wsk->currentHP << endl << endl;
				cout << wsk->name << " attacked " << player.name << endl;
				if ((wsk->str - player.def) > 0) {
					player.currentHP = player.currentHP - (wsk->str - player.def);
				}
				else {
					cout << wsk->name << " cannot hurt you." << endl;
				}
				cout << player.name << " hp is now " << player.currentHP << endl << endl;
				if (player.currentHP <= 0) {
					cout << "Game Over!" << endl;
					wsk->currentHP = wsk->hp;
					break;
				}
				else if (wsk->currentHP <= 0) {
					cout << wsk->name << " died. You earn " << wsk->exp << " experience points." << endl << endl;
					player.exp += wsk->exp;
					if (player.exp >= player.nextExp) {
						player.exp -= player.nextExp;
						player.levelUp();
					}
					wsk->currentHP = wsk->hp;
					break;
				}
			}
			else if (choice == 2) {
				player.potion();
				cout << wsk->name << " attacked " << player.name << endl;
				if ((wsk->str - player.def) > 0) {
					player.currentHP = player.currentHP - (wsk->str - player.def);
				}
				else {
					cout << wsk->name << " cannot hurt you." << endl;
				}
				cout << player.name << " hp is now " << player.currentHP << endl << endl;
				if (player.currentHP <= 0) {
					cout << "Game Over" << endl;
					wsk->currentHP = wsk->hp;
					goto end;
					break;
				}
				else if (wsk->currentHP <= 0) {
					cout << wsk->name << " died. Congratulation you won!" << endl;
					goto end;
					break;
				}
			}
			else if (choice == 3) {
				int r = rand() % 100;
				if (r <= 10) {
					cout << "You did not escape." << endl << endl;
				}
				else if (r > 10) {
					cout << "You escaped." << endl << endl;
					wsk->currentHP = wsk->hp;
					goto bt;
				}
			}
			else {
				cout << "Wrong value. Try again." << endl << endl;
			}
		}
		goto bt;
		break;
	case 6:
		cout << "### BESTIARY ###" << endl << endl;
		goblin.show();
		bandit.show();
		werewolf.show();
		orc.show();
		dragon.show();
		goto bt;
		break;
	case 7:
		player.show();
		goto bt;
		break;
	default:
		cout << "Wrong value. Try again." << endl << endl;
		goto bt;
		break;
	}
	end:
	cout << "Do you wanna play again?" << endl;
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