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
	const char* test = "aa유진현";
	cout << test << endl;

	// UTF-8
	auto test2 = u8"aa유진현입니다.";
	setlocale(LC_ALL, "en_US.UTF-8");
	cout << test2 << endl;
	setlocale(LC_ALL, "");

	// UTF-16
	auto test3 = L"aa유진현입니다.";
	wchar_t ch = L'유';
	wstring name = L"aaa유진현 입니다.";
	wcout << name << endl;

}