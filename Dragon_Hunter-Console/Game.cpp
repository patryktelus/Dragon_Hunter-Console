#include "pch.h"
#include <iostream>
#include "Game.h"
#include <string>

using namespace std;

void Player::create() {
	cout << "#############################" << endl;
	cout << "###### Create a character ######" << endl;
	cout << "#############################" << endl;
	cout << "Name: ";
	cin >> name;
	cout << "Strength: ";
	cin >> str;
	cout << "Defence: ";
	cin >> def;
	do {
		if ((str + def) > 10) {
			cout << "#############################" << endl;
			cout << "The sum of strength and defense cannot be more than 10." << endl;
			cout << "-----------------------------------------------------" << endl;
			cout << "Strength: " << endl;
			cin >> str;
			cout << "Defence: " << endl;
			cin >> def;
		}
		else if ((str + def) < 10) {
			cout << "#############################" << endl;
			cout << "You do not spend all points." << endl;
			cout << "-------------------------------------" << endl;
			cout << "Strength: " << endl;
			cin >> str;
			cout << "Defence: " << endl;
			cin >> def;
		}
	} while ((str + def) != 10);
	hp = 100;
	lvl = 0;
	exp = 0;
	currentHP = hp;
	nextExp = (exp + 1) * 100;
	cout << "##############################" << endl << endl;
}

void Player::show() {
	cout << "###############################" << endl;
	cout << "###### " << name << " stats ######" << endl;
	cout << "###############################" << endl;
	cout << "Name: " << name << endl;
	cout << "HP: " << currentHP << "/" << hp << endl;
	cout << "Strength: " << str << endl;
	cout << "Defence: " << def << endl;
	cout << "Level: " << lvl << endl;
	cout << "Experience: " << exp << "/" << nextExp << endl;
	cout << "###############################" << endl << endl;
}

void Player::levelUp() {
	int lp = 10;
	int op = 0;
	cout << "You have reached the level." << endl;
	lvl += 1;
	do {
		cout << "You have " << lp << " learning points." << endl;
		cout << "1. Add 1 strength point." << endl;
		cout << "2. Add 5 strength point." << endl;
		cout << "3. Add 1 defence point." << endl;
		cout << "5. Add 5 defence point." << endl;
		cin >> op;
		if (op == 1) {
			if (lp >= 1) {
				str += 1;
				lp--;
			}
			else {
				cout << "You have not enough learning points." << endl;
			}			
		}
		else if (op == 2) {
			if (lp >= 5) {
				str += 5;
				lp -= 5;
			}
			else {
				cout << "You have not enough learning points." << endl;
			}
		}
		else if (op == 3) {
			if (lp >= 1) {
				def += 1;
				lp--;
			}
			else {
				cout << "You have not enough learning points." << endl;
			}
		}
		else if (op == 4) {
			if (lp >= 5) {
				def += 5;
				lp -= 5;
			}
			else {
				cout << "You have not enough learning points." << endl;
			}
		}
		else {
			cout << "Wrong value. Try again." << endl;
		}
	} while (lp > 0);

}

void Character::show() {
	cout << "###############################" << endl;
	cout << "########### " << name << " ###########" << endl;
	cout << "###############################" << endl;
	cout << "HP: " << hp << endl;
	cout << "Strength: " << str << endl;
	cout << "Defence: " << def << endl;
	cout << "Experience to acquire: " << exp << endl;
	cout << "###############################" << endl << endl;
}

Character::Character(string n = "Character", int h = 100, int s = 10, int d = 0, int e = 10) {
	name = n;
	hp = h;
	str = s;
	def = d;
	exp = e;
	currentHP = hp;
}

Player::Player(string n = "John", int h = 100, int s = 10, int d = 0, int e = 0, int l = 0, int nexp = 100) :Character(n, h, s, d, e) {
	lvl = l;
	nextExp = nexp;
}