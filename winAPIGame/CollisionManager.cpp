#include "pch.h"
#include "CollisionManager.h"
#include "Collider.h"
#include "Actor.h"

void CollisionManager::Init()
{

}

void CollisionManager::Update()
{
	vector<Collider*>& colliders = _colliders;

	int32 size = colliders.size();
	for (int32 i = 0; i < size; i++)
	{
		unordered_set<Collider*>& collisionMap = colliders[i]->GetCollisionMap();

		for (int32 j = i + 1; j < size; j++)
		{
			Collider* src = colliders[i];
			Collider* dest = colliders[j];

			if (src->CheckCollision(dest))
			{
				// TODO
				if (collisionMap.contains(dest) == false)
				{
					src->GetOwner()->OnComponentBeginOverlap(src, dest);
					dest->GetOwner()->OnComponentBeginOverlap(dest, src);
					collisionMap.insert(dest);
					dest->GetCollisionMap().insert(src);
				}
			}
			else
			{
				if (collisionMap.contains(dest))
				{
					src->GetOwner()->OnComponentEndOverlap(src, dest);
					dest->GetOwner()->OnComponentEndOverlap(dest, src);
					collisionMap.erase(dest);
					dest->GetCollisionMap().erase(src);
				}
			}
		}
	}
}

void CollisionManager::AddCollider(Collider* collider)
{
	_colliders.push_back(collider);
}

void CollisionManager::RemoveCollider(Collider* collider)
{
	auto it = std::remove(_colliders.begin(), _colliders.end(), collider);
	_colliders.erase(it, _colliders.end());
}
