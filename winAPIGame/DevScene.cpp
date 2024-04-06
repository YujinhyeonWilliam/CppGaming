#include "pch.h"
#include "DevScene.h"
#include "Utils.h"
#include "InputManager.h"
#include "TimeManager.h"
#include "ResourceManager.h"
#include "Texture.h"
#include "Sprite.h"
#include "Actor.h"
#include "SpriteActor.h"
#include "Player.h"
#include "Flipbook.h"
#include "BoxCollider.h"
#include "SphereCollider.h"
#include "CollisionManager.h"

DevScene::DevScene()
{

}

DevScene::~DevScene()
{

}

void DevScene::Init()
{
	ResourceManager* resourceManager = GET_SINGLE(ResourceManager);
	resourceManager->LoadTexture(L"Stage01", L"Sprite\\Map\\Stage01.bmp");
	resourceManager->LoadTexture(L"Sword", L"Sprite\\Item\\Sword.bmp");
	resourceManager->LoadTexture(L"Potion", L"Sprite\\UI\\Mp.bmp");
	resourceManager->LoadTexture(L"PlayerDown", L"Sprite\\Player\\PlayerDown.bmp", RGB(128, 128, 128));
	resourceManager->LoadTexture(L"PlayerUp", L"Sprite\\Player\\PlayerUp.bmp", RGB(128, 128, 128));
	resourceManager->LoadTexture(L"PlayerLeft", L"Sprite\\Player\\PlayerLeft.bmp", RGB(128, 128, 128));
	resourceManager->LoadTexture(L"PlayerRight", L"Sprite\\Player\\PlayerRight.bmp", RGB(128, 128, 128));
	resourceManager->LoadTexture(L"Start", L"Sprite\\UI\\Start.bmp");
	resourceManager->LoadTexture(L"Edit", L"Sprite\\UI\\Edit.bmp");
	resourceManager->LoadTexture(L"Exit", L"Sprite\\UI\\Exit.bmp");

	Texture* tex = resourceManager->GetTexture(L"Start");
	resourceManager->CreateSprite(L"Stage01",	resourceManager->GetTexture(L"Stage01"));
	resourceManager->CreateSprite(L"Start_Off", resourceManager->GetTexture(L"Start"), 0, 0, 150, 150);
	resourceManager->CreateSprite(L"Start_On",	resourceManager->GetTexture(L"Start"), 150, 0, 150, 150);
	resourceManager->CreateSprite(L"Edit_Off",	resourceManager->GetTexture(L"Edit"), 0, 0, 150, 150);
	resourceManager->CreateSprite(L"Edit_On",	resourceManager->GetTexture(L"Edit"), 150, 0, 150, 150);
	resourceManager->CreateSprite(L"Exit_Off",	resourceManager->GetTexture(L"Exit"), 0, 0, 150, 150);
	resourceManager->CreateSprite(L"Exit_On",	resourceManager->GetTexture(L"Exit"), 150, 0, 150, 150);

	// Player Up Flipbook
	{
		Texture* texture = GET_SINGLE(ResourceManager)->GetTexture(L"PlayerUp");
		Flipbook* fb = GET_SINGLE(ResourceManager)->CreateFlipBook(L"FB_MoveUp");
		fb->SetInfo(
			FlipBookInfo
			{
				texture,
				L"FB_MoveUp",
				{200, 200},
				0,
				9,
				1,
				0.5f
			});
	}

	// Player Down Flipbook
	{
		Texture* texture = GET_SINGLE(ResourceManager)->GetTexture(L"PlayerDown");
		Flipbook* fb = GET_SINGLE(ResourceManager)->CreateFlipBook(L"FB_MoveDown");
		fb->SetInfo(
			FlipBookInfo
			{
				texture,
				L"FB_MoveDown",
				{200, 200},
				0,
				9,
				1,
				0.5f
			});
	}

	// Player Left Flipbook
	{
		Texture* texture = GET_SINGLE(ResourceManager)->GetTexture(L"PlayerLeft");
		Flipbook* fb = GET_SINGLE(ResourceManager)->CreateFlipBook(L"FB_MoveLeft");
		fb->SetInfo(
			FlipBookInfo
			{
				texture,
				L"FB_MoveLeft",
				{200, 200},
				0,
				9,
				1,
				0.5f
			});
	}

	// Player Right Flipbook
	{
		Texture* texture = GET_SINGLE(ResourceManager)->GetTexture(L"PlayerRight");
		Flipbook* fb = GET_SINGLE(ResourceManager)->CreateFlipBook(L"FB_MoveRight");
		fb->SetInfo(
			FlipBookInfo
			{
				texture,
				L"FB_MoveRight",
				{200, 200},
				0,
				9,
				1,
				0.5f
			});
	}

	{
		Sprite* sprite = resourceManager->GetSprite(L"Stage01");
		SpriteActor* background = new SpriteActor();
		background->SetSprite(sprite);
		background->SetLayer(LAYER_BACKGROUND);

		const Vector2DInt size = sprite->GetSize();
		background->SetPos(Vector2D(size.x/2, size.y/2));
		AddActor(background);
	}

	{
		Player* player = new Player();
		{
			SphereCollider* collider = new SphereCollider();
			collider->SetRadius(100);
			player->AddComponent(collider);
			GET_SINGLE(CollisionManager)->AddCollider(collider);
		}
		AddActor(player);
	}


	{
		Actor* player = new Actor();
		{
			SphereCollider* collider = new SphereCollider();
			collider->SetRadius(50);
			player->AddComponent(collider);
			GET_SINGLE(CollisionManager)->AddCollider(collider);
			player->SetPos({ 400, 200 });
		}
		AddActor(player);
	}

	for (const vector<Actor*>& actors : _actors)
		for (Actor* actor : actors)
			actor->BeginPlay();
}

void DevScene::Update()
{
	float deltaTime = GET_SINGLE(TimeManager)->GetDeltaTime();

	GET_SINGLE(CollisionManager)->Update();

	for(const vector<Actor*>& actors : _actors)
		for (Actor* actor : actors)
			 actor->Tick();

}

void DevScene::Render(HDC hdc)
{
	for (const vector<Actor*>& actors : _actors)
		for (Actor* actor : actors)
			 actor->Render(hdc);
}

void DevScene::AddActor(Actor* actor)
{
	if (actor == nullptr)
		return;

	_actors[actor->GetLayer()].push_back(actor);
}

void DevScene::RemovActor(Actor* actor)
{
	if (actor == nullptr)
		return;

	vector<Actor*>& v = _actors[actor->GetLayer()];
	v.erase(std::remove(v.begin(), v.end(), actor), v.end());
}
