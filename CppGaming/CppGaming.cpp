#include <iostream>
#include "Player.h"
using namespace std;

class Pet
{
public:
	Pet() { cout << "Pet()" << endl; }
	~Pet() { cout << "~Pet()" << endl; }

	Pet(const Pet& pet) { cout << "Pet(const Pet& pet) called" << endl; }
};

class Monster
{
public:
	Monster()
	{
		cout << "Monster() called" << endl;
		_pet = new Pet();
	}
	~Monster()
	{
		cout << "~Monster() called" << endl;
		delete _pet;
		_pet = nullptr;
	}
	
	 Monster(const Monster& k)
	 {
	 	_hp = k._hp;
		_pet = new Pet(*k._pet);
	 	cout << "Monster(const Monster& k) called" << endl;
	 }
	 
	 void operator=(const Monster& k)
	 {
	 	_hp = k._hp;
	 }

public:
	int _hp = 100;
	Pet* _pet;
};

int main()
{
	Monster m1;
	m1._hp = 200;
	Monster m2 = m1;
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