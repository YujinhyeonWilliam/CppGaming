#include "pch.h"
#include "Vector.h"
#include "Board.h"
#include "Player.h"

Board board;
Player player;

int main()
{
	::srand(static_cast<uint32>(time(nullptr)));
	board.Init(25, &player);
	player.Init(&board);

	uint64 lastTick = 0;
	while (true)
	{

		#pragma region 프레임 관리
		const uint64 currentTick = ::GetTickCount64();
		const uint64 deltaTick = currentTick - lastTick;
		lastTick = currentTick;
		#pragma endregion

		// TODO: 입력

		// TODO: 로직
		player.Update(deltaTick);

		// TODO: 렌더링
		board.Render();
	}
}
