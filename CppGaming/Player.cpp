#include "Player.h"
#include <iostream>


#pragma region Public Methods

void Player::Attack()
{

}

void Player::Die()
{

}

void Player::Heal(int healValue)
{
	_hp += healValue;
}

void Player::PrintHP()
{
	std::cout << "Hp = " << this->_hp << std::endl;
}

#pragma endregion


#pragma region Private Methods

Player::Player(const Player& other)
{
	_hp = other._hp;
	_attack = other._attack;
	_defence = other._defence;
	std::cout << "Copy Player Constructor!" << std::endl;
}

// 기본 생성자
Player::Player()
{
	_hp = 100;
	_attack = 10;
	_defence = 50;
	std::cout << "Player Constructor!" << std::endl;
}

Player::Player(int hp, int attack, int defence)
{
	_hp = hp;
	_attack = attack;
	_defence = defence;
	std::cout << "Player Constructor!" << std::endl;
}

Player::~Player()
{
	std::cout << "Player Destructor!" << std::endl;
}

#pragma endregion