#include "pch.h"
#include "Player.h"
#include "InputManager.h"
#include "TimeManager.h"
#include "Flipbook.h"
#include "ResourceManager.h"

Player::Player()
{
	ResourceManager* resourceManager = GET_SINGLE(ResourceManager);
	_flipbookUp		= resourceManager->GetFlipBook(L"FB_MoveUp");
	_flipbookDown	= resourceManager->GetFlipBook(L"FB_MoveDown");
	_flipbookLeft	= resourceManager->GetFlipBook(L"FB_MoveLeft");
	_flipbookRight	= resourceManager->GetFlipBook(L"FB_MoveRight");
}

Player::~Player()
{
}

void Player::BeginPlay()
{
	Super::BeginPlay();
	SetFlipBook(_flipbookRight);
}

void Player::Tick()
{
	Super::Tick();
	float deltaTime = GET_SINGLE(TimeManager)->GetDeltaTime();

	// TODO : 움직여야함
	if (GET_SINGLE(InputManager)->GetButton(KeyType::W))
	{
		_pos.y -= 200 * deltaTime;
		SetFlipBook(_flipbookUp);
	}
	else if (GET_SINGLE(InputManager)->GetButton(KeyType::S))
	{
		_pos.y += 200 * deltaTime;
		SetFlipBook(_flipbookDown);
	}
	else if (GET_SINGLE(InputManager)->GetButton(KeyType::A))
	{
		_pos.x -= 200 * deltaTime;
		SetFlipBook(_flipbookLeft);
	}
	else if (GET_SINGLE(InputManager)->GetButton(KeyType::D))
	{
		_pos.x += 200 * deltaTime;
		SetFlipBook(_flipbookRight);
	}
}

void Player::Render(HDC hdc)
{
	Super::Render(hdc);
}
