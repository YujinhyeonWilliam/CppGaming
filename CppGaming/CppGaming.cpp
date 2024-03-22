#include <iostream>
using namespace std;

struct StatInfo
{
	int hp;
	int attack;
	int defence;
};


// 1. 값(복사) 전달 방식
void PrintByCopy(StatInfo player)
{
	cout << "-------------" << endl;
	cout << "HP : " << player.hp << endl;
	cout << "ATT : " << player.attack << endl;
	cout << "DEF : " << player.defence << endl;
	cout << "-------------" << endl;
}

 // 2. 주소 전달 방식
void PrintByPointer(StatInfo* player)
{
	cout << "-------------" << endl;
	cout << "HP : " << player->hp << endl;
	cout << "ATT : " << player->attack << endl;
	cout << "DEF : " << player->defence << endl;
	cout << "-------------" << endl;
}

// 3) 참조 전달 방식 (원본 값을 유지하며, 복사비용을 아끼기 위해서 const 사용)

// 아래와 같이 OUT 키워드를 넣으면 확실하게 이 함수 안에서 수정하는 코드가 있다는 것을 알려주는 암묵적 룰이 있다.
// 언리얼 샘플 코드에서도 간혹 보이므로 이상한 코드 형태가 아님
#define OUT
void PrintByRef(OUT StatInfo& player)
{
	player.hp = 0;

	cout << "-------------" << endl;
	cout << "HP : " << player.hp << endl;
	cout << "ATT : " << player.attack << endl;
	cout << "DEF : " << player.defence << endl;
	cout << "-------------" << endl;
}

int main()
{
	StatInfo player = { 100, 10, 1 };
	PrintByCopy(player);

	StatInfo* ptr = nullptr;
	PrintByPointer(&player);
	PrintByRef(OUT player);
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