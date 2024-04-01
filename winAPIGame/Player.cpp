#include "pch.h"
#include "Player.h"
#include "InputManager.h"
#include "TimeManager.h"
#include "Missile.h"
#include "ObjectManager.h"

Player::Player() : Object(ObjectType::Player)
{

}

Player::~Player()
{
}

void Player::Init()
{
	_stat.hp = 100;
	_stat.maxHp = 100;
	_stat.speed = 500;

	_pos.x = 400;
	_pos.y = 500;
}

void Player::Update()
{
	InputManager* inputManager = GET_SINGLE(InputManager);
	float deltaTime = GET_SINGLE(TimeManager)->GetDeltaTime();
	if (inputManager->GetButton(KeyType::A))
	{
		_pos.x -= deltaTime * _stat.speed;
	}

	if (inputManager->GetButton(KeyType::D))
	{
		_pos.x += deltaTime * _stat.speed;
	}

	if (inputManager->GetButton(KeyType::W))
	{
		_pos.y -= deltaTime * _stat.speed;
	}

	if (inputManager->GetButton(KeyType::S))
	{
		_pos.y += deltaTime * _stat.speed;
	}

	if (inputManager->GetButtonDown(KeyType::SpaceBar))
	{
		// TODO : 미사일 발사
		Missile* missile = GET_SINGLE(ObjectManager)->CreateObject<Missile>();
		missile->SetPos(_pos);
		GET_SINGLE(ObjectManager)->Add(missile);
	}
}

void Player::Render(HDC hdc)
{
	Utils::DrawCircle(hdc, _pos, 50);
}
