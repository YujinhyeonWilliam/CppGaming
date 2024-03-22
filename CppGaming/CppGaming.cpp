#include <iostream>
#include "Player.h"
using namespace std;

void Fight(Player* k1, Player* k2)
{

}

int main()
{
	Player p1{ 100, 30, 2 };
	Player p2(p1);

	p1.Heal(30);
	p2.Heal(-10);

	p1.PrintHP();
	p2.PrintHP();
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