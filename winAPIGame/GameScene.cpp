#include "pch.h"
#include "GameScene.h"
#include "Player.h"
#include "ObjectManager.h"

GameScene::GameScene()
{
}

GameScene::~GameScene()
{
}

void GameScene::Init()
{
	{
		ObjectManager* objManager = GET_SINGLE(ObjectManager);
		Player* player = objManager->CreateObject<Player>();
		player->SetPos(Pos{ 400, 400 });
		objManager->Add(player);
	}
}

void GameScene::Update()
{
	const vector<Object*>& objects = GET_SINGLE(ObjectManager)->GetObjects();
	for (Object* object : objects)
	{
		object->Update();
	}
}

void GameScene::Render(HDC hdc)
{
	const vector<Object*>& objects = GET_SINGLE(ObjectManager)->GetObjects();
	for (Object* object : objects)
	{
		object->Render(hdc);
	}
}
