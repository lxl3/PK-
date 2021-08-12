#pragma once
#include<iostream>
#include<map>
using namespace std;
class Weapon {
public:
	virtual int getBaseDamage() = 0;//��ȡ�����˺�
	virtual int getCrit() = 0;//��ȡ����Ч��������ֵ����0��������
	virtual int getSunkBlood() = 0;//��ȡ��ѪЧ��������ֵ����0������Ѫ
	virtual int getFrozen() = 0;//��ȡ����Ч��������ֵ����0����������
	virtual bool isTrigger(int rate) = 0;//��������
public:
	int BaseDamage;//��������
	string weaponName;//��������
	int cirtRate;//������
	int critPlus;//����ϵ��
	int sunkPlus;//��Ѫϵ��
	int sunkRate;//��Ѫ��
	int frozenRate;//������
};