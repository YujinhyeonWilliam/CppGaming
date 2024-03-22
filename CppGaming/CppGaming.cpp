#include <iostream>
using namespace std;

// 로또 번호 생성기
void Swap(int& a, int& b)
{
	int temp = a;
	a = b;
	b = temp;
}

void BubbleSort(int* numbers, int length)
{
	for (int i = 0; i < length; i++)
	{
		for (int j = 0; j < length - 1 - i; j++)
		{
			if (numbers[j] > numbers[j + 1])
			{
				Swap(numbers[j], numbers[j + 1]);
			}
		}
	}
}

void ChooseLotto(int* numbers)
{
	int count = 0;

	while (count != 6)
	{
		// 1 ~ 45
		int randValue = 1 + rand() % 45;

		bool found = false;
		for (int i = 0; i < count; i++)
		{
			if (numbers[i] == randValue)
			{
				found = true;
				break;
			}
		}

		if (found == false)
		{
 		   numbers[count] = randValue;
  		   count++;
		}
	}

	BubbleSort(numbers, 6);
}

int main()
{
	srand((unsigned int)time(0));
	int lotto[6];
	ChooseLotto(lotto);

	for (int i = 0; i < 6; i++)
		cout << lotto[i] << endl;
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