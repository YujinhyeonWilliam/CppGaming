#include "pch.h"
#include "Collider.h"
#include "SphereCollider.h"
#include "BoxCollider.h"
#include "Actor.h"

Collider::Collider(ColliderType colliderType) : _colliderType(colliderType)
{

}

Collider::~Collider()
{
}

void Collider::BeginPlay()
{
}

void Collider::TickComponent()
{
}

void Collider::Render(HDC hdc)
{
}

bool Collider::CheckCollision(Collider* other)
{
	return false;
}

bool Collider::CheckCollisionBox2Box(BoxCollider* b1, BoxCollider* b2)
{
	Vector2D p1 = b1->GetOwner()->GetPos();
	Vector2D s1 = b1->GetSize();

	Vector2D p2 = b2->GetOwner()->GetPos();
	Vector2D s2 = b2->GetSize();

	float minX_1 = p1.x - s1.x / 2;
	float maxX_1 = p1.x + s1.x / 2;
	float minY_1 = p1.y - s1.y / 2;
	float maxY_1 = p1.y + s1.y / 2;

	float minX_2 = p2.x - s2.x / 2;
	float maxX_2 = p2.x + s2.x / 2;
	float minY_2 = p2.y - s2.y / 2;
	float maxY_2 = p2.y + s2.y / 2;

	if (maxX_2 < minX_1)
		return false;

	if (maxX_1 < minX_2)
		return false;

	if (maxY_1 < minY_2)
		return false;

	if (maxY_2 < minY_1)
		return false;

	return true;
}

bool Collider::CheckCollisionSphere2Box(SphereCollider* s1, BoxCollider* b2)
{
	return false;
}

bool Collider::CheckCollisionSphere2Sphere(SphereCollider* s1, SphereCollider* s2)
{
	Vector2D p1 = s1->GetOwner()->GetPos();
	float r1 = s1->GetRadius();

	Vector2D p2 = s2->GetOwner()->GetPos();
	float r2 = s2->GetRadius();

	Vector2D dir = p1 - p2;
	float dist = dir.Length();

	return dist <= r1 + r2;
}
