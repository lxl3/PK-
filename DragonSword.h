#pragma once
#include"Weapon.h"
#include<iostream>
using namespace std;
class DragonSword :public Weapon {
public:
	DragonSword();
	virtual int getBaseDamage();
	virtual int getCrit();//��ȡ����Ч��������ֵ����0��������
	virtual int getSunkBlood();//��ȡ��ѪЧ��������ֵ����0������Ѫ
	virtual int getFrozen();//��ȡ����Ч��������ֵ����0����������
	virtual bool isTrigger(int rate);//��������
};
