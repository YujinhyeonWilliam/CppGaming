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

//���� �湮�� ���
vector<bool> visited;

// �߰���
vector<bool> discovered;

void CreateGraph()
{
	vertices.resize(6);

	// ���� ����Ʈ
	adjacent = vector<vector<int>>(6);
	adjacent[0] = { 1, 3 };
	adjacent[1] = { 0, 2, 3 };
	adjacent[3] = { 4 };
	adjacent[5] = { 4 };

	// ���� ���
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
	// ex) ������ ���ؼ� �߰ߵǾ��°�
	vector<int> parent(6, -1);

	// ex) ���������� ��ŭ ������ �ִ°�?
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

		// �湮 ����
		cout << "Visited : " << now << endl;

		// �������
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

		// ��������Ʈ
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