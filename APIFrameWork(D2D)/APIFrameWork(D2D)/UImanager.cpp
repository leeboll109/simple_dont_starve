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
	_craft = new Crafting;
	_craft->init();

	_charc = new Character;

	_clock = new Clock;
	_clock->init();

	_timeMental = 0;
	_timeHunger = 0;

	_hunger = STATMAX;
	_hp = STATMAX;
	_mental = STATMAX;

	//불값 초기화
	_hungerPopUp = false;
	_hpPopUp = false;
	_mentalPopUp = false;

	_stopMenuPopUp = false;

	_stopMenuGameBreak = false;
	_stopMenuGameResume = false;

	//프레임 이미지 init(배고픔, 체력, 멘탈)
	IMAGEMANAGER->addFrameImage(Rt, L"hunger", L"image/ui_hunger.png", 2400, 50, 50, 1);
	IMAGEMANAGER->addFrameImage(Rt, L"hp", L"image/ui_health.png", 2400, 50, 50, 1);
	IMAGEMANAGER->addFrameImage(Rt, L"mental", L"image/ui_mental.png", 2400, 50, 50, 1);
	IMAGEMANAGER->addFrameImage(Rt, L"number", L"image/ui_number.png", 150, 40, 10, 1);

	//이미지 init (image 클래스 사용)
	_stopMenuButton = IMAGEMANAGER->addImage(Rt, L"stopMenuButton", L"image/ui_stopmenubutton.png", 23, 22);

	IMAGEMANAGER->addImage(Rt, L"stopMenu", L"image/ui_stopMenu.png", 398, 450);
	IMAGEMANAGER->addImage(Rt, L"stopMenuButton_yes", L"image/ui_stopmenubutton_yes.png", 165, 53);
	IMAGEMANAGER->addImage(Rt, L"stopMenuButton_no", L"image/ui_stopmenubutton_no.png", 165, 53);

	return S_OK;
}

void UImanager::release(void)
{
	_craft->release();
	_clock->release();
}

void UImanager::update(void)
{
	_craft->update();
	_clock->update();

	reduceStat(_timeHunger, REDUCEHUNGER, _hunger);
	reduceStat(_timeMental, REDUCEMENTAL, _mental);

	popUpCheck(_hungerPopUp, 1163, 89);
	popUpCheck(_hpPopUp, 1226, 89);
	popUpCheck(_mentalPopUp, 1194, 137);

	stopMenuUpCheck(_stopMenuPopUp, 1222, 693);
	stopMenuButtonClickCheck(_stopMenuGameBreak, _stopMenuGameResume, 564, 355, 564, 445);
	stopMenuButtonFunc(_stopMenuGameBreak, _stopMenuGameResume, _stopMenuPopUp);
}

void UImanager::render(void)
{
	_craft->render();
	_clock->render();

	//프레임 이미지 렌더
	IMAGEMANAGER->frameRender(L"hunger", Rt, 1163, 89, 50 - _hunger, 0);
	IMAGEMANAGER->frameRender(L"hp", Rt, 1226, 89, 50 - _hp, 0);
	IMAGEMANAGER->frameRender(L"mental", Rt, 1194, 137, 50 - _mental, 0);

	//이미지 렌더
	IMAGEMANAGER->render(L"stopMenuButton", Rt, 1222, 693);

	//넘버 뜨게할 위치는 임의로 설정했습니다(조금 복잡합니다 ㅜㅜ)
	popUpNumberRender(_hungerPopUp, _hunger, 1163 + STATIMAGE_FRAMEWIDTH - 9, 89 + STATIMAGE_HEIGHT / 9);
	popUpNumberRender(_hpPopUp, _hp, 1226 + STATIMAGE_FRAMEWIDTH - 9, 89 + STATIMAGE_HEIGHT / 9);
	popUpNumberRender(_mentalPopUp, _mental, 1194 + STATIMAGE_FRAMEWIDTH - 9, 137 + STATIMAGE_HEIGHT / 9);

	stopMenuRender(_stopMenuPopUp, WINSIZEX_NUM / 2 - 199, WINSIZEY_NUM / 2 - 225);
}

void UImanager::reduceStat(int& timeStat, int reduceValue, int& stat)
{
	//시간이 지나면 캐릭터의 포만감이 줄어듭니다(이것은 시간이 지나면 줄어드는 게 전부에요)
	if ((int)TIMEMANAGER->getWorldTime() % reduceValue == 0 && (int)TIMEMANAGER->getWorldTime() != timeStat) {
		timeStat = (int)TIMEMANAGER->getWorldTime();
		stat--;
	}
}

void UImanager::popUpCheck(bool& popUp, int x, int y)
{
	//마우스가 렉트 안에 가있는지? (STATEIMAGE_FRAMEWIDTH = 가로값, STATEIMAGE_HEIGHT = 세로값 디파인입니다)
	if (IsInRect(_ptMouse, { x, y, x + STATIMAGE_FRAMEWIDTH, y + STATIMAGE_HEIGHT })) {
		popUp = true;
	}
	else {
		popUp = false;
	}
}

void UImanager::stopMenuUpCheck(bool& popUp, int x, int y)
{
	//스탑 메뉴 렉트안에 마우스가 있고 LBUTTON이 눌렸을때 
	if (IsInRect(_ptMouse, { x, y, x + 23, y + 22 })) {
		if (KEYMANAGER->isOnceKeyDown(VK_LBUTTON)) {
			//현재 popUp 인자의 불값을 바꿔줍니다
			//이렇게되면 처음 버튼을 눌렀을때는 true가 되고 다시 버튼을 누르면 false가 됩니다(논리반전)
			popUp = !popUp;
		}
	}
}

void UImanager::popUpNumberRender(bool popUp, int stat, int x, int y)
{
	//유민형님이 보여주신 기능입니다(확실히 이해하고 주석 추가할게요)
	if (popUp) {
		int tmp = stat;
		int countScore = 0;
		while (tmp != 0) {
			countScore++;
			IMAGEMANAGER->frameRender(L"number", Rt, x - 15 * countScore, y, tmp % 10, 0);
			tmp /= 10;
		}
		if (countScore == 0) {
			IMAGEMANAGER->frameRender(L"number", Rt, x, y, 0, 0);
		}
	}
}

void UImanager::stopMenuRender(bool popUp, int x, int y)
{
	//popUp이 true일 경우에 stopMenu를 키값으로 가지는 이미지를 띄운다
	if (popUp) {
		IMAGEMANAGER->render(L"stopMenu", Rt, x, y);
		IMAGEMANAGER->render(L"stopMenuButton_yes", Rt, x + 123, y + 220);
		IMAGEMANAGER->render(L"stopMenuButton_no", Rt, x + 123, y + 310);
	}
}

void UImanager::stopMenuButtonClickCheck(bool& popUpGameBreak, bool& popUpGameResume, int x1, int y1, int x2, int y2)
{
	//스탑 메뉴 첫번째 버튼 안에 마우스가 있고 LBUTTON이 눌렸을때 
	if (IsInRect(_ptMouse, { x1, y1, x1 + 165, y1 + 53 })) {
		if (KEYMANAGER->isOnceKeyDown(VK_LBUTTON)) {
			//popUpGameStop이 true 아니면 false
			popUpGameBreak = true;
		}
		else {
			popUpGameBreak = false;
		}
	}

	else if (IsInRect(_ptMouse, { x2, y2, x2 + 165, y2 + 53 })) {
		if (KEYMANAGER->isOnceKeyDown(VK_LBUTTON)) {
			//popUpGameResume이 true 아니면 false
			popUpGameResume = true;
		}
		else {
			popUpGameResume = false;
		}
	}
}

void UImanager::stopMenuButtonFunc(bool popUpGameBreak, bool popUpGameResume, bool& popUp)
{
	//게임 종료 판별 불값, 게임 재개 판별 불값, 메뉴 창 불값을 받아서
	if (popUpGameBreak) {
		//게임 종료 판별 불값이 true이면 게임을 종료(임시)합니다
		PostQuitMessage(0);
	}

	//게임 재개 판별 불값이 true이면 메뉴 창의 불값을 논리반전합니다
	//메뉴 창이 켜져있는 상태이니 true가 false로 바뀝니다(메뉴 창 닫힘)
	else if (popUpGameResume) {
		popUp = !popUp;
	}
}
