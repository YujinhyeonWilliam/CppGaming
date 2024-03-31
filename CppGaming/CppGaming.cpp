#include <iostream>
#include <vector>
#include <list>
#include <queue>
#include <map>
#include <unordered_map>
#include <algorithm>
#include <windows.h>
using namespace std;

int N = 9;
int cache[100];

// [+num]���� �����ؼ�, [+N]���� ���� ����� ��
int Enchant(int num)
{
	// ���� ���
	if (num > N)
		return 0;
	if (num == N)
		return 1;

	// ĳ��
	int& ret = cache[num];
	if (ret != -1)
		return ret;

	// ����
	return ret = Enchant(num + 1) + Enchant(num + 2) + Enchant(num + 3);
}

int main()
{
	memset(cache, -1, sizeof(cache));
	int ret = Enchant(0);
	cout << ret << endl;
}
