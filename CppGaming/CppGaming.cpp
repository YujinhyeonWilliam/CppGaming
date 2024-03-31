#include <iostream>
#include <vector>
#include <list>
#include <queue>
#include <map>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Knight
{
public:
	
	~Knight()
	{
		cout << " Knight 소멸" << endl;
	}

	void Attack()
	{
		if (_target)
			_target->_hp -= _damage;
	}

	int _hp = 0;
	int _damage = 100;
	shared_ptr<Knight> _target = nullptr;
};


template<typename T>
class Wrapper
{
public:

	Wrapper(T* ptr) : _ptr(ptr) {}
	~Wrapper()
	{
		if (_ptr != nullptr)
		{
			delete _ptr;
			_ptr = nullptr;
		}

		cout << " Wrapper 클래스 소멸자. 메모리 해제 완료? = " << (_ptr == nullptr ? "true" : "false") << endl;
	}

public:
	T* _ptr;
};

class RefCountBlock
{
public:
	int _refCount = 1;
};

template<typename T>
class SharedPtr
{
public:
	SharedPtr(){}
	SharedPtr(T* ptr) : _ptr(ptr) 
	{
		if (ptr)
		{
			_block = new ReCountBlock();
			cout << " RefCount: " << _block->_refCount << endl;
		}
	}

	SharedPtr(const SharedPtr& other) : _ptr(other._ptr), _block(other._block)
	{
		if (_ptr)
		{
			_block->_refCount++;
		}
	}

	void operator=(const SharedPtr& other)
	{
		_ptr = other._ptr;
		_block = other._block;

		if (_ptr)
			_block->_refCount++;
	}

	~SharedPtr()
	{
		if (_ptr)
		{
			_block->_refCount--;

			if (_block->_refCount == 0)
			{
				delete _ptr;
				delete _block;
				cout << "Delete Data" << endl;
			}
		}
	}

public:
	T* _ptr = nullptr;
	RefCountBlock* _block = nullptr;
};


int main()
{
	shared_ptr<Knight> k1(new Knight());
	shared_ptr<Knight> k2(new Knight());
	k1->_target = k2;
}
