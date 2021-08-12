#include"Hero.h"
#include"Monster.h"
Hero::Hero(int heroId)
{
    FileManager f1;
    map<string, map<string, string>>hero;
    f1.loadCSVData("./Hero.csv", hero);
    //int 转string
    string tempid = std::to_string(heroId);
    string id = hero[tempid]["heroId"];
    this->heroName = hero[id]["heroName"];
    this->heroAtk = atoi(hero[id]["heroAtk"].c_str());
    this->heroDef= atoi(hero[id]["heroAtk"].c_str());
    this->heroHp= atoi(hero[id]["heroHp"].c_str());
    this->heroInfo= atoi(hero[id]["heroInfo"].c_str());
    this->pWeapon = NULL;

}

void Hero::Attack(Monster* monster)
{
    int crit = 0;
    int sunk = 0;
    int frozen = 0;
    int damage = 0;
    if (this->pWeapon == NULL)//说明赤手空拳
    {
        damage = this->heroAtk;
    }
    else
    {
        damage = this->heroAtk + pWeapon->BaseDamage;
        //是否暴击
        crit = pWeapon->getCrit();
        //是否吸血
        sunk = pWeapon->getSunkBlood();
        //是否冰冻
        frozen = pWeapon->getFrozen();
    }
    if (crit)
    {
        damage += crit;//攻击力再次加上暴击加成伤害
        cout << "英雄的武器触发暴击效果,怪物<" << monster->monsterName << ">受到暴击伤害" << endl;
    }
    if (sunk)
    {
        cout << "英雄的武器触发吸血效果，英雄<" <<this->heroName << ">增加血量" <<sunk<< endl;

    }
    if (frozen)
    {
        monster->isFrozen = true;
        cout << "英雄的武器触发冰冻效果" << "怪物<" << monster->monsterName << ">停止攻击一回合" << endl;
    }
    monster->isFrozen = frozen;
    int trueDamage = damage - monster->monsterDef > 0 ? damage - monster->monsterDef : 1;
    //吸血
    this->heroHp += sunk;
    monster->monsterHp -= trueDamage;
    cout << "英雄<" << this->heroName << ">攻击了<" << monster->monsterName << ">造成的伤害为" << trueDamage << endl;
}

void Hero::EquipWeapon(Weapon* weapon)
{
    if (weapon == NULL)
    {
        return;
    }
    this->pWeapon = weapon;//维护用户选择的武器
    cout << "英雄< " << this->heroName << ">装备了武器： " << this->pWeapon->weaponName << "!" <<endl;

}
