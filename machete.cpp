#include"machete.h"
#include"FileManager.h"
Machete::Machete()
{
	FileManager f2;
	map<string, map<string, string>>mWeaponData;
	f2.loadCSVData("./Weapon.csv", mWeaponData);
	string id = mWeaponData["2"]["weaponId"];
	this->weaponName = mWeaponData[id]["weaponName"];//��������
	this->BaseDamage = atoi(mWeaponData[id]["weaponAtk"].c_str());//���˺�
	this->cirtRate = atoi(mWeaponData[id]["weaponCritRate"].c_str());//������
	this->critPlus = atoi(mWeaponData[id]["weaponCritPlus"].c_str());//����ϵ��
	this->frozenRate = atoi(mWeaponData[id]["weapFrozenRate"].c_str());//����
	this->sunkRate = atoi(mWeaponData[id]["weaponSuckRate"].c_str());//��Ѫ��
	this->sunkPlus = atoi(mWeaponData[id]["weaponSuckPlus"].c_str());//��Ѫϵ��
}

int Machete::getBaseDamage()
{
	return this->BaseDamage;
}

int Machete::getCrit()
{
	if (isTrigger(this->cirtRate))//������������������˺�*����ϵ��
	{
		return this->BaseDamage * this->critPlus;
	}
	else
		return 0;
}

int Machete::getSunkBlood()
{
	if (isTrigger(this->sunkRate))
	{
		return this->BaseDamage * this->sunkPlus;
	}
	else
		return 0;
}

int Machete::getFrozen()
{
	if (isTrigger(this->frozenRate))
	{
		return 1;
	}
	else
		return 0;
}

bool Machete::isTrigger(int rate)
{
	int num = rand() % 100 + 1;//����1~100
	if (num < rate)
	{
		return true;
	}
	else
		return false;
}
