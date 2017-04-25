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

	//�Ұ� �ʱ�ȭ
	_hungerPopUp = false;
	_hpPopUp = false;
	_mentalPopUp = false;

	_stopMenuPopUp = false;

	_stopMenuGameBreak = false;
	_stopMenuGameResume = false;

	//������ �̹��� init(�����, ü��, ��Ż)
	IMAGEMANAGER->addFrameImage(Rt, L"hunger", L"image/ui_hunger.png", 2400, 50, 50, 1);
	IMAGEMANAGER->addFrameImage(Rt, L"hp", L"image/ui_health.png", 2400, 50, 50, 1);
	IMAGEMANAGER->addFrameImage(Rt, L"mental", L"image/ui_mental.png", 2400, 50, 50, 1);
	IMAGEMANAGER->addFrameImage(Rt, L"number", L"image/ui_number.png", 150, 40, 10, 1);

	//�̹��� init (image Ŭ���� ���)
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

	//������ �̹��� ����
	IMAGEMANAGER->frameRender(L"hunger", Rt, 1163, 89, 50 - _hunger, 0);
	IMAGEMANAGER->frameRender(L"hp", Rt, 1226, 89, 50 - _hp, 0);
	IMAGEMANAGER->frameRender(L"mental", Rt, 1194, 137, 50 - _mental, 0);

	//�̹��� ����
	IMAGEMANAGER->render(L"stopMenuButton", Rt, 1222, 693);

	//�ѹ� �߰��� ��ġ�� ���Ƿ� �����߽��ϴ�(���� �����մϴ� �̤�)
	popUpNumberRender(_hungerPopUp, _hunger, 1163 + STATIMAGE_FRAMEWIDTH - 9, 89 + STATIMAGE_HEIGHT / 9);
	popUpNumberRender(_hpPopUp, _hp, 1226 + STATIMAGE_FRAMEWIDTH - 9, 89 + STATIMAGE_HEIGHT / 9);
	popUpNumberRender(_mentalPopUp, _mental, 1194 + STATIMAGE_FRAMEWIDTH - 9, 137 + STATIMAGE_HEIGHT / 9);

	stopMenuRender(_stopMenuPopUp, WINSIZEX_NUM / 2 - 199, WINSIZEY_NUM / 2 - 225);
}

void UImanager::reduceStat(int& timeStat, int reduceValue, int& stat)
{
	//�ð��� ������ ĳ������ �������� �پ��ϴ�(�̰��� �ð��� ������ �پ��� �� ���ο���)
	if ((int)TIMEMANAGER->getWorldTime() % reduceValue == 0 && (int)TIMEMANAGER->getWorldTime() != timeStat) {
		timeStat = (int)TIMEMANAGER->getWorldTime();
		stat--;
	}
}

void UImanager::popUpCheck(bool& popUp, int x, int y)
{
	//���콺�� ��Ʈ �ȿ� ���ִ���? (STATEIMAGE_FRAMEWIDTH = ���ΰ�, STATEIMAGE_HEIGHT = ���ΰ� �������Դϴ�)
	if (IsInRect(_ptMouse, { x, y, x + STATIMAGE_FRAMEWIDTH, y + STATIMAGE_HEIGHT })) {
		popUp = true;
	}
	else {
		popUp = false;
	}
}

void UImanager::stopMenuUpCheck(bool& popUp, int x, int y)
{
	//��ž �޴� ��Ʈ�ȿ� ���콺�� �ְ� LBUTTON�� �������� 
	if (IsInRect(_ptMouse, { x, y, x + 23, y + 22 })) {
		if (KEYMANAGER->isOnceKeyDown(VK_LBUTTON)) {
			//���� popUp ������ �Ұ��� �ٲ��ݴϴ�
			//�̷��ԵǸ� ó�� ��ư�� ���������� true�� �ǰ� �ٽ� ��ư�� ������ false�� �˴ϴ�(������)
			popUp = !popUp;
		}
	}
}

void UImanager::popUpNumberRender(bool popUp, int stat, int x, int y)
{
	//���������� �����ֽ� ����Դϴ�(Ȯ���� �����ϰ� �ּ� �߰��ҰԿ�)
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
	//popUp�� true�� ��쿡 stopMenu�� Ű������ ������ �̹����� ����
	if (popUp) {
		IMAGEMANAGER->render(L"stopMenu", Rt, x, y);
		IMAGEMANAGER->render(L"stopMenuButton_yes", Rt, x + 123, y + 220);
		IMAGEMANAGER->render(L"stopMenuButton_no", Rt, x + 123, y + 310);
	}
}

void UImanager::stopMenuButtonClickCheck(bool& popUpGameBreak, bool& popUpGameResume, int x1, int y1, int x2, int y2)
{
	//��ž �޴� ù��° ��ư �ȿ� ���콺�� �ְ� LBUTTON�� �������� 
	if (IsInRect(_ptMouse, { x1, y1, x1 + 165, y1 + 53 })) {
		if (KEYMANAGER->isOnceKeyDown(VK_LBUTTON)) {
			//popUpGameStop�� true �ƴϸ� false
			popUpGameBreak = true;
		}
		else {
			popUpGameBreak = false;
		}
	}

	else if (IsInRect(_ptMouse, { x2, y2, x2 + 165, y2 + 53 })) {
		if (KEYMANAGER->isOnceKeyDown(VK_LBUTTON)) {
			//popUpGameResume�� true �ƴϸ� false
			popUpGameResume = true;
		}
		else {
			popUpGameResume = false;
		}
	}
}

void UImanager::stopMenuButtonFunc(bool popUpGameBreak, bool popUpGameResume, bool& popUp)
{
	//���� ���� �Ǻ� �Ұ�, ���� �簳 �Ǻ� �Ұ�, �޴� â �Ұ��� �޾Ƽ�
	if (popUpGameBreak) {
		//���� ���� �Ǻ� �Ұ��� true�̸� ������ ����(�ӽ�)�մϴ�
		PostQuitMessage(0);
	}

	//���� �簳 �Ǻ� �Ұ��� true�̸� �޴� â�� �Ұ��� �������մϴ�
	//�޴� â�� �����ִ� �����̴� true�� false�� �ٲ�ϴ�(�޴� â ����)
	else if (popUpGameResume) {
		popUp = !popUp;
	}
}
