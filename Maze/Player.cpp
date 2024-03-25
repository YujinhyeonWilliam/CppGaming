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

		// 1. ���������� ���������� ��ȸ��
		if (CanGo(pos + forward[rightturn]))
		{
			_dir = rightturn;
			nextPos = pos + forward[rightturn];
			_path.push_back(nextPos);
			pos = nextPos;
		}
		// 2. ������ ���� ������ ����
		else if (CanGo(nextPos))
		{
			_path.push_back(nextPos);
			pos = nextPos;
		}
		// 3. �Ѵ� �ƴϸ� �������� ���� ����
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
	// parent[y][x] = pos -> (y, x)�� pos�� ���� �߰ߵ�
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

			// �̹� �ٸ� ��ο� ���� �߰ܳ�� �����ΰ�
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

		// ������
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


// ä��
// - �Ա��������� �󸶳� ������ �ִ���?
// - �ⱸ�������� �󸶳� ������ �ִ���?

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
	// F = ���� ���� (�������� ����)
	// G = ���������� �ش� ��ǥ���� �̵��ϴµ� ��� ���
	// H = ���������� �ش� ��ǥ���� �̵��ϴµ� ��� ���
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
		10, // ��
		10, // ��
		10, // ��
		10, // ��
		14, // 14�� �밢��
		14,
		14,
		14
	};

	const int32 size = _board->GetSize();

	// best[y][x] -> ���ݱ��� (y, x)�� ���� ���� ���� ��� (�������� ����)
	vector<vector<int32>> best(size, vector<int32>(size, INT32_MAX));
	
	// �ɼ�) ��� Best���ص� �Ǻ� ����
	// closed[y][x]�� '������' �湮�ߴ°�?
	vector<vector<bool>> closed(size, vector<bool>(size, false));

	// �θ� ���� �뵵
	vector<vector<Pos>> parent(size, vector<Pos>(size, Pos(-1, -1)));

	// 1) ���� �ý��� ����
	// 2) �ڴʰ� �� ���� ��ΰ� �߰ߵ� �� ���� -> ���� ó��! 

	// OpenList : ���ݱ��� �߰ߵ� ���
	priority_queue<PQNode, vector<PQNode>, greater<PQNode>> pq;
	
	// �ʱⰪ
	{
		int32 g = 0;
		// �޸���ƽ ������ �������� ���� ���ϴ´�� �Ը��� �°� �ٲ��ָ� ��
		int32 h = 10 * (abs(dest.y - start.y) + abs(dest.y - start.x));
		pq.push(PQNode(g + h, g, start));
		best[start.y][start.x] = g + h;
		parent[start.y][start.x] = start;
	}

	while (pq.empty() == false)
	{
		// ���� ���� �ĺ��� ã�´�.
		PQNode node = pq.top();
		pq.pop();

		// ������ ��ǥ�� ���� ��η� ã�Ƽ�
		// �� ���� ��η� ���� �̹� �湮(closed)ó�� �� ��� ��ŵ
		if (closed[node.pos.y][node.pos.x])
			continue;

		// ������ �� ����� �ĺ��� ���� ��
		if (best[node.pos.y][node.pos.x] < node.f)
			continue;

		// �湮
		closed[node.pos.y][node.pos.x] = true;

		// �������� ���������� �ٷ� ����
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

			// �ٸ� ��ο��� �� ���� ���� ã������ ��ŵ
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

		// ������
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
