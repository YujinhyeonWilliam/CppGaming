#include <iostream>
#include <vector>
#include <list>
#include <queue>
#include <map>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Pet
{

};

class Knight
{
public:
	
	Knight()
	{

	}

	~Knight()
	{
		if (_pet != nullptr)
			delete _pet;
	}

	// 복사 생성자
	Knight(const Knight& knight)
	{
		_hp = knight._hp;


		// 깊은 복사
		if (knight._pet)
			_pet = new Pet(*knight._pet);

		// 얕은 복사
		//_pet = knight._pet;
	}

	// 복사 대입 연산자
	void operator=(const Knight& knight)
	{
		_hp = knight._hp;
		

		// 깊은 복사
		if (knight._pet)
			_pet = new Pet(*knight._pet);

		// 얕은 복사
		//_pet = knight._pet;
	}


	// 이동 생성자
	Knight(Knight&& knight) noexcept
	{
		_hp = knight._hp;
		_pet = knight._pet;
		knight._pet = nullptr;
	}

	// 이동 대입 연산자
	void operator=(Knight&& knight) noexcept
	{
		_hp = knight._hp;
		_pet = knight._pet;
		knight._pet = nullptr;
	}


	int _hp = 0;
	Pet* _pet = nullptr;
};

void TestKnight_Copy(Knight knight)
{
	knight._hp = 100;
}

void TestKnight_LValueRef(Knight& knight)
{
	knight._hp = 100;
}


void TestKnight_ConstValueRef(const Knight& knight)
{
	//knight._hp = 100;
}

void TestKnight_RValueRef(Knight&& knight)
{
	//knight._hp = 100;
}

int main()
{
	int a = 3;
	Knight k1;
	k1._pet = new Pet();
	Knight k3 = std::move(k1);
}