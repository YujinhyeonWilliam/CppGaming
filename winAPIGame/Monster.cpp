#include "pch.h"
#include "Monster.h"
#include "InputManager.h"

Monster::Monster() : Object(ObjectType::Monster)
{

}

Monster::~Monster()
{
}

void Monster::Init()
{
	_stat.hp = 100;
	_stat.maxHp = 100;
	_stat.speed = 10;

	_pos = Pos{ 400, 300 };
	_lookPos = Pos{ 400, 70 };
	_lookDir = (_lookPos - _pos).normalized();
}

void Monster::Update()
{
	
}

void Monster::Render(HDC hdc)
{
	Utils::DrawCircle(hdc, _pos, 100);
	InputManager* inputManager = GET_SINGLE(InputManager);

	// FrontDir
	HPEN pen = ::CreatePen(PS_SOLID, 1, RGB(255, 0, 0));
	HPEN oldPen = (HPEN)::SelectObject(hdc, pen);

	{
		Utils::DrawLine(hdc, _pos, _lookPos);
	}

	::SelectObject(hdc, oldPen);
	::DeleteObject(pen);


	Vector mousePos = inputManager->GetMousePos();
	Vector monsterToMouseDir = mousePos - _pos;
	monsterToMouseDir.Normalize();

	float dotProduct = monsterToMouseDir.Dot(_lookDir);
	float radian = ::acos(dotProduct);
	float angle = radian * (180 / 3.14f);

	{
		wstring str = std::format(L"angle ({0})", angle);
		Utils::DrawTextW(hdc, { 20, 50 }, str);
	}
}
