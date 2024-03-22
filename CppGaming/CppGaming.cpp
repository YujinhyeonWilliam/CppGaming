#include <iostream>
using namespace std;

int StrLen(const char* str)
{
	int count = 0;

	while (str[count] != '\0')
	{
		count++;
	}

	return count;
}

char* StrCpy(char* dest, char* src)
{
	char* ret = dest;

	while (*src != '\0')
	{
		*dest = *src;
		dest++;
		src++;
	}

	*dest = 0;
	return ret;
}

char* StrCat(char* lhs, char* rhs)
{
	/*int len = StrLen(lhs);

	int i = 0;
	while (rhs[i] != 0)
	{
		lhs[len + i] = rhs[i];
		i++;
	}

	lhs[len + i] = 0;*/

	char* ret = lhs;

	while (*lhs != 0)
		lhs++;

	while (*rhs != 0)
	{
		*lhs = *rhs;
		lhs++;
		rhs++;
	}

	return ret;
}

int main()
{
	const int BUF_SIZE = 100;

	char aStr[BUF_SIZE] = "Hello";
	char bStr[BUF_SIZE] = "World";

	int len = StrLen(aStr);
	cout << len << endl;

#pragma warning(disable:4996)
	char c[BUF_SIZE];
	StrCpy(c, aStr);
	cout << c << endl;


	cout << StrCat(aStr, bStr) << endl;
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