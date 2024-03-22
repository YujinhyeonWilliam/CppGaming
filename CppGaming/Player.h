#pragma once

class Player
{
public:
	// �Լ����� �޸� ���� �� Code ������ ����. 
	void Attack();
	void Die();
	void Heal(int healValue);
	virtual void Move();
	virtual void Eat() abstract;
	void PrintHP();

	Player();
	Player(const Player& other);
	Player(int hp, int attack, int defence);
	virtual ~Player();

protected:
	int _hp;
	int _attack;
	int _defence;
};

class Knight : public Player
{
public:
	virtual void Move() override;
	virtual void Eat() override;

	Knight() : Player() {}
	Knight(int hp, int attack, int defence) : Player(hp, attack, defence) {}
private:

};

class Archer : public Player
{
public:

private:

};

class Mage : public Player
{
public:

private:

};