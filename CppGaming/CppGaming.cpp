#include <iostream>
//#include "Player.h"
using namespace std;

class Player
{
public:
	Player() {};
	virtual ~Player(){}
};

class Knight : public Player
{
public:
	Knight() {};
	virtual ~Knight(){}
};

class Archer : public Player
{
public:
	Archer() {};
	virtual ~Archer() {}
};

class Dog
{

};

int main()
{
	// static_cast
	int hp = 100;
	int maxHp = 200;
	float ratio = static_cast<float>(hp / maxHp);

	// dynamic_cast
	Archer* k = new Archer();
	Player* p = k;
	Knight* k3 = dynamic_cast<Knight*>(p);

	// const_cast
	const char* name = "Jinhyeon";
	char* name2 = const_cast<char*>(name);

	// reinterpret_cast
	Dog* dog = reinterpret_cast<Dog*>(p);
	__int64 address = reinterpret_cast<__int64>(k3);
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