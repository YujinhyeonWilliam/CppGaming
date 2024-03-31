#pragma once
#include <wtypes.h>

class GameCore
{
public:
	GameCore();
	~GameCore();

public:
	void Init(HWND hwnd);
	void Update();
	void Render();

private:
	HWND _hwnd = {};
	HDC _hdc = {};
};

