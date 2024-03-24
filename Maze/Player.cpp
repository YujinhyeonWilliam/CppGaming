#include "pch.h"
#include "Player.h"
#include "Board.h"

void Player::Init(Board* board)
{
	_board = board;
	SetPos(board->GetEnterPos());

	CalculatePath();
}

bool Player::CanGo(Pos pos)
{
	TileType tileType = _board->GetTileType(pos);
	return tileType == TileType::EMPTY;
}


void Player::CalculatePath()
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
