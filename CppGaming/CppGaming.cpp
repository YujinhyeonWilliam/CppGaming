#include <iostream>
using namespace std;

int main()
{
	int N;
	std::cin >> N;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (j < i)
				cout << " ";
			else
				cout << "*";
		}
		cout << endl;
	}
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