#pragma once
#include "pch.h"
#include <iostream>
#include <string>

using namespace std;

class Character {
public:
	string name;
	int hp, str, def, exp;
	int currentHP;
	Character(string, int, int, int, int);
	~Character();
	void show();
};

class Player :public Character {
public:
	int lvl, nextExp;
	Player(string, int, int, int, int, int, int);
	~Player();
	void create();
	void show();
	void potion();
	void levelUp();
};