#include"DragonSword.h"
#include"FileManager.h"
DragonSword::DragonSword()
{
	FileManager f2;
	map<string, map<string, string>>mWeaponData;
	f2.loadCSVData("./Weapon.csv", mWeaponData);
	string id = mWeaponData["3"]["weaponId"];
	this->weaponName = mWeaponData[id]["weaponName"];//武器名称
	this->BaseDamage = atoi(mWeaponData[id]["weaponAtk"].c_str());//基伤害
	this->cirtRate = atoi(mWeaponData[id]["weaponCritRate"].c_str());//暴击率
	this->critPlus = atoi(mWeaponData[id]["weaponCritPlus"].c_str());//暴击系数
	this->frozenRate = atoi(mWeaponData[id]["weapFrozenRate"].c_str());//冰冻
	this->sunkRate = atoi(mWeaponData[id]["weaponSuckRate"].c_str());//吸血率
	this->sunkPlus = atoi(mWeaponData[id]["weaponSuckPlus"].c_str());//吸血系数
}

int DragonSword::getBaseDamage()
{
	return this->BaseDamage;
}

int DragonSword::getCrit()
{
	if (isTrigger(this->cirtRate))//如果出发暴击，基础伤害*暴击系数
	{
		return this->BaseDamage * this->critPlus;
	}
	else
		return 0;
}

int DragonSword::getSunkBlood()
{
	if (isTrigger(this->sunkRate))
	{
		return this->BaseDamage * this->sunkPlus;
	}
	else
		return 0;
}

int DragonSword::getFrozen()
{
	if (isTrigger(this->frozenRate))
	{
		return 1;
	}
	else
		return 0;
}

bool DragonSword::isTrigger(int rate)
{
	int num = rand() % 100 + 1;//产生1~100
	if (num < rate)
	{
		return true;
	}
	else
		return false;
}
