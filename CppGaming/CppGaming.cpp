#include <iostream>
using namespace std;

struct StatInfo
{
	int hp;
	int attack;
	int defence;
};

StatInfo CreatePlayer()
{
	StatInfo info;
	cout << " 플레이어 생성 " << endl;
	info.hp = 100;
	info.attack = 10;
	info.defence = 2;

	return info;
}

void CreateMonster(StatInfo* info)
{
	info->hp = 40;
	info->attack = 8;
	info->defence = 1;
}

void Battle(StatInfo* player, StatInfo* monster)
{
	while (true)
	{
	  int damage = player->attack - monster->defence;

	  if (damage < 0)
		  damage = 0;

	  monster->hp -= damage;
	  if (monster->hp < 0)
		  monster->hp = 0;

	  cout << " 몬스터 HP : " << monster->hp << endl;

	  if (monster->hp == 0)
		  return;

	  damage = monster->attack - player->defence;
	  if (damage < 0)
		  damage = 0;

	  cout << " 플레이어 HP : " << player->hp << endl;

	  player->hp -= damage;
	  if (player->hp < 0)
		  player->hp = 0;

	  if (player->hp == 0)
		  return;
	}

}

int main()
{
	StatInfo player = CreatePlayer();
	StatInfo monster;
	CreateMonster(&monster);

	Battle(&player, &monster);
}


/*

#include <iostream>
using namespace std;
#include "Helper.h"
#include "Map.h"
#include "Player.h"


[Map and Player Move]

int main()
{
	SetCursorOnOff(false);

	while (true)
	{
		// 입력
		HandleKeyInput();

		// 출력
		HandleMove();

		// 로직
		PrintMap2D();
	}
}

*/