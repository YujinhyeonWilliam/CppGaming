#include "pch.h"
#include "SpriteActor.h"
#include "Sprite.h"

SpriteActor::SpriteActor()
{
}

SpriteActor::~SpriteActor()
{
}

void SpriteActor::BeginPlay()
{
	Super::BeginPlay();
}

void SpriteActor::Tick()
{
	Super::Tick();
}

void SpriteActor::Render(HDC hdc)
{
	Super::Render(hdc);

	if (_sprite == nullptr)
		return;

	Vector2DInt size = _sprite->GetSize();

	::BitBlt(hdc,
		// Destination
		(int32)_pos.x - size.x/2,
		(int32)_pos.y - size.y/2,
		size.x,
		size.y,
		// Soruce
		_sprite->GetDC(),
		_sprite->GetPos().x,
		_sprite->GetPos().y,
		SRCCOPY);
}
