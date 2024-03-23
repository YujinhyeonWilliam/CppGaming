#include "Item.h"
#include <iostream>
using namespace std;

// *******************
//		Item
// *******************

Item::Item(ItemType itemType) : _itemType(itemType)
{
	int randValue = rand() % 100;

	if (randValue < 50)
	{
		_rarity = IR_Normal;
	}
	else if(randValue < 80)
	{
		_rarity = IR_Rare;
	}
	else
	{
		_rarity = IR_Unique;
	}
}

Item::~Item()
{
}

void Item::PrintInfo()
{
	switch (_rarity)
	{
	case IR_Normal:
		cout << "[��͵�] �Ϲ�" << endl;
		break;
	case IR_Rare:
		cout << "[��͵�] ����" << endl;
		break;
	case IR_Unique:
		cout << "[��͵�] ����ũ" << endl;
		break;
	}
}

ItemType Item::GetItemType()
{
	return _itemType;
}


// *******************
//		Weapon
// *******************

Weapon::Weapon(ItemType itemType) : Item(itemType)
{
	switch (_rarity)
	{
	case IR_Normal:
		SetDamage(1 + rand() % 5);
		break;
	case IR_Rare:
		SetDamage(10 + rand() % 15);
		break;
	case IR_Unique:
		SetDamage(30 + rand() % 40);
		break;
	}
}

Weapon::~Weapon()
{
}

void Weapon::PrintInfo()
{
	cout << "********************" << endl;
	cout << "[Ÿ��] ����" << endl;
	cout << "[���ݷ�] " << _damage << endl;
	Item::PrintInfo();
	cout << "********************" << endl;
}


// *******************
//		Armor
// *******************

Armor::Armor(ItemType itemType) : Item(itemType)
{
	switch (_rarity)
	{
	case IR_Normal:
		SetDefence(1 + rand() % 5);
		break;
	case IR_Rare:
		SetDefence(10 + rand() % 15);
		break;
	case IR_Unique:
		SetDefence(30 + rand() % 40);
		break;
	}
}

Armor::~Armor()
{
}

void Armor::PrintInfo()
{
	cout << "********************" << endl;
	cout << "[Ÿ��] ��" << endl;
	cout << "[����] " << _defence << endl;
	Item::PrintInfo();
	cout << "********************" << endl;
}
