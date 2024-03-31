#include "pch.h"
#include "InputManager.h"

void InputManager::Init(HWND hwnd)
{
	_hwnd = hwnd;
	_states.resize(KEY_TYPE_COUNT, KeyState::None);
}

void InputManager::Update()
{
	BYTE asciiKeys[KEY_TYPE_COUNT] = {};

	if (::GetKeyboardState(asciiKeys) == false)
		return;
	
	for (uint32 key = 0; key < KEY_TYPE_COUNT; key++)
	{
		// 키가 눌려있나?
		if (asciiKeys[key] & 0x80)
		{
			KeyState& state = _states[key];

			if (state == KeyState::Press || state == KeyState::Down)
				state = KeyState::Press;
			else
				state = KeyState::Down;
		}
		// 키를 떼고있는 상태
		else
		{
			KeyState& state = _states[key];

			// 이전 프레임에 키를 누른 상태라면 Up
			if (state == KeyState::Press || state == KeyState::Down)
				state = KeyState::Up;
			else
				state = KeyState::None;

		}
	}

	// Mouse
	::GetCursorPos(&_mousePos); // 커서의 좌표를 알아온다.
	::ScreenToClient(_hwnd, &_mousePos); // 우리 창 기준으로의 마우스 좌표로 바꿔준다.

}
