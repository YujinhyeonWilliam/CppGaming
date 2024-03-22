#include <iostream>
#include "Player.h"
using namespace std;


void MovePlayer(Player* player)
{
	(*player).Move();
}

int main()
{
	Knight k1;
	MovePlayer(&k1);
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