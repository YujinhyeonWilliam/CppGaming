#include <iostream>
#include "Player.h"
using namespace std;

class Pos
{
public:
	Pos()
	{

	}

	explicit Pos(int b)
	{
		x = b;
		y = b;
	}

	Pos operator+(const Pos& other)
	{
		Pos pos;
		pos.x = this->x + other.x;
		pos.y = this->y + other.y;
		return pos;
	}

	Pos operator+(const int other)
	{
		Pos pos;
		pos.x = this->x + other;
		pos.y = this->y + other;
		return pos;
	}
	
	bool operator==(const Pos& b)
	{
		return x == b.x && y == b.y;
	}

	Pos& operator=(int b)
	{
		x = b;
		y = b;
		return *this;
	}

	int x = 0;
	int y = 0;
};

Pos operator+(int a, const Pos& b)
{
	Pos pos;
	pos.x = a + b.x;
	pos.y = a + b.y;
	return pos;
}

int main()
{
	// C# Knight k = new Knight();
	// C++ Knight* k = new Knight();
	Pos pos1;
	Pos pos2;
	Pos pos3 = pos1 + pos2;

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