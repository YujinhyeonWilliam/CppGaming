#include <iostream>
using namespace std;

// Vector/List -> Tree -> Graph -> BFS -> Dijikstra -> A* (PQ)

int Factorial(int n)
{
	if (n <= 1)
		return 1;

	return n * Factorial(n - 1);
}

// 유클리드 알고리즘 [호제법]
// a > b
// GCD(1071, 1029)
// GCD(1029, 1071 % 1029 =42)
// GCD(42, 1029 = 21);
// GCD(21, 0) = 21

int GCD(int a, int b)
{
	if (b == 0)
		return a;

	return GCD(b, a % b);
}

int main()
{
	cout << " 유클리드 호제 (7123, 2629) = " << GCD(7123, 2629) << endl;
}
