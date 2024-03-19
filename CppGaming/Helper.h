#pragma once

enum PlayerType
{
	PT_None = 0,
	PT_Knight = 1,
	PT_Archer = 2,
	PT_Mage = 3,
};

enum EnemyType
{
	ET_None = 0,
	ET_Slime = 1,
	ET_Orc = 2,
	ET_Skeleton = 3,
};

void EnterLobby();
void SelectPlayer();
void CreateRandomMonster();
void WaitForNextKey();

extern PlayerType playerType;
extern int hp;
extern int attack;
extern int defence;

extern EnemyType monsterType;
extern int monsterHp;
extern int monsterAttack;
extern int monsterDefence;