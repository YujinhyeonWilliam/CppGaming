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
	// C ��Ÿ�� ���ڿ�
	std::string str = "jinhyeon";
	std::string str2 = "jinhyeon";

	// (1) ��
	if (str == str2)
		cout << "����" << endl;
	else
		cout << "�ٸ�" << endl;

	// (2) ����
	string str3;
	str3 = str;


	// (3) �߰�
	str.append("12334");
	str += " 1234";

	// (4) ã��
	auto c = str.find("yeo");
	if (c == string::npos)
	{
		cout << " ��ã�� " << endl;
	}

	// (5) ��ü
	string chatStr = "Shit !!!";
	string findStr = "Shit";
	string replaceStr = "****";

	chatStr.replace(chatStr.find(findStr), findStr.length(), replaceStr);

	// (6) �ڸ���
	string subStr = str.substr(0, 3);

	// (7) C ��Ÿ�� ��ȯ
	const char* nameC = str.c_str();
}