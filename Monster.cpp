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
	this->isFrozen = false;//�Ƿ񱻱�����Ĭ��û�б�����
}

void Monster::attack(Hero* hero)
{
	if (this->isFrozen)
	{
		cout << "����<" << this->monsterName << ">������,���غ��޷����� " << endl;
		return;
	}
	else
	{
		int damage = this->monsterAtk - hero->heroDef > 0 ? this->monsterAtk - hero->heroDef:1;
		hero->heroHp -= damage;
		cout << "����<" << this->monsterName << ">������Ӣ��<"<<hero->heroName <<">�����" << damage << "���˺�" << endl;
	}
}
