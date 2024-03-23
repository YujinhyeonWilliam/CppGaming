#include <iostream>
#include "Item.h"
#include "Inventory.h"
using namespace std;

Item* DropItem()
{
	if (rand() % 2 == 0)
	{
		Weapon* weapon = new Weapon(ItemType::IT_Weapon);
		return weapon;
	}
	else
	{
		Armor* armor = new Armor(ItemType::IT_Armor);
		return armor;
	}
}

int main()
{
	srand((unsigned int)time(0));
	Inventory* inventory = Inventory::GetInstance();

	// 몬스터 처치 및 아이템 드랍
	for (int i = 0; i < 10; i++)
	{
		Item* item = DropItem();
		item->PrintInfo();

		bool isSuccess = inventory->AddItem(item);

		if (isSuccess)
			cout << " Added Item to Inven. InvenSlot = " << inventory->GetItemCount()<< endl;
		else
		{
			cout << " Failed Adding Item to Inven" << endl;
			delete item;
		}
	}

	// PK 당해서 랜덤으로 일부 아이템 드랍
	for (int i = 0; i < 20; i++)
	{
		int randIndex = rand() % MAX_SLOT;
		Item* item = inventory->GetItemAtSlot(randIndex);

		if (item != nullptr && inventory->RemoveItem(item))
		{
			cout << "Removed Item. Index = " << randIndex << endl;
		}
		else
			cout << "Failed to Remove Item. Random Index = "<< randIndex << endl;
	}
}