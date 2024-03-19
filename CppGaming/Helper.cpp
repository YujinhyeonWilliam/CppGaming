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
		cout << "�κ� ���� �߽��ϴ�!" << endl;
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
		cout << "������ ����ּ���!" << endl;
		cout << "(1) ��� (2) �ü� (3) ����" << endl;
		cout << "-------------------------------" << endl;
		cout << "> ";

		int choice;
		cin >> choice;

		switch (choice)
		{
		case 1:
			cout << "��� ������... " << endl;
			hp = 150;
			attack = 10;
			defence = 8;
			playerType = PlayerType::PT_Knight;
			break;
		case 2:
			cout << "��ó ������... " << endl;
			hp = 100;
			attack = 15;
			defence = 5;
			playerType = PlayerType::PT_Archer;
			break;
		case 3:
			cout << "���� ������... " << endl;
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
		cout << " ������ ��ȯ" << endl;
		break;
	case EnemyType::ET_Orc:
		cout << " ��ũ ��ȯ" << endl;
		break;
	case EnemyType::ET_Skeleton:
		cout << " ���̷��� ��ȯ" << endl;
		break;
	}

	WaitForNextKey();
}

void WaitForNextKey()
{

	cout << "����Ϸ��� 1�� �����ּ���" << endl;
	cout << "> ";

	int input;
	cin >> input;
	system("cls");
}


