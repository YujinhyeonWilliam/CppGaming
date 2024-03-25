#include <iostream>
using namespace std;
#include <vector>
#include <queue>

struct Vertex
{
	// int data;
};

vector<Vertex> vertices;
vector<vector<int>> adjacent;

//내가 방문한 목록
vector<bool> visited;

// 발견한
vector<bool> discovered;

void CreateGraph()
{
	vertices.resize(6);

	// 인접 리스트
	adjacent = vector<vector<int>>(6);
	adjacent[0] = { 1, 3 };
	adjacent[1] = { 0, 2, 3 };
	adjacent[3] = { 4 };
	adjacent[5] = { 4 };

	// 인접 행렬
	adjacent = vector<vector<int>>
	{
		{0, 1, 0, 1, 0, 0},
		{1, 0, 1, 1, 0, 0},
		{0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 1, 0},
		{0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 1, 0},
	};

}


void BFS(int now)
{
	// ex) 누구에 의해서 발견되었는가
	vector<int> parent(6, -1);

	// ex) 시작점에서 얼만큼 떨어져 있는가?
	vector<int> dist(6, -1);
	queue<int> q;
	q.push(now);

	discovered[now] = true;
	parent[now] = now;
	dist[now] = 0;

	while (q.empty() == false)
	{
		now = q.front();
		q.pop();

		// 방문 도장
		cout << "Visited : " << now << endl;

		// 인접행렬
		for (int dest = 0; dest < 6; dest++)
		{
			if (adjacent[now][dest] == false)
				continue;

			if (discovered[dest])
				continue;

			q.push(dest);
			discovered[dest] = true;

			parent[dest] = now;
			dist[dest] = dist[now] + 1;
		}

		// 인접리스트
		//int size = static_cast<int>(adjacent[now].size());
		//for(int i=0; i<size; i++)
		//{
		//	int dest = adjacent[now][i];
		//	if (discovered[dest])
		//		continue;

		//	q.push(dest);
		//	discovered[dest] = true;
		//}
	}
}


void BFSALL()
{
	discovered = vector<bool>(6, false);
	for (int i = 0; i < 6; i++)
		if (discovered[i] == false)
			BFS(i);
}

int main()
{
	CreateGraph();
	// discovered = vector<bool>(6, false);
	// BFS(0);
	BFSALL();
}