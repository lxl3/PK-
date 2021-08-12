#pragma once
#include<iostream>
#include<map>
using namespace std;
class Weapon {
public:
	virtual int getBaseDamage() = 0;//获取基础伤害
	virtual int getCrit() = 0;//获取暴击效果，返回值大于0出发暴击
	virtual int getSunkBlood() = 0;//获取吸血效果，返回值大于0出发吸血
	virtual int getFrozen() = 0;//获取冰冻效果，返回值大于0，出发冰冻
	virtual bool isTrigger(int rate) = 0;//触发概率
public:
	int BaseDamage;//基础攻击
	string weaponName;//武器名称
	int cirtRate;//暴击率
	int critPlus;//暴击系数
	int sunkPlus;//吸血系数
	int sunkRate;//吸血率
	int frozenRate;//冰冻率
};