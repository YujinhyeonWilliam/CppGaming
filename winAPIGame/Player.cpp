#include "pch.h"
#include "Player.h"
#include "InputManager.h"
#include "TimeManager.h"
#include "ObjectManager.h"
#include "ResourceManager.h"
#include "LineMesh.h"

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

	if (!GetPlayerTurn())
		return;

	if (inputManager->GetButton(KeyType::A))
	{
		_pos.x -= deltaTime * _stat.speed;
		_dir = Dir::Left;
	}

	if (inputManager->GetButton(KeyType::D))
	{
		_pos.x += deltaTime * _stat.speed;
		_dir = Dir::Right;
	}

	if (inputManager->GetButton(KeyType::W))
	{
		
	}

	if (inputManager->GetButton(KeyType::S))
	{
		
	}

	if (inputManager->GetButton(KeyType::Q))
	{

	}

	if (inputManager->GetButton(KeyType::E))
	{

	}

	if (inputManager->GetButtonDown(KeyType::SpaceBar))
	{

	}
}

void Player::Render(HDC hdc)
{
	//Utils::DrawCircle(hdc, _pos, 50);

	float dirAppliedRatio = _dir == Dir::Left ? 0.5f : -0.5f;

	const LineMesh* mesh = GET_SINGLE(ResourceManager)->GetLineMesh(GetMeshKey());
	if (mesh)
	{
		mesh->Render(hdc, _pos, dirAppliedRatio, 0.5f);
	}

	HPEN pen = ::CreatePen(PS_SOLID, 1, RGB(255, 0, 0));
	HPEN oldPen = (HPEN)::SelectObject(hdc, pen);

	//Utils::DrawLine(hdc, _pos, GetFirePos());

	::SelectObject(hdc, oldPen);
	::DeleteObject(pen);
}

wstring Player::GetMeshKey()
{
	if (_playerType == PlayerType::MissileTank)
		return L"MissileTank";

	return L"CanonTank";
}

