#pragma once
class UI;
class Actor;

class Scene
{
public:
	Scene();
	virtual ~Scene();

	virtual void Init();
	virtual void Update();
	virtual void Render(HDC hdc);

	void AddActor(Actor* actor);
	void RemovActor(Actor* actor);

public:
	vector<Actor*> _actors[LAYER_TYPE::LAYER_MAXCOUNT];
	vector<UI*> _uis;
};

