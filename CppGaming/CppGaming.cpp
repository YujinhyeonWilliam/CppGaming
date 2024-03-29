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
	// C 스타일 문자열
	std::string str = "jinhyeon";
	std::string str2 = "jinhyeon";

	// (1) 비교
	if (str == str2)
		cout << "같음" << endl;
	else
		cout << "다름" << endl;

	// (2) 복사
	string str3;
	str3 = str;


	// (3) 추가
	str.append("12334");
	str += " 1234";

	// (4) 찾기
	auto c = str.find("yeo");
	if (c == string::npos)
	{
		cout << " 못찾음 " << endl;
	}

	// (5) 교체
	string chatStr = "Shit !!!";
	string findStr = "Shit";
	string replaceStr = "****";

	chatStr.replace(chatStr.find(findStr), findStr.length(), replaceStr);

	// (6) 자르기
	string subStr = str.substr(0, 3);

	// (7) C 스타일 변환
	const char* nameC = str.c_str();
}