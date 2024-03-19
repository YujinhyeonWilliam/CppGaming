#include <iostream>
using namespace std;

int main()
{
	int N;
	std::cin >> N;

	int halfN = N / 2;

	for (int i = 0; i < N; i+=2)
	{
		if(i < N-1)
			cout << " ";

		for (int j = 0; j < halfN+i; j++)
		{
			if (j < halfN)
				cout << " ";
			else
				cout << "*";
		}
		cout << endl;
	}

	// if(n==3)  halfN  = 1 
	// 0*    1 (i0)
	// ***     (i2)

	// if(n==5)  halfN = 2
	// 00*   2 (i0)
	// 0***    (i2)
	// *****   (i4)

	// if(n==7)  halfN = 3
	// 000*  3 (i0)
	// 00***   (i2)
	// 0*****  (i4)
	// ******* (i6)

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