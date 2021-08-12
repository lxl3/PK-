#pragma once
#include"Weapon.h"
class Knife :public Weapon {
public:
	Knife();
	virtual int getBaseDamage();
	virtual int getCrit();//获取暴击效果，返回值大于0出发暴击
	virtual int getSunkBlood();//获取吸血效果，返回值大于0出发吸血
	virtual int getFrozen();//获取冰冻效果，返回值大于0，出发冰冻
	virtual bool isTrigger(int rate);//触发概率
};
