#pragma once
#include "ResourceBase.h"

class Texture;
struct FlipBookInfo
{
	Texture* texture = nullptr;
	wstring name;
	Vector2DInt size = {};
	int32 start = 0;
	int32 end = 0;
	int32 line = 0;
	float duration = 1.f;
	bool loop = true;
};

class Flipbook : public ResourceBase
{
public:
	Flipbook();
	virtual ~Flipbook();

	void SetInfo(const FlipBookInfo& info) { _info = info; }
	const FlipBookInfo& GetInfo() { return _info; }
private:
	FlipBookInfo _info;
};