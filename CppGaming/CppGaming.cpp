#include <iostream>
#include <vector>
#include <list>
#include <queue>
#include <map>
#include <unordered_map>
#include <algorithm>
using namespace std;

template<typename T>
class SharedPtr
{
public:
	SharedPtr(T* ptr) : _ptr(ptr) {}

public:
	T* _ptr;
	int _refCount = 1;
};

class Knight
{
public:
	Knight(){}
	Knight(int id) : _id(id){}
	~Knight()
	{
		cout << " Knight ¼Ò¸ê" << endl;
	}

	void Attack()
	{
		if (!_target.expired())
		{
			shared_ptr<Knight> spr = _target.lock();
			spr->_hp -= _damage;
		}
	}
	int _id = 0;
	int _hp = 0;
	int _damage = 100;
	weak_ptr<Knight> _target;
};

int main()
{
	shared_ptr<Knight> k1 = make_shared<Knight>(1);
	shared_ptr<Knight> k2 = make_shared<Knight>(2);
	k1->_target = k2;
	k2->_target = k1;

	// unique_ptr
	unique_ptr<Knight> k3(new Knight());
	unique_ptr<Knight> k4 = k3;

}
