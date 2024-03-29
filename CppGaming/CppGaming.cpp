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
	setlocale(LC_ALL, "");
	cout << " LC_ALL, " << setlocale(LC_ALL, NULL) << endl;

	// CP949
	const char* test = "aa������";
	cout << test << endl;

	// UTF-8
	auto test2 = u8"aa�������Դϴ�.";
	setlocale(LC_ALL, "en_US.UTF-8");
	cout << test2 << endl;
	setlocale(LC_ALL, "");

	// UTF-16
	auto test3 = L"aa�������Դϴ�.";
	wchar_t ch = L'��';
	wstring name = L"aaa������ �Դϴ�.";
	wcout << name << endl;

}