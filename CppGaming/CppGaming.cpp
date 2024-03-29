#include <iostream>
#include <vector>
#include <list>
#include <queue>
#include <map>
#include <unordered_map>
#include <algorithm>
using namespace std;


int main()
{
	vector<int> v{ 1, 4, 3, 5, 8, 2 };

	for (auto it = v.begin(); it != v.end(); )
	{
		if (*it % 2 != 0)
			it = v.erase(it);
		else
			it++;
	}
	
	struct IsOdd
	{
		bool operator()(int n)
		{
			return n % 2 != 0;
		}
	};

	auto it = std::remove_if(v.begin(), v.end(), IsOdd());
	v.erase(it, v.end());


}