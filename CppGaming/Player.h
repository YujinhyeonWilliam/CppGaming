#pragma once

class Player
{
public:
	// 함수들은 메모리 구조 중 Code 영역에 들어간다. 
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