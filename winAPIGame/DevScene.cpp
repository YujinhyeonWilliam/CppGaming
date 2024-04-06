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

	{
		Sprite* sprite = resourceManager->GetSprite(L"Stage01");
		SpriteActor* background = new SpriteActor();
		background->SetSprite(sprite);

		const Vector2DInt size = sprite->GetSize();
		background->SetPos(Vector2DInt(size.x/2, size.y/2));
		_actors.push_back(background);
	}

	{
		Sprite* sprite = resourceManager->GetSprite(L"Start_On");
		Player* player = new Player();
		player->SetSprite(sprite);

		const Vector2DInt size = sprite->GetSize();
		player->SetPos(Vector2DInt(size.x / 2, size.y / 2));
		_actors.push_back(player);
	}

	for (Actor* actor : _actors)
		actor->BeginPlay();
}

void DevScene::Update()
{
	float deltaTime = GET_SINGLE(TimeManager)->GetDeltaTime();
	for (Actor* actor : _actors)
		 actor->Tick();
}

void DevScene::Render(HDC hdc)
{
	for (Actor* actor : _actors)
		 actor->Render(hdc);
}
