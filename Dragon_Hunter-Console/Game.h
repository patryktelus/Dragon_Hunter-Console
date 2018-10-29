#pragma once
#include "pch.h"
#include <iostream>
#include <string>

using namespace std;



class CharacterAttack {
public:
	virtual void attack() = 0;
};

class Character :public CharacterAttack {
	string name;
	int hp, str, def, lvl, exp;

public:
	int currentHP;
	int nextExp;
	Character(string, int, int, int, int, int);
	void create();
	void show();
	void potion();
	void levelUp();
	virtual void attack();
};

class Monster :public CharacterAttack {
	string name;
	int hp, str, def, exp;
public:
	int currentHP;
	Monster(string n, int h, int s, int d, int e);
	virtual void attack();
	void show();
};