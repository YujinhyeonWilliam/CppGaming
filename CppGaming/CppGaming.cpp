#include <iostream>
using namespace std;
#include "Helper.h"
#include "Map.h"
#include "Player.h"

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