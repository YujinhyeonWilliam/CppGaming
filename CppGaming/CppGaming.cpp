#include <iostream>
#include <vector>
#include <list>
#include <queue>
#include <map>
#include <unordered_map>
#include <algorithm>
#include <windows.h>
using namespace std;

int cache[50][50];

int combination(int n, int r)
{
	// 기저 사례
	if (r == 0 || n == r)
		return 1;

	// 이미 답을 구한 적이 있으면 바로 반환
	int& ret = cache[n][r];
	if (ret != -1)
		return ret;

	return ret = combination(n - 1, r - 1) + combination(n - 1, r);
}


int main()
{
	::memset(cache, -1, sizeof(cache));

	__int64 start = ::GetTickCount64();
	int lotto = combination(45, 6);
	__int64 end = ::GetTickCount64();
	cout << "Lotto chances = " << lotto << endl;
	cout << end - start << "ms" << endl;
}
