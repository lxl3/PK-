#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include<string>
#include"FileManager.h"
#include"Weapon.h"
#include"Knife.h"
#include"DragonSword.h"
#include"machete.h"
#include"Hero.h"
#include"Monster.h"
void fight()
{
    cout << "************************************************欢迎来到天下第一武道会**************************************************";
    cout << "请选择您的英雄" << endl;
    FileManager f1;
    map<string, map<string, string>>hero;
    f1.loadCSVData("./Hero.csv",hero);
    char buff[1024];
    sprintf(buff,"1、%s<%s>", hero["1"]["heroName"].c_str(),hero["1"]["heroInfo"].c_str());
    cout << buff << endl;
    sprintf(buff, "2、%s<%s>", hero["2"]["heroName"].c_str(), hero["2"]["heroInfo"].c_str());
    cout << buff << endl;
    sprintf(buff, "3、%s<%s>", hero["3"]["heroName"].c_str(), hero["3"]["heroInfo"].c_str());
    cout << buff << endl;
    int choice;
    cin >> choice;
    getchar();
    Hero hero1(choice);
    cout << "您选择的英雄是<" << hero1.heroName<<">"<<endl;
    cout << "请选择你的武器" << endl;
    map<string, map<string, string>>weapon;
    f1.loadCSVData("./Weapon.csv", weapon);
    cout << "1、赤手空拳" << endl;
    char buff2[1024];
    sprintf(buff2, "2、%s", weapon["1"]["weaponName"].c_str());
    cout << buff2 << endl;
    sprintf(buff2, "3、%s", weapon["2"]["weaponName"].c_str());
    cout << buff2 << endl;
    sprintf(buff2, "4、%s", weapon["3"]["weaponName"].c_str());
    cout << buff2 << endl;
    //sprintf(buff2, "4、%s", weapon["4"]["weaponName"].c_str());
    /*map<string, map<string, string>>monster;
    f1.loadCSVData("./Monster.csv", monster);*/
    /*cout << "1、赤手空拳" << endl;
    char buff[1024];
    sprintf(buff, "1、%s", monster["1"]["monsterName"].c_str());
    cout << buff << endl;
    sprintf(buff, "2、%s", monster["2"]["monsterName"].c_str());
    cout << buff << endl;
    sprintf(buff, "3、%s", monster["3"]["monsterName"].c_str());
    cout << buff << endl;*/
    int select;
    cin >> select;
    getchar();
    Weapon* weapon1 =NULL;
    switch (select)
    {
    case 1:
        cout << "你真牛逼，等死吧" << endl;
        break;
    case 2:
        weapon1 = new Knife();
        break;
    case 3:
        weapon1 = new Machete();
        break;
    case 4:
        weapon1 = new DragonSword();
        break;
    default:
        break;
    }
    hero1.EquipWeapon(weapon1);
    int id = 5;//rand() % 5 + 1;//1~5
    Monster monster1(id);
    int round = 1;//回合数
    while(true)

    {   
        getchar();
        system("cls");
        cout << "************************************************当前是第"<<round<<"回合**********************************************************";
        //英雄攻击怪物
        if (hero1.heroHp < 0)
        {
            cout << "英雄<" << hero1.heroName << ">已挂掉：!游戏结束" << endl;
            break;
        }
        hero1.Attack(&monster1);
        //怪物反击英雄
        if (monster1.monsterHp < 0)
        {
            cout << "怪物<" << monster1.monsterName << ">已挂： 游戏通关" << endl;
            break;
        }
        monster1.attack(&hero1);

        cout << "英雄"<<hero1.heroName<<"当前血量为" << hero1.heroHp << endl;
        cout << "怪物"<<monster1.monsterName<<"当前血量为" << monster1.monsterHp << endl;
        if (monster1.monsterHp < 0)
        {
            cout << "怪物<" << monster1.monsterName << ">已挂： 游戏通关" << endl;
            break;
        }
        round++;
    }
}
int main()
{
    srand((unsigned int)time(NULL));
    /*FileManager f1;
    map<string, map<string, string>>hero;
    f1.loadCSVData("./Hero.csv",hero);
    cout << "1号英雄姓名：" << hero["1"]["heroName"] << endl;
    cout << "2号英雄Hp：" << hero["2"]["heroHp"] << endl;
    cout << "3号英雄Atk：" << hero["3"]["heroAtk"] << endl;
    map<string, map<string, string>>monster;
    f1.loadCSVData("./Monster.csv", monster);
    cout << "1号怪物姓名：" << monster["1"]["monsterName"] << endl;
    cout << "2号怪物Hp：" << monster["2"]["monsterHp"] << endl;
    cout << "3号怪物Atk：" << monster["3"]["monsterAtk"] << endl;
    map<string, map<string, string>>weapon;
    f1.loadCSVData("./Weapon.csv", weapon);
    cout << "1号武器姓名：" << weapon["1"]["weaponName"] << endl;
    cout << "2号武器暴击系数：" << weapon["2"]["weaponCritPlus"] << endl;
    cout << "3号武器暴击率：" << weapon["3"]["weaponCritRate"] << endl;
    Weapon * weapon2 = new Knife;
    cout << "Knife武器名称：" <<weapon2->weaponName << endl;
    cout << "Knife武器伤害：" <<weapon2->BaseDamage << endl;
    delete weapon2;
    weapon2 = new Machete;
    cout << "Machete武器的攻击力: " << weapon2->BaseDamage << endl;
    cout << "Machete武器的名称： " << weapon2->weaponName << endl;
    delete weapon2;
    weapon2 = new DragonSword;
    cout << "DragonSword武器的攻击力: " << weapon2->BaseDamage << endl;
    cout << "DragonSword武器的名称： " << weapon2->weaponName << endl;
    delete weapon2;*/
    fight();
}
