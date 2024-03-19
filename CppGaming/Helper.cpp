#include <iostream>
#include "Helper.h"
using namespace std;

PlayerType playerType;
int hp;
int attack;
int defence;

EnemyType monsterType;
int monsterHp;
int monsterAttack;
int monsterDefence;

void EnterLobby()
{
	while (true)
	{
		cout << "-------------------------------" << endl;
		cout << "로비에 입장 했습니다!" << endl;
		cout << "-------------------------------" << endl;

		SelectPlayer();
		CreateRandomMonster();
	}
}

void SelectPlayer()
{
	while (true)
	{
		cout << "-------------------------------" << endl;
		cout << "직업을 골라주세요!" << endl;
		cout << "(1) 기사 (2) 궁수 (3) 법사" << endl;
		cout << "-------------------------------" << endl;
		cout << "> ";

		int choice;
		cin >> choice;

		switch (choice)
		{
		case 1:
			cout << "기사 생성중... " << endl;
			hp = 150;
			attack = 10;
			defence = 8;
			playerType = PlayerType::PT_Knight;
			break;
		case 2:
			cout << "아처 생성중... " << endl;
			hp = 100;
			attack = 15;
			defence = 5;
			playerType = PlayerType::PT_Archer;
			break;
		case 3:
			cout << "법사 생성중... " << endl;
			hp = 80;
			attack = 30;
			defence = 2;
			playerType = PlayerType::PT_Mage;
			break;
		default:
			break;
		}


		break;
	}


}

void CreateRandomMonster()
{

	int randomChoice = 1 + (rand() % 3);
	switch (randomChoice)
	{
	case EnemyType::ET_Slime:
		cout << " 슬라임 소환" << endl;
		break;
	case EnemyType::ET_Orc:
		cout << " 오크 소환" << endl;
		break;
	case EnemyType::ET_Skeleton:
		cout << " 스켈레톤 소환" << endl;
		break;
	}

	WaitForNextKey();
}

void WaitForNextKey()
{

	cout << "계속하려면 1을 눌러주세요" << endl;
	cout << "> ";

	int input;
	cin >> input;
	system("cls");
}


