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

void CreateGraph()
{
	vertices.resize(6);
	adjacent = vector<vector<int>>(6, vector<int>(6, -1));
	adjacent[0][1] = adjacent[1][0] = 15;
	adjacent[0][3] = adjacent[3][0] = 35;
	adjacent[1][2] = adjacent[2][1] = 5;
	adjacent[1][3] = adjacent[3][1] = 10;
	adjacent[3][4] = adjacent[4][3] = 5;
	adjacent[5][4] = adjacent[4][5] = 5;

}

struct VertexCost
{
	VertexCost(int cost, int vertex) : cost(cost), vertex(vertex) {}
	int cost;
	int vertex;

	bool operator<(const VertexCost& other) const
	{
		return cost < other.cost;
	}

	bool operator>(const VertexCost& other) const
	{
		return cost > other.cost;
	}

	bool operator==(const VertexCost& other) const
	{
		return cost == other.cost;
	}

	bool operator!=(const VertexCost& other) const
	{
		return !(cost == other.cost);
	}

};

// Dijikstra = BFS + 양념(cost)
// - BFS : Queue
// - Dijikstra = Priority Queue

void Dijikstra(int now)
{
	priority_queue<VertexCost, vector<VertexCost>, greater<VertexCost>> pq;
	vector<int> best(6, INT32_MAX);
	vector<int> parent(6, -1);

	pq.push(VertexCost(0, now));
	best[now] = 0;
	parent[now] = now;

	while (pq.empty() == false)
	{
		VertexCost v = pq.top();
		pq.pop();

		int cost = v.cost;
		now = v.vertex;

		if (best[now] < cost)
			continue;
		
		cout << "방문!: " << now << endl;

		for (int dest = 0; dest < 6; dest++)
		{
			if (adjacent[now][dest] == -1)
				continue;

			// 더 좋은 경로를 과거에 찾았으면 스킵
			int nextCost = best[now] + adjacent[now][dest];
			if (nextCost >= best[dest])
				continue;

			// 지금까지 찾은 최선의 수치
			best[dest] = nextCost;
			parent[dest] = now; // 나중에 갱신 가능
			pq.push(VertexCost(nextCost, dest));
		}
	}
}

int main()
{
	CreateGraph();
	Dijikstra(0);
}