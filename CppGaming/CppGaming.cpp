#include <iostream>
#include <vector>
#include <list>
#include <queue>
#include <map>
#include <unordered_map>
#include <algorithm>
using namespace std;

enum class ItemType
{
	None,
	Armor,
	Weapon,
	Jewelry,
	Consumable
};

enum class Rarity
{
	Common,
	Rare,
	Unique
};

class Item
{
public:
	Item(){}
	Item(int itemid, Rarity rarity, ItemType type) : _itemId(itemid), _rarity(rarity), _type(type){}


public:
	int _itemId = 0;
	Rarity _rarity = Rarity::Common;
	ItemType _type = ItemType::None;
};

int main()
{
	vector<Item> v;
	v.push_back(Item(661, Rarity::Common, ItemType::Weapon));
	v.push_back(Item(12, Rarity::Unique, ItemType::Armor));
	v.push_back(Item(31, Rarity::Rare, ItemType::Jewelry));
	v.push_back(Item(4234, Rarity::Rare, ItemType::Consumable));
	v.push_back(Item(124, Rarity::Rare, ItemType::Weapon));

	{
		Rarity wantedRarity = Rarity::Unique;
		int itemId = 0;
		auto RarityPredicLambda =
		[&wantedRarity, itemId](Item& item)
		{
			return item._rarity == wantedRarity;
		};

		auto it = std::find_if(v.begin(), v.end(), RarityPredicLambda);
		
		if (it == v.end())
			cout << "못찾음." << endl;
		else
			cout << "찾음. id = " << it->_itemId << endl;
	}
}