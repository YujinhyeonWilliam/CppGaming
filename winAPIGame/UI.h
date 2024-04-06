#pragma once

class UI
{
public:
	UI();
	virtual ~UI();

	virtual void	BeginPlay();
	virtual void	Tick();
	virtual void	Render(HDC hdc);
	void			SetPos(Vector2D pos) { _pos = pos; }
	Vector2D		GetPos() { return _pos; }

	RECT GetRect();
	bool IsMouseInRect();

protected:
	Vector2D		_pos = { 400, 300 };
	Vector2DInt		_size = { 150, 150 };
};

