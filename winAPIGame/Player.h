#pragma once
#include "FlipbookActor.h"

class BoxCollider;

enum class PlayerState
{
	MoveGround,
	JumpFall,
};

class Player : public FlipbookActor
{
	using Super = FlipbookActor;
public:
	Player();
	virtual ~Player() override;

	virtual void BeginPlay() override;
	virtual void Tick() override;
	virtual void Render(HDC hdc) override;

	virtual void OnComponentBeginOverlap(Collider* collider, Collider* other) override;
	virtual void OnComponentEndOverlap(Collider* collider, Collider* other) override;

	void		 SetState(PlayerState state);
	PlayerState	 GetState() { return _state; }
private:
	virtual void	TickMoveGround(float deltaTime);
	virtual void	TickJumpFall(float deltaTime);
	void			TickInput(float deltaTime);
	void			TickGravity(float deltaTime);

private:
	void Jump();
	void AdjustCollisionPos(BoxCollider* b1, BoxCollider* b2);

private:
	Flipbook*	_flipbookUp = nullptr;
	Flipbook*	_flipbookDown = nullptr;
	Flipbook*	_flipbookLeft = nullptr;
	Flipbook*	_flipbookRight = nullptr;

private:
	Vector2D	_speed = {};
	int32		_gravity = 1000;
	PlayerState _state = PlayerState::JumpFall;
};

