#include "pch.h"
#include "Scene.h"
#include "Actor.h"
#include "TimeManager.h"
#include "CollisionManager.h"
#include "UI.h"

Scene::Scene()
{
}

Scene::~Scene()
{
}

void Scene::Init()
{
}

void Scene::Update()
{
	float deltaTime = GET_SINGLE(TimeManager)->GetDeltaTime();

	GET_SINGLE(CollisionManager)->Update();

	for (const vector<Actor*>& actors : _actors)
		for (Actor* actor : actors)
			actor->Tick();

	for (UI* ui : _uis)
		ui->Tick();
}

void Scene::Render(HDC hdc)
{
	for (const vector<Actor*>& actors : _actors)
		for (Actor* actor : actors)
			actor->Render(hdc);

	for (UI* ui : _uis)
		ui->Render(hdc);
}

void Scene::AddActor(Actor* actor)
{
	if (actor == nullptr)
		return;

	_actors[actor->GetLayer()].push_back(actor);
}

void Scene::RemovActor(Actor* actor)
{
	if (actor == nullptr)
		return;

	vector<Actor*>& v = _actors[actor->GetLayer()];
	v.erase(std::remove(v.begin(), v.end(), actor), v.end());
}
