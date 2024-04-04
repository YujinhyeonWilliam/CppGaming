#pragma once
#include "Object.h"

enum class PlayerType
{
	CanonTank,
	MissileTank
};

class Player : public Object
{
public:
	Player();
	virtual ~Player() override;

	virtual void Init() override;
	virtual void Update() override;
	virtual void Render(HDC hdc) override;

	wstring GetMeshKey();

	void SetPlayerType(PlayerType type) { _playerType = type; }
	void SetPlayerId(int32 playerId) { _playerId = playerId; }
	void SetPlayerTurn(bool playerTurn) { _playerTurn = playerTurn; }
	
	int32 GetPlayerId() { return _playerId; }
	PlayerType GetPlayerType() { return _playerType; }
	bool GetPlayerTurn() { return _playerTurn; }

	void UpdateFireAngle();

public:
	PlayerType	_playerType = PlayerType::CanonTank;
	int32		_playerId = 0;
	bool		_playerTurn = false;
	float		_fireAngle = 0.f;
};

