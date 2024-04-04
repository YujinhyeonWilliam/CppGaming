#include "pch.h"
#include "GameScene.h"
#include "Player.h"
#include "Monster.h"
#include "ObjectManager.h"

GameScene::GameScene()
{
}

GameScene::~GameScene()
{
}

void GameScene::Init()
{
	// // Create Player 
	// { 
	// 	ObjectManager* objManager = GET_SINGLE(ObjectManager);
	// 	Player* player = objManager->CreateObject<Player>();
	// 	player->SetPos(Pos{ 400, 400 });
	// 	objManager->Add(player);
	// }

	// Create Monster
	{
	  
	  ObjectManager* objManager = GET_SINGLE(ObjectManager);
	  Monster* monster = objManager->CreateObject<Monster>();
	  monster->SetPos(Pos{400, 400});
	  objManager->Add(monster);
	  
	}
}

void GameScene::Update()
{
	const vector<Object*> objects = GET_SINGLE(ObjectManager)->GetObjects();
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
