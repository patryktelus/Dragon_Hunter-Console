#include "pch.h"
#include <iostream>
#include "Game.h"
#include <string>

using namespace std;


void AllAttack(CharacterAttack *x) {
	x->attack();
}

void Character::create() {
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

void Character::show() {
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

void Character::attack() {
	cout << "Monster hp: ";
}

void Monster::show() {
	cout << "###############################" << endl;
	cout << "########### " << name << " ###########" << endl;
	cout << "###############################" << endl;
	cout << "HP: " << hp << endl;
	cout << "Strength: " << str << endl;
	cout << "Defence: " << def << endl;
	cout << "Experience to acquire: " << exp << endl;
	cout << "###############################" << endl << endl;
}

Character::Character(string n = "John", int h = 100, int s = 10, int d = 0, int l = 0, int e = 0) {
	name = n;
	hp = h;
	str = s;
	def = d;
	lvl = l;
	exp = e;
}

Monster::Monster(string n = "Monster", int h = 100, int s = 10, int d = 0, int e = 10) {
	name = n;
	hp = h;
	str = s;
	def = d;
	exp = e;
	currentHP = hp;
}

void Monster::attack() {
	cout << "Attack M" << endl;
}