#include <iostream>
#include <vector>
#include <list>
#include <queue>
#include <map>
using namespace std;

class Player
{
public:
	Player() {}
	Player(int id) : _id(id) { }

	int _id = 0;
};

template<typename T, typename U>
struct Pair
{
	T first;
	U second;
};

template<typename T, typename U>
std::pair<T, U> MakePair(T first, U second)
{
	return std::pair<T, U>(first, second);
}


int main()
{
	vector<Player*> v;
	v.push_back(new Player(200));
	v.push_back(new Player(400));
	v.push_back(new Player(300));
	v.push_back(new Player(500));
	v.push_back(new Player(100));

	// (Key, Value)
	map<int, Player*> m;

	// 추가
	std::pair<int, Player*> p;

	for(Player* player : v)
	{
		m.insert(make_pair(player->_id, player));
	}

	// 찾기
	auto it = m.find(300); // O(logN)
	if (it != m.end())
	{
		int key = it->first;
		Player* player = it->second;
	}
	else
	{
		cout << "데이터 없음" << endl;
	}

	// 삭제
	m.erase(it);

	// 순회
	for (auto it = m.begin(); it != m.end(); it++)
	{
		int key = it->first;
		Player* value = it->second;
	}


}