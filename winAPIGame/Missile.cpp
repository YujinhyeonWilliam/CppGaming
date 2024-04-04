#include "pch.h"
#include "Missile.h"
#include "TimeManager.h"
#include "ObjectManager.h"

Missile::Missile() : Object(ObjectType::Projectile)
{

}

Missile::~Missile()
{

}

void Missile::Init()
{
	// TODO : Data
	_stat.hp = 1;
	_stat.maxHp = 1;
	_stat.speed = 600;
}

void Missile::Update()
{
	float deltaTime = GET_SINGLE(TimeManager)->GetDeltaTime();

	//
	if (_target == nullptr)
	{
		_pos.x += _stat.speed * deltaTime * ::cos(_angle);
		_pos.y -= _stat.speed * deltaTime * ::sin(_angle);

		_sumTime += deltaTime;
		if (_sumTime >= 0.2f)
		{
			const vector<Object*> objects = GET_SINGLE(ObjectManager)->GetObjects();
			for(Object* object : objects)
				if (object->GetObjectType() == ObjectType::Monster)
				{
					_target = object;
					_sumTime = 0.f;
					break;
				}
		}
	}
	else
	{
		Vector dirVector = _target->GetPos() - GetPos();
		SetPos(_pos + dirVector.normalized() * _stat.speed * deltaTime);
	}

	// Ãæµ¹
	const vector<Object*> objects = GET_SINGLE(ObjectManager)->GetObjects();
	for (Object* object : objects)
	{
		if (object == this)
			continue;

		if (object->GetObjectType() != ObjectType::Monster)
			continue;

		Vector p1 = GetPos();
		Vector p2 = object->GetPos();

		const float dx = p1.x - p2.x;
		const float dy = p1.y - p2.y;
		float dist = (p2 - p1).LengthSquared();

		if (dist < 25)
		{
			GET_SINGLE(ObjectManager)->Remove(object);
			GET_SINGLE(ObjectManager)->Remove(this);
			return;
		}
	}

	if (_pos.y < -200)
	{
		GET_SINGLE(ObjectManager)->Remove(this);
		return;
	}
}

void Missile::Render(HDC hdc)
{
	Utils::DrawCircle(hdc, _pos, 25);
}