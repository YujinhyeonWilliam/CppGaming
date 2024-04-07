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
#include "UI.h"
#include "TilemapActor.h"
#include "Tilemap.h"

DevScene::DevScene()
{

}

DevScene::~DevScene()
{
	Clear();
}

void DevScene::Init()
{
	ResourceManager* resourceManager = GET_SINGLE(ResourceManager);
	resourceManager->LoadTexture(L"Stage01", L"Sprite\\Map\\Stage01.bmp");
	resourceManager->LoadTexture(L"Tile", L"Sprite\\Map\\Tile.bmp", RGB(128, 128, 128));
	resourceManager->LoadTexture(L"Sword", L"Sprite\\Item\\Sword.bmp");
	resourceManager->LoadTexture(L"Potion", L"Sprite\\UI\\Mp.bmp");
	resourceManager->LoadTexture(L"PlayerDown", L"Sprite\\Player\\PlayerDown.bmp", RGB(128, 128, 128));
	resourceManager->LoadTexture(L"PlayerUp", L"Sprite\\Player\\PlayerUp.bmp", RGB(128, 128, 128));
	resourceManager->LoadTexture(L"PlayerLeft", L"Sprite\\Player\\PlayerLeft.bmp", RGB(128, 128, 128));
	resourceManager->LoadTexture(L"PlayerRight", L"Sprite\\Player\\PlayerRight.bmp", RGB(128, 128, 128));
	resourceManager->LoadTexture(L"Start", L"Sprite\\UI\\Start.bmp");
	resourceManager->LoadTexture(L"Edit", L"Sprite\\UI\\Edit.bmp");
	resourceManager->LoadTexture(L"Exit", L"Sprite\\UI\\Exit.bmp");

	resourceManager->CreateSprite(L"Stage01",	resourceManager->GetTexture(L"Stage01"));
	resourceManager->CreateSprite(L"TileO",	resourceManager->GetTexture(L"Tile"), 0, 0, 48, 48);
	resourceManager->CreateSprite(L"TileX",	resourceManager->GetTexture(L"Tile"), 48, 0, 48, 48);

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
		player->SetPos({ 100, 100 });

		// BoxCollider* collider = new BoxCollider();
		// collider->SetSize({ 100, 100 });
		// GET_SINGLE(CollisionManager)->AddCollider(collider);
		// player->AddComponent(collider);

		AddActor(player);
	}

	//{
	//	Actor* test = new Actor();
	//	test->SetLayer(LAYER_OBJECT);
	//	test->SetPos({ 1000, 200 });

	//	BoxCollider* collider = new BoxCollider();
	//	collider->SetSize({100, 100});
	//	GET_SINGLE(CollisionManager)->AddCollider(collider);
	//	test->AddComponent(collider);
	//	
	//	AddActor(test);
	//}


	{
		TilemapActor* actor = new TilemapActor();
		AddActor(actor);
		_tilemapActor = actor;

		{
			auto* tm = GET_SINGLE(ResourceManager)->CreateTilemap(L"Tilemap_01");
			tm->SetMapSize({ 63, 43 });
			tm->SetTileSize(48);

			_tilemapActor->SetTilemap(tm);
			_tilemapActor->SetShowDebug(true);
		}

	}

	for (const vector<Actor*>& actors : _actors)
		for (Actor* actor : actors)
			actor->BeginPlay();

	for (UI* ui : _uis)
		ui->BeginPlay();

	Super::Init();
}

void DevScene::Update()
{
	Super::Update();

	//float deltaTime = GET_SINGLE(TimeManager)->GetDeltaTime();
	if (GET_SINGLE(InputManager)->GetButtonDown(KeyType::Q))
	{
		GET_SINGLE(ResourceManager)->SaveTilemap(L"Tilemap_01", L"Tilemap\\Tilemap01.txt");
	}
	else if (GET_SINGLE(InputManager)->GetButtonDown(KeyType::E))
	{
		GET_SINGLE(ResourceManager)->LoadTilemap(L"Tilemap_01", L"Tilemap\\Tilemap01.txt");
	}
}

void DevScene::Render(HDC hdc)
{
	Super::Render(hdc);

}

void DevScene::Clear()
{
	for (const vector<Actor*> actors : _actors)
		for (Actor* actor : actors)
			SAFE_DELETE(actor);

	for (vector<Actor*> actors : _actors)
		actors.clear();

	for (UI* ui : _uis)
		SAFE_DELETE(ui);

	_uis.clear();
}

