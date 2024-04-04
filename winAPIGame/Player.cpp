#include "pch.h"
#include "Player.h"
#include "InputManager.h"
#include "TimeManager.h"
#include "ObjectManager.h"
#include "ResourceManager.h"
#include "LineMesh.h"
#include "UIManager.h"
#include "Bullet.h"

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

	UpdateFireAngle();

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
		_fireAngle = ::clamp(_fireAngle + 50 * deltaTime, 0.f, 75.f);
	}

	if (inputManager->GetButton(KeyType::S))
	{
		_fireAngle = ::clamp(_fireAngle - 50 * deltaTime, 0.f, 75.f);
	}

	if (inputManager->GetButton(KeyType::Q))
	{

	}

	if (inputManager->GetButton(KeyType::E))
	{

	}

	if (inputManager->GetButton(KeyType::SpaceBar))
	{
		float percent = GET_SINGLE(UIManager)->GetPowerPercent();
		percent = min(100, percent + 100 * deltaTime);
		GET_SINGLE(UIManager)->SetPowerPercent(percent);
	}

	if (inputManager->GetButtonUp(KeyType::SpaceBar))
	{
		// TODO : ½´ÆÃ
		_playerTurn = false;
		float percent = GET_SINGLE(UIManager)->GetPowerPercent();
		float speed = 10.f * percent;
		float angle = GET_SINGLE(UIManager)->GetBarrelAngle();

		// TODO : ÃÑ¾Ë ½ºÅÈ ¼³Á¤
		const float Deg2Rad = PI / 180.f;
		Bullet* bullet = GET_SINGLE(ObjectManager)->CreateObject<Bullet>();
		bullet->SetPos(_pos);
		bullet->SetSpeed(Vector{ speed * ::cos(angle * Deg2Rad), -speed * ::sin(angle * Deg2Rad)});
		GET_SINGLE(ObjectManager)->Add(bullet);
	}
}

void Player::Render(HDC hdc)
{

	float dirAppliedRatio = _dir == Dir::Left ? 0.5f : -0.5f;

	const LineMesh* mesh = GET_SINGLE(ResourceManager)->GetLineMesh(GetMeshKey());
	if (mesh)
	{
		mesh->Render(hdc, _pos, dirAppliedRatio, 0.5f);
	}

	if (_playerTurn)
	{
		RECT rect;
		rect.bottom = static_cast<LONG>(_pos.y - 60);
		rect.left = static_cast<LONG>(_pos.x - 10);
		rect.right = static_cast<LONG>(_pos.x + 10);
		rect.top = static_cast<LONG>(_pos.y - 80);

		HBRUSH brush = ::CreateSolidBrush(RGB(250, 236, 197));
		HBRUSH oldBrush = (HBRUSH)::SelectObject(hdc, brush);

		::Ellipse(hdc, rect.left, rect.top, rect.right, rect.bottom);

		::SelectObject(hdc, oldBrush);
		::DeleteObject(brush);
	}
}

wstring Player::GetMeshKey()
{
	if (_playerType == PlayerType::MissileTank)
		return L"MissileTank";

	return L"CanonTank";
}

void Player::UpdateFireAngle()
{
	UIManager* uiManager = GET_SINGLE(UIManager);
	
	if (_dir == Dir::Left)
	{
		uiManager->SetPlayerAngle(180.f);
		uiManager->SetBarrelAngle(180 - _fireAngle);
	}
	else
	{
		uiManager->SetPlayerAngle(0.f);
		uiManager->SetBarrelAngle(_fireAngle);
	}
}

