#include <iostream>
using namespace std;
#include <vector>
#include <list>
#include <queue>

vector<int> numbers;
// O(logN)
void BinarySearch(int N)
{
	int left = 0;
	int right = numbers.size() - 1;

	while (left <= right)
	{
		cout << " Ž�� ���� : " << left << "~" << right << endl;
		int mid = (left + right) / 2;
		if (N < numbers[mid])
		{
			cout << N << "<" << numbers[mid] << endl;
			right = mid - 1;
		}
		else if (N > numbers[mid])
		{
			cout << N << ">" << numbers[mid] << endl;
			left = mid + 1;
		}
		else
		{
			cout << "ã����!" << endl;
			break;
		}
	}
}

int main()
{
	numbers = { 1, 8, 15, 23, 32, 44, 56, 63, 81, 91 };
	BinarySearch(44);
}