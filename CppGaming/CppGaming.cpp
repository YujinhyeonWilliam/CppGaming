#include <iostream>
#include "Player.h"
using namespace std;

class Monster
{
public:
	Monster() { cout << "Monster()" << endl; }
	~Monster() { cout << "~Monster()" << endl;  }
	int _hp = 0;

};


Player* FindPlayer(int id)
{
	//TODO

	return nullptr;
}

int main()
{
	// (1) malloc + free  (C���)
	// (2) new + delete (C++���) 

	// (1)�� (2)��
	//  ����1. (1)�� �Լ� (2)�� ������ 
	//  ����2. (1)�� �޸𸮸� �Ҵ����ְ� (2)�� ������ �� �Ҹ��ڸ� ȣ�����ش�.
	//  �׷��� C++, �𸮾� �۾����� �ַ� new�� delete�� ����Ѵ�

	 Monster* m1 = new Monster[5]();
	 m1->_hp = 10;
	 delete[] m1;
	 m1 = nullptr;

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
		// �Է�
		HandleKeyInput();

		// ���
		HandleMove();

		// ����
		PrintMap2D();
	}
}

*/