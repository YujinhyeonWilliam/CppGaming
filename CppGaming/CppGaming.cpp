#include <iostream>
#include <vector>
#include <list>
#include <queue>
#include <map>
#include <unordered_map>
#include <algorithm>
using namespace std;

bool Descending(int a, int b) { return a < b; }
bool Ascending(int a, int b) { return a > b; }

template<typename T>
void BubbleSort(vector<int>& v, T predicate)
{
	int i, j;
	const int size = v.size();

	// O(n^2)
	for (i = 0; i < size - 1; i++)
	{
		for (j = 0; j < size - 1 - i; j++)
		{
			if (predicate(v[j], v[j + 1]))
			{
				swap(v[j], v[j + 1]);
			}
		}
	}

}

template<typename T>
void SelectionSort(vector<int>& v, T predicate)
{
	const int n = v.size();

	// O(n^2)
	for (int i = 0; i < n - 1; i++)
	{
		int bestIdx = i;

		for (int j = i + 1; j < n; j++)
		{
			if (predicate(v[bestIdx], v[j]))
				bestIdx = j;
		}

		if(i != bestIdx)
		   swap(v[i], v[bestIdx]);
	}
}

// 총 소요 시간 : O(2nLogn), 시간복잡도 : O(nLogn)
void HeapSort(vector<int>& v)
{
	priority_queue<int, vector<int>, greater<int>> pq;

	// O(nLogn)
	for (int num : v) // n
		pq.push(num); // logN

	v.clear();

	// O(nLogn)
	while (pq.empty() == false)
	{
		v.push_back(pq.top()); // O(1)
		pq.pop(); // O(logN)
	}
}

int main()
{
	vector<int> v{ 1, 5, 3, 4, 2 };

	//std::sort(v.begin(), v.end());
	// BubbleSort(v, Descending);
	// SelectionSort(v, Ascending);
	// HeapSort(v);
}