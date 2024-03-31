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

	// ���� ������
	Knight(const Knight& knight)
	{
		_hp = knight._hp;


		// ���� ����
		if (knight._pet)
			_pet = new Pet(*knight._pet);

		// ���� ����
		//_pet = knight._pet;
	}

	// ���� ���� ������
	void operator=(const Knight& knight)
	{
		_hp = knight._hp;
		

		// ���� ����
		if (knight._pet)
			_pet = new Pet(*knight._pet);

		// ���� ����
		//_pet = knight._pet;
	}


	// �̵� ������
	Knight(Knight&& knight) noexcept
	{
		_hp = knight._hp;
		_pet = knight._pet;
		knight._pet = nullptr;
	}

	// �̵� ���� ������
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