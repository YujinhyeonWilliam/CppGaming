#include "pch.h"
#include "DevScene.h"
#include "Utils.h"
#include "InputManager.h"
#include "TimeManager.h"

DevScene::DevScene()
{

}

DevScene::~DevScene()
{

}

void DevScene::Init()
{
}

void DevScene::Update()
{
	//float deltaTime = GET_SINGLE(TimeManager)->GetDeltaTime();
	//if (GET_SINGLE(InputManager)->GetButton(KeyType::A))
	//{
	//	_playerPos.x -= deltaTime * _speed;
	//}
	//
	//if (GET_SINGLE(InputManager)->GetButton(KeyType::D))
	//{
	//	_playerPos.x += deltaTime * _speed;
	//}
	//
	//if (GET_SINGLE(InputManager)->GetButton(KeyType::W))
	//{
	//	_playerPos.y -= deltaTime * _speed;
	//}
	//
	//if (GET_SINGLE(InputManager)->GetButton(KeyType::S))
	//{
	//	_playerPos.y += deltaTime * _speed;
	//}
}

void DevScene::Render(HDC hdc)
{
	// Player
	Utils::DrawCircle(hdc, _playerPos, 50);

	// Monster


	// Projectile
}
