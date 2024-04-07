#pragma once
#include "Collider.h"
class BoxCollider : public Collider
{
	using Super = Collider;
public:
	BoxCollider();
	virtual ~BoxCollider() override;

	virtual void BeginPlay() override;
	virtual void TickComponent() override;
	virtual void Render(HDC hdc) override;

	virtual bool CheckCollision(Collider* other);

	Vector2D GetSize() { return _size; }
	void SetSize(Vector2D size) { _size = size; }

	RECT GetRect();
private:
	Vector2D _size = {};

};

