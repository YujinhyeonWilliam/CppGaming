#include "pch.h"
#include "Player.h"
#include "Board.h"

void Player::Init(Board* board)
{
	_board = board;
	SetPos(board->GetEnterPos());

	CalculatePath_Astar();
}

bool Player::CanGo(Pos pos)
{
	TileType tileType = _board->GetTileType(pos);
	return tileType == TileType::EMPTY;
}


void Player::CalculatePath_RightHand()
{
	Pos pos = _pos;

	_path.clear();
	_path.push_back(pos);

	Pos dest = _board->GetExitPos();
	Pos forward[4] =
	{
		Pos(-1, 0),	// up
		Pos(0, -1),	// left
		Pos(1, 0),	// down
		Pos(0, 1)	// right
	};

	while (pos != dest)
	{
		Pos nextPos = pos + forward[_dir];
		int32 rightturn = (_dir - 1 + MAX_DIR_COUNT) % MAX_DIR_COUNT;
		int32 leftturn = (_dir + 1 + MAX_DIR_COUNT) % MAX_DIR_COUNT;

		// 1. 오른쪽으로 갈수있으면 우회전
		if (CanGo(pos + forward[rightturn]))
		{
			_dir = rightturn;
			nextPos = pos + forward[rightturn];
			_path.push_back(nextPos);
			pos = nextPos;
		}
		// 2. 앞으로 갈수 있으면 전진
		else if (CanGo(nextPos))
		{
			_path.push_back(nextPos);
			pos = nextPos;
		}
		// 3. 둘다 아니면 왼쪽으로 방향 변경
		else
		{
			_dir = leftturn;
		}
	}
}

void Player::CalculatePath_BFS()
{
	Pos pos = _pos;
	Pos dest = _board->GetExitPos();

	const int32 size = _board->GetSize();
	vector<vector<bool>> discovered(size, vector<bool>(size, false));
	// parent[y][x] = pos -> (y, x)는 pos에 의해 발견됨
	vector<vector<Pos>> parent(size, vector<Pos>(size, Pos(-1, -1)));

	Pos forward[4] =
	{
		Pos(-1, 0),	// up
		Pos(0, -1),	// left
		Pos(1, 0),	// down
		Pos(0, 1)	// right
	};
	
	queue<Pos> q;
	q.push(pos);
	discovered[pos.y][pos.x] = true;
	parent[pos.y][pos.x] = pos;

	while (q.empty() == false)
	{
		pos = q.front();
		q.pop();

		if (pos == dest)
			break;

		for (int32 dir = 0; dir < MAX_DIR_COUNT; dir++)
		{
			Pos nextPos = pos + forward[dir];
			if (CanGo(nextPos) == false)
				continue;

			// 이미 다른 경로에 의해 발겨노딘 지역인가
			if (discovered[nextPos.y][nextPos.x])
				continue;
			
			q.push(nextPos);
			discovered[nextPos.y][nextPos.x] = true;
			parent[nextPos.y][nextPos.x] = pos;
		}
	}

	_path.clear();
	pos = dest;
	while (true)
	{
		_path.push_back(pos);

		// 시작점
		if (pos == parent[pos.y][pos.x])
			break;

		pos = parent[pos.y][pos.x];
	}

	int pathSize = static_cast<int>(_path.size());
	vector<Pos> temp(pathSize);
	for (int i = 0; i < pathSize; i++)
		temp[i] = _path[pathSize - 1 - i];

	_path = temp;
}


// 채점
// - 입구에서부터 얼마나 떨어져 있는지?
// - 출구에서부터 얼마나 떨어져 있는지?

struct PQNode
{
	PQNode(int32 f, int32 g, Pos pos) : f(f), g(g), pos(pos) {}

	bool operator<(const PQNode& other) const { return f < other.f; }
	bool operator>(const PQNode& other) const { return f > other.f; }

	int32 f; // f = g + h
	int32 g;
	Pos pos;
};

void Player::CalculatePath_Astar()
{
	// F = G + H
	// F = 최종 점수 (작을수록 좋음)
	// G = 시작점에서 해당 좌표까지 이동하는데 드는 비용
	// H = 목적지에서 해당 좌표까지 이동하는데 드는 비용
	Pos start = _pos;
	Pos dest = _board->GetExitPos();

	Pos forward[] =
	{
		Pos(-1, 0),	// up
		Pos(0, -1),	// left
		Pos(1, 0),	// down
		Pos(0, 1),	// right
		Pos(-1, -1), // UP_LEFT
		Pos(1, -1), // DOWN_LEFT
		Pos(1, 1), // DOWN_RIGHT
		Pos(-1, 1), // UP_RIGHT
	};

	int32 cost[] =
	{
		10, // 상
		10, // 하
		10, // 좌
		10, // 우
		14, // 14는 대각선
		14,
		14,
		14
	};

	const int32 size = _board->GetSize();

	// best[y][x] -> 지금까지 (y, x)에 대한 가장 좋은 비용 (작을수록 좋음)
	vector<vector<int32>> best(size, vector<int32>(size, INT32_MAX));
	
	// 옵션) 사실 Best만해도 판별 가능
	// closed[y][x]에 '실제로' 방문했는가?
	vector<vector<bool>> closed(size, vector<bool>(size, false));

	// 부모 추적 용도
	vector<vector<Pos>> parent(size, vector<Pos>(size, Pos(-1, -1)));

	// 1) 예약 시스템 구현
	// 2) 뒤늦게 더 좋은 경로가 발견될 수 있음 -> 예외 처리! 

	// OpenList : 지금까지 발견된 목록
	priority_queue<PQNode, vector<PQNode>, greater<PQNode>> pq;
	
	// 초기값
	{
		int32 g = 0;
		// 휴리스틱 공식은 언제든지 내가 원하는대로 입맛에 맞게 바꿔주면 됨
		int32 h = 10 * (abs(dest.y - start.y) + abs(dest.y - start.x));
		pq.push(PQNode(g + h, g, start));
		best[start.y][start.x] = g + h;
		parent[start.y][start.x] = start;
	}

	while (pq.empty() == false)
	{
		// 제일 좋은 후보를 찾는다.
		PQNode node = pq.top();
		pq.pop();

		// 동일한 좌표를 여러 경로로 찾아서
		// 더 빠른 경로로 인해 이미 방문(closed)처리 된 경우 스킵
		if (closed[node.pos.y][node.pos.x])
			continue;

		// 나보다 더 우수한 후보가 있을 때
		if (best[node.pos.y][node.pos.x] < node.f)
			continue;

		// 방문
		closed[node.pos.y][node.pos.x] = true;

		// 목적지에 도착했으면 바로 종료
		if (node.pos == dest)
			break;

		for (int32 dir = 0; dir < 8; dir++)
		{
			Pos nextPos = node.pos + forward[dir];

			if (CanGo(nextPos) == false)
				continue;

			if (closed[nextPos.y][nextPos.x])
				continue;
			
			int32 g = node.g + cost[dir];
			int32 h = 10 * (abs(dest.y - nextPos.y) + abs(dest.x - nextPos.x));

			// 다른 경로에서 더 빠른 길을 찾았으면 스킵
			if (best[nextPos.y][nextPos.x] <= g + h)
				continue;

			best[nextPos.y][nextPos.x] = g + h;
			pq.push(PQNode(g + h, g, nextPos));
			parent[nextPos.y][nextPos.x] = node.pos;
		}
	}

	_path.clear();
	Pos pos = dest;
	while (true)
	{
		_path.push_back(pos);

		// 시작점
		if (pos == parent[pos.y][pos.x])
			break;

		pos = parent[pos.y][pos.x];
	}

	int pathSize = static_cast<int>(_path.size());
	vector<Pos> temp(pathSize);
	for (int i = 0; i < pathSize; i++)
		temp[i] = _path[pathSize - 1 - i];

	_path = temp;
}

void Player::Update(uint64 deltaTick)
{
	if (_pathIndex >= _path.size())
		return;

	_sumTick += deltaTick;
	if (_sumTick >= MOVE_TICK)
	{
		_pos = _path[_pathIndex];
		_pathIndex++;
		_sumTick = 0;
	}
}
