#include <iostream>
using namespace std;

struct StatInfo
{
	int hp;
	int attack;
	int defence;
};


// 1. ��(����) ���� ���
void PrintByCopy(StatInfo player)
{
	cout << "-------------" << endl;
	cout << "HP : " << player.hp << endl;
	cout << "ATT : " << player.attack << endl;
	cout << "DEF : " << player.defence << endl;
	cout << "-------------" << endl;
}

 // 2. �ּ� ���� ���
void PrintByPointer(StatInfo* player)
{
	cout << "-------------" << endl;
	cout << "HP : " << player->hp << endl;
	cout << "ATT : " << player->attack << endl;
	cout << "DEF : " << player->defence << endl;
	cout << "-------------" << endl;
}

// 3) ���� ���� ��� (���� ���� �����ϸ�, �������� �Ƴ��� ���ؼ� const ���)

// �Ʒ��� ���� OUT Ű���带 ������ Ȯ���ϰ� �� �Լ� �ȿ��� �����ϴ� �ڵ尡 �ִٴ� ���� �˷��ִ� �Ϲ��� ���� �ִ�.
// �𸮾� ���� �ڵ忡���� ��Ȥ ���̹Ƿ� �̻��� �ڵ� ���°� �ƴ�
#define OUT
void PrintByRef(OUT StatInfo& player)
{
	player.hp = 0;

	cout << "-------------" << endl;
	cout << "HP : " << player.hp << endl;
	cout << "ATT : " << player.attack << endl;
	cout << "DEF : " << player.defence << endl;
	cout << "-------------" << endl;
}

int main()
{
	StatInfo player = { 100, 10, 1 };
	PrintByCopy(player);

	StatInfo* ptr = nullptr;
	PrintByPointer(&player);
	PrintByRef(OUT player);
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
		// �Է�
		HandleKeyInput();

		// ���
		HandleMove();

		// ����
		PrintMap2D();
	}
}

*/