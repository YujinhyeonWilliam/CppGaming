#include <iostream>
#include "Player.h"
using namespace std;

class UserManager
{
public:
	static UserManager* GetInstance()
	{
		static UserManager um;
		return &um;
	}

public:
	void AddUser() { _userCount++; }
	int GetUserCount() { return _userCount++; }
private:
	int _userCount = 0;
};

#define GET_USER_MANAGER (UserManager::GetInstance())

class Object
{

};

class IFly
{
	virtual void Fly() abstract;
	virtual void Land() abstract;
};

class Player : public Object, public IFly
{
	virtual void Fly() override {}
	virtual void Land() override {}
};

int main()
{


}


/*

#include <iostream>
using namespace std;
#include "Helper.h"
#include "Map.h"
#include "Player.h"


[Map and Player Move]

int main()
{
	SetCursorOnOff(false);

	while (true)
	{
		// 입력
		HandleKeyInput();

		// 출력
		HandleMove();

		// 로직
		PrintMap2D();
	}
}

*/