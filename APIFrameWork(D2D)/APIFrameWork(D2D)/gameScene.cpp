#include "stdafx.h"
#include "gameScene.h"


gameScene::gameScene()
{
}


gameScene::~gameScene()
{
}

HRESULT gameScene::init(void)
{
	SOUNDMANAGER->addSound("�����", "sounds/Dawn_150bpm_3.4time.mp3", true, true);
	SOUNDMANAGER->addSound("�߰���", "sounds/bodyfall_dirt.mp3", false, false);
	SOUNDMANAGER->play("�����");

	for (int i = 0; i < TILEX; i++) {
		for (int j = 0; j < TILEY; ++j) {
			switch (RND->getInt(2)) {
			case 0: {
				_tile[i][j] = L"��1";
			}break;
			case 1: {
				_tile[i][j] = L"��2";
			}break;
			}
		}
	}


	setRadialGradientBrush(Rt, { (int)WINSIZEX_NUM / 2, (int)WINSIZEY_NUM / 2 }, 200, 150, 0.8f);

	_uimanager = new UImanager;
	_uimanager->init();

	_inventory = new Inventory;
	_inventory->init();

	_character = new Character;
	_character->init();

	CAMERAMANAGER->setPositionMemotyRick(_character->getPointerPosition());

	_obj = new OBJECT_ENVIRONMENT;
	_obj->init(EOBJKIND_ENVIRONMENT::FLOWER, { (int)MAPMAX_X / 2 - 500, (int)MAPMAX_Y / 2 - 500 });
	calulateStandard();
	return S_OK;
}

void gameScene::release(void)
{
	_uimanager->release();
	_inventory->release();
	_character->release();
}

void gameScene::update(void)
{
	_uimanager->update();
	_inventory->update();
	_character->update();

	if (KEYMANAGER->isOnceKeyUp('Q')) {
		SOUNDMANAGER->play("�߰���");
		_obj->damage(1);
	}

	calulateStandard();

	_obj->update();
}

void gameScene::render(void)
{
	for (int i = _tmp.x - 2; i < _tmp.x + 3; ++i) {
		for (int j = _tmp.y - 1; j < _tmp.y + 2; ++j) {
			POINT _ttmp = CAMERAMANAGER->getAbsPosition({ i*TILESIZEX, j*TILESIZEY });
			IMAGEMANAGER->render(_tile[i][j], Rt, _ttmp.x, _ttmp.y);
		}
	}

	IMAGEMANAGER->alphaRender(L"���", Rt, 0, 0, 0.3);
	
	_obj->render();
	
	_character->render();

	IMAGEMANAGER->alphaRender(L"���", Rt, 0, 0, 0.1);
	
	_uimanager->render();
	_inventory->render();

	TCHAR testText[50];
	wsprintf(testText, L"Ÿ�� X : %d", _tmp.x);
	D2TextOut(Rt, testText, TextFormat, D2D1::Rect(300, 100, 600, 120), Brush);
	wsprintf(testText, L"Ÿ�� Y : %d", _tmp.y);
	D2TextOut(Rt, testText, TextFormat, D2D1::Rect(300, 120, 600, 140), Brush);
   
	TIMEMANAGER->render(Rt);
}

void gameScene::calulateStandard()
{

	long i = _character->getPointerPosition()->x / TILESIZEX;
	long j = _character->getPointerPosition()->y / TILESIZEY;
	_tmp.x = i;
	_tmp.y = j;
}