#include <iostream>
using namespace std;

void Test(int a)
{
	char b;
	int acd;
	float asff;
	unsigned long long bvv;
	return;
}

int main()
{
	Test(1);
}


/* Pyramid Downward

	int N;
	std::cin >> N;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N - i; j++)
		{
			if (j < i)
				cout << " ";
			else
				cout << "*";
		}
		cout << endl;
	}

*/

/* Pyramid Upwards

	int N;
	std::cin >> N;

	int halfN = N / 2;

	for (int i = 0; i < N; i+=2)
	{
		int halfI = i / 2;

		for (int j = 0; j <= halfN + halfI; j++)
		{
			if (j + halfI < halfN)
				cout << " ";
			else
				cout << "*";
		}
		cout << endl;
	}

*/