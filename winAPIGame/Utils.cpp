#include "pch.h"
#include "Utils.h"

void Utils::DrawText(HDC hdc, Pos pos, const wstring& str)
{
	::TextOut(hdc, static_cast<int32>(pos.x), static_cast<int32>(pos.y), str.c_str(), static_cast<int32>(str.size()));
}

void Utils::DrawRect(HDC hdc, Pos pos, int32 w, int32 h)
{
	int32 PosX = static_cast<int32>(pos.x);
	int32 PosY = static_cast<int32>(pos.y);
	int32 halfWidth = w / 2;
	int32 halfHeight = h / 2;
	::Rectangle(hdc, PosX - halfWidth, PosY - halfHeight, PosX + halfWidth, PosY + halfHeight);
}

void Utils::DrawCircle(HDC hdc, Pos pos, int32 radius)
{
	int32 PosX = static_cast<int32>(pos.x);
	int32 PosY = static_cast<int32>(pos.y);
	::Ellipse(hdc, PosX - radius, PosY - radius, PosX + radius, PosY + radius);
}

void Utils::DrawLine(HDC hdc, Pos from, Pos to)
{
	::MoveToEx(hdc, static_cast<int32>(from.x), static_cast<int32>(from.y), nullptr);
	::LineTo(hdc, static_cast<int32>(to.x), static_cast<int32>(to.y));
}
