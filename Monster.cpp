#include"Monster.h"
#include"Hero.h"
Monster::Monster(int monsterId)
{
	FileManager f1;
	map<string, map<string, string>>monster;
	f1.loadCSVData("./Monster.csv", monster);
	string tempId =std::to_string(monsterId);
	string id = monster[tempId]["monsterId"];
	this->monsterName= monster[id]["monsterName"];
	this->monsterAtk= atoi(monster[id]["monsterAtk"].c_str());
	this->monsterDef= atoi(monster[id]["monsterDef"].c_str());
	this->monsterHp= atoi(monster[id]["monsterHp"].c_str());
	this->isFrozen = false;//是否被冰冻，默认没有被冰冻
}

void Monster::attack(Hero* hero)
{
	if (this->isFrozen)
	{
		cout << "怪物<" << this->monsterName << ">被冰冻,本回合无法攻击 " << endl;
		return;
	}
	else
	{
		int damage = this->monsterAtk - hero->heroDef > 0 ? this->monsterAtk - hero->heroDef:1;
		hero->heroHp -= damage;
		cout << "怪物<" << this->monsterName << ">攻击了英雄<"<<hero->heroName <<">造成了" << damage << "的伤害" << endl;
	}
}
