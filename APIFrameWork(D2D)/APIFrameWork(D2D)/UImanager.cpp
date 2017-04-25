#include "stdafx.h"
#include "UImanager.h"


UImanager::UImanager()
{
}


UImanager::~UImanager()
{
}

HRESULT UImanager::init(void)
{
	_craft = new crafting;
	_craft->init();

	_charc = new Character;

	_timeMental = 0;
	_timeHunger = 0;

	_hunger = STATMAX;
	_hp = STATMAX;
	_mental = STATMAX;

	return S_OK;
}

void UImanager::release(void)
{
	_craft->release();
}

void UImanager::update(void)
{
	_craft->update();

	//시간이 지나면 캐릭터의 포만감이 줄어듭니다(이것은 시간이 지나면 줄어드는 게 전부에요)
	if ((int)TIMEMANAGER->getWorldTime() % REDUCEHUNGER == 0 && (int)TIMEMANAGER->getWorldTime() != _timeHunger) {
		_timeHunger = (int)TIMEMANAGER->getWorldTime();
		_hunger--;
	}

	//시간이 지나면 캐릭터의 멘탈이 줄어듭니다(나중에 조건 추가!) => 이거 추가하실건지 물어보겠습니다
	if ((int)TIMEMANAGER->getWorldTime() % REDUCEMENTAL == 0 && (int)TIMEMANAGER->getWorldTime() != _timeMental) {
		_timeMental = (int)TIMEMANAGER->getWorldTime();
		_mental--;
	}
}

void UImanager::render(void)
{
	_craft->render();

	IMAGEMANAGER->frameRender(L"hunger", Rt, 1163, 89, 50 - _hunger, 0);
	IMAGEMANAGER->frameRender(L"health", Rt, 1226, 89, 50 - _hp, 0);
	IMAGEMANAGER->frameRender(L"mental", Rt, 1194, 137, 50 - _mental, 0);
}
