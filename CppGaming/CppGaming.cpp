#include <iostream>
using namespace std;

void AddHP(int* hp, int value)
{
	*hp += value;
}

int main()
{
	int hp = 100;
	int* ptr = &hp;
	int** pptr = &ptr;

	int a = 3;
	//cout << (int)ptr << endl;
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