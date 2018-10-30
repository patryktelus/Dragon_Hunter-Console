#pragma once
#include "pch.h"
#include <iostream>
#include <string>

using namespace std;

class Character {
public:
	string name;
	int hp, str, def, exp;
//public:
	int currentHP;
	Character(string, int, int, int, int);
	void show();
};

class Player :public Character {
public:
	int lvl, nextExp;
//public:
	Player(string, int, int, int, int, int, int);
	void create();
	void show();
	//void potion();
	void levelUp();
};