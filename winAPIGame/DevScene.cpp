#include "pch.h"
#include "DevScene.h"
#include "Utils.h"
#include "InputManager.h"
#include "TimeManager.h"
#include "ResourceManager.h"
#include "Texture.h"
#include "Sprite.h"

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
	resourceManager->CreateSprite(L"Start_On", tex, 150, 0, 150, 150);
}

void DevScene::Update()
{
	float deltaTime = GET_SINGLE(TimeManager)->GetDeltaTime();
}

void DevScene::Render(HDC hdc)
{
	Sprite* sprite = GET_SINGLE(ResourceManager)->GetSprite(L"Start_On");

	::BitBlt(hdc,
		// Destination
		0,
		0,
		GWinSizeX,
		GWinSizeY,
		// Soruce
		sprite->GetDC(),
		sprite->GetPos().x,
		sprite->GetPos().y,
		SRCCOPY);
}
