#include "pch.h"
#include "GameCore.h"
#include "TimeManager.h"
#include "InputManager.h"

GameCore::GameCore()
{
}

GameCore::~GameCore()
{
}

void GameCore::Init(HWND hwnd)
{
	_hwnd = hwnd; // 윈도우 번호
	_hdc = ::GetDC(hwnd); // 도화지 번호
	
	GET_SINGLE(TimeManager)->Init();
	GET_SINGLE(InputManager)->Init(hwnd);
}

void GameCore::Update()
{
	GET_SINGLE(TimeManager)->Update();
	GET_SINGLE(InputManager)->Update();
}

void GameCore::Render()
{
	uint32 fps = GET_SINGLE(TimeManager)->GetFps();
	float deltaTime = GET_SINGLE(TimeManager)->GetDeltaTime() * 1000;
	
	{
		POINT mousePos = GET_SINGLE(InputManager)->GetMousePos();
		wstring str = std::format(L"Mouse Pos ({0}, {1})", mousePos.x, mousePos.y);
		::TextOut(_hdc, 20, 10, str.c_str(), static_cast<int32>(str.size()));
	}

	{
		wstring str = std::format(L"FPS({0}), DT({1} ms)", fps, static_cast<int32>(deltaTime));
		::TextOut(_hdc, 650, 10, str.c_str(), static_cast<int32>(str.size()));
	}

	::Rectangle(_hdc, 200, 200, 400, 400);

}
