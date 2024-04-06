#pragma once
#include "ResourceBase.h"

class Texture;
class Sprite :public ResourceBase
{
public:
	Sprite(Texture* texture, int32 x, int32 y, int32 cx, int32 cy);
	virtual ~Sprite();

	HDC GetDC();
	int32 GetTransparent();
	Vector2DInt GetPos() {return Vector2DInt {_x, _y}; }
	Vector2DInt GetSize() { return Vector2DInt{ _cx, _cy }; }

private:
	Texture* _texture = nullptr;
	int32 _x;
	int32 _y;
	int32 _cx;
	int32 _cy;
};

