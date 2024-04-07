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

	TickInput(deltaTime);

	switch (_state)
	{
	  case PlayerState::MoveGround: 
		  TickMoveGround(deltaTime); 
		  break;
	  case PlayerState::JumpFall: 
		  TickJumpFall(deltaTime);
		  TickGravity(deltaTime);
		  break;
	}	
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
		SetState(PlayerState::MoveGround);
	}
}

void Player::OnComponentEndOverlap(Collider* collider, Collider* other)
{
	BoxCollider* b1 = dynamic_cast<BoxCollider*>(collider);
	BoxCollider* b2 = dynamic_cast<BoxCollider*>(other);

	if (b1 == nullptr || b2 == nullptr)
		return;

	if (b2->GetCollisionLayer() & CLT_GROUND)
	{
		
	}

}

void Player::SetState(PlayerState state)
{
	if (_state == state)
		return;

	switch (_state)
	{
	case PlayerState::MoveGround:
		_speed.y = 0;
		break;
	case PlayerState::JumpFall:
		break;
	}

	_state = state;
}

void Player::TickMoveGround(float deltaTime)
{
	if (GET_SINGLE(InputManager)->GetButtonDown(KeyType::SpaceBar))
	{
		Jump();
	}
}

void Player::TickJumpFall(float deltaTime)
{

}

void Player::TickInput(float deltaTime)
{
	// TODO 

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
}

void Player::Jump()
{
	if (_state == PlayerState::JumpFall)
		return;

	SetState(PlayerState::JumpFall);
	_speed.y = -500;
}

void Player::TickGravity(float deltaTime)
{
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
