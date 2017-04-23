#include "stdafx.h"
#include "Character.h"


Character::Character()
{}

Character::~Character()
{}

HRESULT Character::init(void)
{
	_dir = DOWN;
	isWalk = false;

	// 이미지 키값 인덱스
	character_action[IDLE] = L"player_idle";
	character_action[RUN] = L"player_run";
	character_action[RUN_TORCH] = L"player_run_torch";
	character_action[ACTION_AXE] = L"player_axe";
	character_action[ACTION_PICKAXE] = L"player_pickaxe";
	character_action[ACTION_BUILD] = L"player_build";
	character_action[ACTION_PICKUP] = L"player_pickup";
	character_action[ITEM_IN] = L"player_item_in";
	character_action[ITEM_OUT] = L"player_item_out";
	character_action[IDLE_TORCH] = L"player_idle_torch";
	character_action[WAKEUP] = L"player_wakeup";

	// item_in, item_out, wakeup
	character_order[NONE] = L"";
	// idle, idle_torch, pickup, actionFX,
	character_order[NONE_DOWN] = L"_down";
	character_order[NONE_SIDE] = L"_side";
	character_order[NONE_UP] = L"_up";
	// idle_sanity, build, run, run_torch, axe, pickaxe
	character_order[PRE_DOWN] = L"_pre_down";
	character_order[PRE_SIDE] = L"_pre_side";
	character_order[PRE_UP] = L"_pre_up";
	character_order[LOOP_DOWN] = L"_loop_down";
	character_order[LOOP_SIDE] = L"_loop_side";
	character_order[LOOP_UP] = L"_loop_up";
	character_order[PST_DOWN] = L"_pst_down";
	character_order[PST_SIDE] = L"_pst_side";
	character_order[PST_UP] = L"_pst_up";

	_action = WAKEUP;
	_order = NONE;

	isOpening = true;
	count = 0;

	characterX = WINSIZEX_NUM / 2;
	characterY = WINSIZEY_NUM / 2;
	frameX = 0;

	return S_OK;
}

void Character::release(void)
{
}

void Character::update(void)
{
	// up
	if (KEYMANAGER->isStayKeyDown('W')) {
		characterY -= CHARACTER_SPEED;
		isWalk = true;
		_dir = UP;
	}
	// down
	if (KEYMANAGER->isStayKeyDown('S')) {
		characterY += CHARACTER_SPEED;
		isWalk = true;
		_dir = DOWN;
	}
	//left
	if (KEYMANAGER->isStayKeyDown('A')) {
		characterX -= CHARACTER_SPEED;
		isWalk = true;
		_dir = LEFT;
	}
	//right
	if (KEYMANAGER->isStayKeyDown('D')) {
		characterX += CHARACTER_SPEED;
		isWalk = true;
		_dir = RIGHT;
	}

	count++;
	if (count > 10) {
		if (isOpening) {
			frameX++;
			if (frameX > 45) {
				isOpening = false;
				frameX = 0;
				_action = IDLE;
				_order = NONE_DOWN;
			}
		}
		if (isWalk) {
			frameX++;
			if (frameX > 10) {
				frameX = 0;
				_action = IDLE;
				_order = NONE_DOWN;
			}
		}
		else {
			frameX++;
			if (frameX > 10) {
				frameX = 0;
			}
		}
	}
	

}

void Character::render(void)
{
	IMAGEMANAGER->render(L"ground", Rt);

	tstring tmp = character_action[_action] + character_order[_order];
	//IMAGEMANAGER->frameRender(tmp, Rt, characterX, characterY, frameX, 0);
}


