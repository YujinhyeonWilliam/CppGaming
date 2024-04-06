#pragma once

class Component;
class Collider;

class Actor
{
public:
	Actor();
	virtual ~Actor();

	virtual void	BeginPlay();
	virtual void	Tick();
	virtual void	Render(HDC hdc);

	void			SetPos(Vector2D pos) { _pos = pos; }
	Vector2D		GetPos() { return _pos; }
	void			AddComponent(Component* component);
	void			RemoveComponent(Component* component);

	void			SetLayer(LAYER_TYPE layer) { _layer = layer; }
	LAYER_TYPE		GetLayer() { return _layer; }

	virtual void OnComponentBeginOverlap(Collider* collider, Collider* other);
	virtual void OnComponentEndOverlap(Collider* collider, Collider* other);

protected:
	Vector2D		_pos = { 0, 0 };
	vector<Component*> _components;
	LAYER_TYPE _layer = LAYER_TYPE::LAYER_OBJECT;
};

