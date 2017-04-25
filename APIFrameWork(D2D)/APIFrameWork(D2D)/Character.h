#pragma once
#include "gameNode.h"

#define CHARACTER_SPEED 5

// ĳ���� �̵� ����
enum CHARACTER_DIR {
	DOWN,
	UP,
	LEFT,
	RIGHT
};

// ĳ���� ������ ����
enum CHARACTER_ACTION {
	WAKEUP,
	IDLE,
	IDLE_TORCH,
	RUN,
	RUN_TORCH,
	ACTION_AXE,
	ACTION_PICKAXE,
	ACTION_BUILD,
	ACTION_PICKUP,
	ITEM_IN,
	ITEM_OUT
};
// ĳ���� ������ ����
enum CHARACTER_ORDER {
	NONE_ACTION,
	NONE_DOWN,
	NONE_RIGHT,
	NONE_LEFT,
	NONE_UP,
	PRE_DOWN,
	PRE_RIGHT,
	PRE_LEFT,
	PRE_UP,
	LOOP_DOWN,
	LOOP_RIGHT,
	LOOP_LEFT,
	LOOP_UP,
	PST_DOWN,
	PST_RIGHT,
	PST_LEFT,
	PST_UP
};

class Character : public gameNode
{
private:
	CHARACTER_DIR _dir;
	tstring character_action[16];
	tstring character_order[17];

	CHARACTER_ORDER _order;
	CHARACTER_ACTION _action;

	RECT HUD[3];

	bool isWalk;
	bool isOpening;
	bool isWalkComp;
	int count;
	POINT _position;				// int characterX, characterY;
	int frameX;

public:
	Character();
	~Character();

	HRESULT init(void);
	void release(void);
	void update(void);
	void render(void);

	POINT* getPointerPosition() { return &_position; }
};