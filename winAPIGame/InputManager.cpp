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
		// Ű�� �����ֳ�?
		if (asciiKeys[key] & 0x80)
		{
			KeyState& state = _states[key];

			if (state == KeyState::Press || state == KeyState::Down)
				state = KeyState::Press;
			else
				state = KeyState::Down;
		}
		// Ű�� �����ִ� ����
		else
		{
			KeyState& state = _states[key];

			// ���� �����ӿ� Ű�� ���� ���¶�� Up
			if (state == KeyState::Press || state == KeyState::Down)
				state = KeyState::Up;
			else
				state = KeyState::None;

		}
	}

	// Mouse
	::GetCursorPos(&_mousePos); // Ŀ���� ��ǥ�� �˾ƿ´�.
	::ScreenToClient(_hwnd, &_mousePos); // �츮 â ���������� ���콺 ��ǥ�� �ٲ��ش�.

}
