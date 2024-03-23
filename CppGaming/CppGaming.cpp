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
	// (1) malloc + free  (C방식)
	// (2) new + delete (C++방식) 

	// (1)과 (2)의
	//  차이1. (1)은 함수 (2)는 연산자 
	//  차이2. (1)은 메모리만 할당해주고 (2)는 생성자 및 소멸자를 호출해준다.
	//  그래서 C++, 언리얼 작업에선 주로 new와 delete를 사용한다

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
		// 입력
		HandleKeyInput();

		// 출력
		HandleMove();

		// 로직
		PrintMap2D();
	}
}

*/