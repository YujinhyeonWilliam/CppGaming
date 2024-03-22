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

int main()
{
	for(int i=0; i<5; i++)
		GET_USER_MANAGER->AddUser();

	cout << GET_USER_MANAGER->GetUserCount() << endl;

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
		// �Է�
		HandleKeyInput();

		// ���
		HandleMove();

		// ����
		PrintMap2D();
	}
}

*/