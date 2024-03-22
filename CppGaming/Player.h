#pragma once

class Player
{
public:
	// 함수들은 메모리 구조 중 Code 영역에 들어간다. 
	void Attack();
	void Die();
	void Heal(int healValue);
	void PrintHP();

	Player();
	Player(const Player& other);
	Player(int hp, int attack, int defence);
	~Player();
private:
	int _hp;
	int _attack;
	int _defence;
};