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
	character_order[NONE_ACTION] = L"";
	// idle, idle_torch, pickup, actionFX,
	character_order[NONE_DOWN] = L"_down";
	character_order[NONE_RIGHT] = L"_right";
	character_order[NONE_LEFT] = L"_left";
	character_order[NONE_UP] = L"_up";
	// idle_sanity, build, run, run_torch, axe, pickaxe
	character_order[PRE_DOWN] = L"_pre_down";
	character_order[PRE_RIGHT] = L"_pre_right";
	character_order[PRE_LEFT] = L"_pre_left";
	character_order[PRE_UP] = L"_pre_up";
	character_order[LOOP_DOWN] = L"_loop_down";
	character_order[LOOP_RIGHT] = L"_loop_right";
	character_order[LOOP_LEFT] = L"_loop_left";
	character_order[LOOP_UP] = L"_loop_up";
	character_order[PST_DOWN] = L"_pst_down";
	character_order[PST_RIGHT] = L"_pst_right";
	character_order[PST_LEFT] = L"_pst_left";
	character_order[PST_UP] = L"_pst_up";

	_action = IDLE;
	_order = NONE_DOWN;

	isOpening = true;
	count = 0;
	isWalkComp = false;

	_position.x = MAPMAX_X / 2 - 500;
	_position.y = MAPMAX_X / 2 - 500;
	frameX = 0;

	CAMERAMANAGER->setPositionMemotyRick(&_position);
	return S_OK;
}

void Character::release(void)
{
}

void Character::update(void)
{
	// up
	if (KEYMANAGER->isOnceKeyDown('W') || KEYMANAGER->isOnceKeyDown(VK_UP)) {
		isWalkComp = false;
	}
	if (KEYMANAGER->isStayKeyDown('W') || KEYMANAGER->isStayKeyDown(VK_UP)) {
		_position.y -= SPEED;
		isWalk = true;
		_dir = UP;
	}
	// down
	if (KEYMANAGER->isOnceKeyDown('S') || KEYMANAGER->isOnceKeyDown(VK_DOWN)) {
		isWalkComp = false;
	}
	if (KEYMANAGER->isStayKeyDown('S') || KEYMANAGER->isStayKeyDown(VK_DOWN)) {
		_position.y += SPEED;
		isWalk = true;
		_dir = DOWN;
	}
	//left	
	if (KEYMANAGER->isOnceKeyDown('A') || KEYMANAGER->isOnceKeyDown(VK_LEFT)) {
		isWalkComp = false;
	}
	if (KEYMANAGER->isStayKeyDown('A') || KEYMANAGER->isStayKeyDown(VK_LEFT)) {
		_position.x -= SPEED;
		isWalk = true;
		_dir = LEFT;
	}
	//right
	if (KEYMANAGER->isOnceKeyDown('D') || KEYMANAGER->isOnceKeyDown(VK_RIGHT)) {
		isWalkComp = false;
	}
	if (KEYMANAGER->isStayKeyDown('D') || KEYMANAGER->isStayKeyDown(VK_RIGHT)) {
		_position.x += SPEED;
		isWalk = true;
		_dir = RIGHT;
	}

	// up remove
	if (KEYMANAGER->isOnceKeyUp('W') || KEYMANAGER->isOnceKeyUp(VK_UP)) {
		isWalk = false;
		_dir = UP;
	}
	//down remove
	if (KEYMANAGER->isOnceKeyUp('S') || KEYMANAGER->isOnceKeyUp(VK_DOWN)) {
		isWalk = false;
		_dir = DOWN;
	}
	//left remove
	if (KEYMANAGER->isOnceKeyUp('A') || KEYMANAGER->isOnceKeyUp(VK_LEFT)) {
		isWalk = false;
		_dir = LEFT;
	}
	//right remove
	if (KEYMANAGER->isOnceKeyUp('D') || KEYMANAGER->isOnceKeyUp(VK_RIGHT)) {
		isWalk = false;
		_dir = RIGHT;
	}

	count++;
	if (isOpening) {
		frameX++;
		if (frameX > 45) {
			isOpening = false;
			frameX = 0;
			_action = IDLE;
			_order = NONE_DOWN;
		}
	}
	if (isWalk && count % 8 == 0) {
		frameX++;
		if (!isWalkComp) {
			_action = RUN;
			switch (_dir)
			{
			case DOWN:
				_order = PRE_DOWN;
				isWalkComp = true;
				break;
			case UP:
				_order = PRE_UP;
				isWalkComp = true;
				break;
			case LEFT:
				_order = PRE_LEFT;
				isWalkComp = true;
				break;
			case RIGHT:
				_order = PRE_RIGHT;
				isWalkComp = true;
				break;
			default:
				break;
			}
		}
		if (frameX > 10) {
			frameX = 0;
			_action = RUN;
			switch (_dir)
			{
			case DOWN:
				_order = LOOP_DOWN;
				break;
			case UP:
				_order = LOOP_UP;
				break;
			case LEFT:
				_order = LOOP_LEFT;
				break;
			case RIGHT:
				_order = LOOP_RIGHT;
				break;
			default:
				break;
			}
		}
	}
	else if (!isWalk && count % 4 == 0) {
		frameX++;
		if (frameX > 10) {
			frameX = 0;
			_action = IDLE;
			switch (_dir)
			{
			case DOWN:
				_order = NONE_DOWN;
				break;
			case UP:
				_order = NONE_UP;
				break;
			case LEFT:
				_order = NONE_LEFT;
				break;
			case RIGHT:
				_order = NONE_RIGHT;
				break;
			default:
				break;
			}
		}
	}
}

void Character::render(void)
{
	tstring tmp = character_action[_action] + character_order[_order];
	IMAGEMANAGER->frameRender(tmp, Rt, WINSIZEX_NUM / 2 - 0.15 * (IMAGEMANAGER->findImage(tmp)->getWidth() / 10), WINSIZEY_NUM / 2 - 0.5 * (IMAGEMANAGER->findImage(tmp)->getHeight()), frameX, 0);
}