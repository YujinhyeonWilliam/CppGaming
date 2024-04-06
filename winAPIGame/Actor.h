#pragma once
class Actor
{
public:
	Actor();
	virtual ~Actor();

	virtual void	BeginPlay();
	virtual void	Tick();
	virtual void	Render(HDC hdc);

	void			SetPos(Vector2DInt pos) { _pos = pos; }
	Vector2DInt		GetPos() { return _pos; }

protected:
	Vector2DInt		_pos = { 0, 0 };
};

