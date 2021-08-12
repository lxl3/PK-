#pragma once
#include"Hero.h"
#include<string>
#include<iostream>
using namespace std;
class Hero;
class Monster {
public:
	Monster(int monsterId);
	void attack(Hero* hero);
public:
	string monsterName;
	int monsterHp;
	int monsterAtk;
	int monsterDef;
	bool isFrozen;


};