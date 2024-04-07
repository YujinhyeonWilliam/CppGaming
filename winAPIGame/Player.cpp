#include "pch.h"
#include "Player.h"
#include "InputManager.h"
#include "TimeManager.h"
#include "Flipbook.h"
#include "ResourceManager.h"
#include "CameraComponent.h"
#include "BoxCollider.h"

Player::Player()
{
	ResourceManager* resourceManager = GET_SINGLE(ResourceManager);
	_flipbookUp		= resourceManager->GetFlipBook(L"FB_MoveUp");
	_flipbookDown	= resourceManager->GetFlipBook(L"FB_MoveDown");
	_flipbookLeft	= resourceManager->GetFlipBook(L"FB_MoveLeft");
	_flipbookRight	= resourceManager->GetFlipBook(L"FB_MoveRight");

	CameraComponent* camera = new CameraComponent();
	AddComponent(camera);
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

	if (GET_SINGLE(InputManager)->GetButton(KeyType::A))
	{
		_pos.x -= 200 * deltaTime;
		SetFlipBook(_flipbookLeft);
	}
	else if (GET_SINGLE(InputManager)->GetButton(KeyType::D))
	{
		_pos.x += 200 * deltaTime;
		SetFlipBook(_flipbookRight);
	}
	else if (GET_SINGLE(InputManager)->GetButtonDown(KeyType::SpaceBar))
	{
		Jump();
	}

	if(!_onGround)
	  TickGravity();
}

void Player::Render(HDC hdc)
{
	Super::Render(hdc);
}

void Player::OnComponentBeginOverlap(Collider* collider, Collider* other)
{
	BoxCollider* b1 = dynamic_cast<BoxCollider*>(collider);
	BoxCollider* b2 = dynamic_cast<BoxCollider*>(other);

	if (b1 == nullptr || b2 == nullptr)
		return;

	AdjustCollisionPos(b1, b2);

	if (b2->GetCollisionLayer() & CLT_GROUND)
	{
	  _onGround = true;
	  _jumping = false;
	}
}

void Player::OnComponentEndOverlap(Collider* collider, Collider* other)
{
	BoxCollider* b1 = dynamic_cast<BoxCollider*>(collider);
	BoxCollider* b2 = dynamic_cast<BoxCollider*>(other);

	if (b1 == nullptr || b2 == nullptr)
		return;

	if (b2->GetCollisionLayer() & CLT_GROUND)
		_onGround = false;
}

void Player::Jump()
{
	if (_jumping)
		return;

	_jumping = true;
	_onGround = false;
	_speed.y = -500;
}

void Player::TickGravity()
{
	float deltaTime = GET_SINGLE(TimeManager)->GetDeltaTime();

	if (deltaTime > 0.1f)
		return;

	_speed.y += _gravity * deltaTime;
	_pos.y += _speed.y * deltaTime;
}

void Player::AdjustCollisionPos(BoxCollider* b1, BoxCollider* b2)
{
	RECT r1 = b1->GetRect();
	RECT r2 = b2->GetRect();

	Vector2D pos = GetPos();
	
	RECT intersect = {};
	if (::IntersectRect(&intersect, &r1, &r2))
	{
		int32 w = intersect.right - intersect.left;
		int32 h = intersect.bottom - intersect.top;

		if (w > h)
		{
			if (intersect.top == r2.top)
			{
				pos.y -= h;
			}
			else
			{
				pos.y += h;
			}
		}
		else
		{
			if (intersect.left == r2.left)
			{
				pos.x -= w;
			}
			else
			{
				pos.x += w;
			}
		}
	}

	SetPos(pos);
}
