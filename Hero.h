#pragma once
#include<iostream>
#include"Weapon.h"
#include"FileManager.h"
using namespace std;
class Monster;
class Hero {
public:
	Hero(int heroId);
	void Attack(Monster *monster);
	void EquipWeapon(Weapon* weapon);
public:
	int heroHp;
	int heroAtk;
	int heroDef;
	string heroName;
	string heroInfo;
	Weapon* pWeapon;
};