#pragma once

class Player
{
public:
	// �Լ����� �޸� ���� �� Code ������ ����. 
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