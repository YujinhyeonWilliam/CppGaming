#include <iostream>
#include <vector>
#include <list>
#include <queue>
#include <map>
#include <unordered_map>
using namespace std;

enum class ObjectType
{
	Player,
	Monster,
	Projectile,
	Env,
	NONE
};


class Object
{
public:
	Object(ObjectType type) : _id(0), _type(type) {}
	Object(int id) : _id(id), _type(ObjectType::NONE) {}
	Object(int id, ObjectType type) : _id(id), _type(type) {}
	virtual ~Object() {}
	int GetID() const { return _id; }
	virtual void Update() = 0;
protected:
	int _id;
	ObjectType _type;
};

class Player : public Object
{
public:
	Player(ObjectType type) : Object(0){}
	Player(int id) : Object(id) {}
	Player(int id, ObjectType type) : Object(id, type) {}

	virtual void Update() override
	{

	}
	virtual ~Player() override
	{

	}
};

class Monster : public Object
{
public:
	Monster(ObjectType type) : Object(0) {}
	Monster(int id) : Object(id) {}
	Monster(int id, ObjectType type) : Object(id, type) {}

	virtual void Update() override
	{

	}

	virtual ~Monster() override
	{

	}
};


class Projectile : public Object
{
public:
	Projectile(ObjectType type) : Object(0) {}
	Projectile(int id) : Object(id) {}
	Projectile(int id, ObjectType type) : Object(id, type) {}

	virtual void Update() override
	{

	}

	virtual ~Projectile() override
	{

	}
};


class EnV : public Object
{
public:
	EnV(ObjectType type) : Object(0) {}
	EnV(int id) : Object(id) {}
	EnV(int id, ObjectType type) : Object(id, type) {}

	virtual void Update() override
	{

	}

	virtual ~EnV() override
	{

	}
};

class Field
{
public:
	static Field* GetInstance()
	{
		static Field field;
		return &field;
	}

	void Add(Object* player)
	{
		_objects.insert(make_pair(player->GetID(), player));
	}

	void Remove(int id)
	{
		_objects.erase(id);
	}

	void Update() 
	{
		for (auto& item : _objects)
		{
			item.second->Update();
		}
	}

	Object* Get(int id)
	{
		auto findIt = _objects.find(id);
		if (findIt != _objects.end())
			return findIt->second;

		return nullptr;
	}

private:
	unordered_map<int, Object*> _objects;

};

int main()
{
	Field::GetInstance()->Add(new Player(1));
	Player* player = dynamic_cast<Player*>(Field::GetInstance()->Get(1));
}