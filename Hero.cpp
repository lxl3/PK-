#include"Hero.h"
#include"Monster.h"
Hero::Hero(int heroId)
{
    FileManager f1;
    map<string, map<string, string>>hero;
    f1.loadCSVData("./Hero.csv", hero);
    //int תstring
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
    if (this->pWeapon == NULL)//˵�����ֿ�ȭ
    {
        damage = this->heroAtk;
    }
    else
    {
        damage = this->heroAtk + pWeapon->BaseDamage;
        //�Ƿ񱩻�
        crit = pWeapon->getCrit();
        //�Ƿ���Ѫ
        sunk = pWeapon->getSunkBlood();
        //�Ƿ����
        frozen = pWeapon->getFrozen();
    }
    if (crit)
    {
        damage += crit;//�������ٴμ��ϱ����ӳ��˺�
        cout << "Ӣ�۵�������������Ч��,����<" << monster->monsterName << ">�ܵ������˺�" << endl;
    }
    if (sunk)
    {
        cout << "Ӣ�۵�����������ѪЧ����Ӣ��<" <<this->heroName << ">����Ѫ��" <<sunk<< endl;

    }
    if (frozen)
    {
        monster->isFrozen = true;
        cout << "Ӣ�۵�������������Ч��" << "����<" << monster->monsterName << ">ֹͣ����һ�غ�" << endl;
    }
    monster->isFrozen = frozen;
    int trueDamage = damage - monster->monsterDef > 0 ? damage - monster->monsterDef : 1;
    //��Ѫ
    this->heroHp += sunk;
    monster->monsterHp -= trueDamage;
    cout << "Ӣ��<" << this->heroName << ">������<" << monster->monsterName << ">��ɵ��˺�Ϊ" << trueDamage << endl;
}

void Hero::EquipWeapon(Weapon* weapon)
{
    if (weapon == NULL)
    {
        return;
    }
    this->pWeapon = weapon;//ά���û�ѡ�������
    cout << "Ӣ��< " << this->heroName << ">װ���������� " << this->pWeapon->weaponName << "!" <<endl;

}
