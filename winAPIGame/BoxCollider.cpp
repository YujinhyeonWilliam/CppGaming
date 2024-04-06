#include "pch.h"
#include "BoxCollider.h"
#include "SceneManager.h"
#include "Actor.h"
#include "SphereCollider.h"

BoxCollider::BoxCollider() : Collider(ColliderType::Box)
{

}

BoxCollider::~BoxCollider()
{
}

void BoxCollider::BeginPlay()
{
	Super::BeginPlay();
}

void BoxCollider::TickComponent()
{
	Super::TickComponent();
}

void BoxCollider::Render(HDC hdc)
{
	Super::Render(hdc);

	if (_showDebug == false)
		return;

	Vector2D pos = GetOwner()->GetPos();
	Vector2D cameraPos = GET_SINGLE(SceneManager)->GetCameraPos();

	pos.x -= (cameraPos.x - GWinSizeX / 2);
	pos.y -= (cameraPos.y - GWinSizeY / 2);

	HBRUSH myBrush = (HBRUSH)::GetStockObject(NULL_BRUSH);
	HBRUSH oldBrush = (HBRUSH)::SelectObject(hdc, myBrush);
	Utils::DrawRect(hdc, pos, _size.x, _size.y);
	::SelectObject(hdc, oldBrush);
	::DeleteObject(myBrush);
}

bool BoxCollider::CheckCollision(Collider* other)
{
	switch (other->GetColliderType())
	{
		case ColliderType::Box:		return CheckCollisionBox2Box(this, static_cast<BoxCollider*>(other));
		case ColliderType::Sphere:  return CheckCollisionSphere2Box(static_cast<SphereCollider*>(other), this);
	}
	return false;
}
