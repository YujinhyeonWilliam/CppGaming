#include "pch.h"
#include "Player.h"
#include "Board.h"

void Player::Init(Board* board)
{
	_board = board;
	SetPos(board->GetEnterPos());

	CalculatePath_BFS();
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
