#pragma once
#include "Collider.h"

class SphereCollider : public Collider
{
	using Super = Collider;

public:
	SphereCollider();
	virtual ~SphereCollider() override;

	virtual void BeginPlay() override;
	virtual void TickComponent() override;
	virtual void Render(HDC hdc) override;

	virtual bool CheckCollision(Collider* other);
	void		 SetRadius(float radius) { _radius = radius; }
	float		 GetRadius() { return _radius; }
private:
	float _radius = 0.f;
};

