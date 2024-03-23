#include <iostream>
#include "Player.h"
using namespace std;

class Pet
{
public:
	Pet()
	{
	 std::cout << "Pet()" << std::endl;	  
	}
	~Pet()
	{
		std::cout << "~Pet()" << std::endl;
	}
};

class Archer : public Player
{
public:
	Archer()
	{
		_pet = new Pet();
		std::cout << "Archer()" << std::endl;
	}

	~Archer()
	{
		std::cout << "~Archer()" << std::endl;
		delete _pet;
		_pet = nullptr;
	}

	virtual void Eat() override;
private:
	Pet* _pet;
};

void Archer::Eat()
{
}

int main()
{
	while(true)
	{
	  Player* archer = new Archer();
	  delete archer;
	}

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