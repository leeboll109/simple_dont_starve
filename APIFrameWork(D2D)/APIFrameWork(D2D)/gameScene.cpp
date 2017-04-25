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
	IMAGEMANAGER->addImage(Rt, L"블럭1", L"image/block.png", 512, 512);
	IMAGEMANAGER->addImage(Rt, L"블럭2", L"image/ground.png", 512, 512);
	IMAGEMANAGER->addImage(Rt, L"시침", L"image/clockpin.png", 20, 100);
	IMAGEMANAGER->addImage(Rt, L"노랑", L"image/yellow.png", MAPMAX_X, MAPMAX_Y);
	//IMAGEMANAGER->addFrameImage(Rt, L"캐릭터", L"image/player/idle/player_idle_down.png", 630, 100, 10, 1);
	SOUNDMANAGER->play("배경음");

	for (int i = 0; i < TILEX; i++) {
		for (int j = 0; j < TILEY; ++j) {
			switch (RND->getInt(2)) {
			case 0: {
				_tile[i][j] = L"블럭1";
			}break;
			case 1: {
				_tile[i][j] = L"블럭2";
			}break;
			}
		}
	}

	frame = count = 0;

	_pt.x = MAPMAX_X / 2 - 500;
	_pt.y = MAPMAX_Y / 2 - 500;

	_isWalk = false;

	CAMERAMANAGER->setPositionMemotyRick(&_pt);
	_time = 0;

	setRadialGradientBrush(Rt, { (int)WINSIZEX_NUM / 2, (int)WINSIZEY_NUM / 2 }, 200, 150);

	_uimanager = new UImanager;
	_uimanager->init();

	_inventory = new Inventory;
	_inventory->init();

	_character = new Character;
	_character->init();

	return S_OK;
}

void gameScene::release(void)
{
	_uimanager->release();
	_inventory->release();
}

void gameScene::update(void)
{
	_uimanager->update();
	_inventory->update();
	_character->update();
/*
	count++;
	frame = count / 2;
	if (frame == 10) {
		frame = 0;
	}

	_time = count / 2;
	if (_time == 360) {
		_time = 0;
	}

	if (KEYMANAGER->isStayKeyDown(VK_LEFT)) {
		_pt.x -= 3.0f;
		_isWalk = true;
	}
	if (KEYMANAGER->isStayKeyDown(VK_RIGHT)) {
		_pt.x += 3.0f;
		_isWalk = true;
	}
	if (KEYMANAGER->isStayKeyDown(VK_UP)) {
		_pt.y -= 3.0f;
		_isWalk = true;
	}
	if (KEYMANAGER->isStayKeyDown(VK_DOWN)) {
		_pt.y += 3.0f;
		_isWalk = true;
	}
	if (KEYMANAGER->isOnceKeyUp(VK_LEFT)) {
		_isWalk = false;
	}
	if (KEYMANAGER->isOnceKeyUp(VK_RIGHT)) {
		_isWalk = false;
	}
	if (KEYMANAGER->isOnceKeyUp(VK_UP)) {
		_isWalk = false;
	}
	if (KEYMANAGER->isOnceKeyUp(VK_DOWN)) {
		_isWalk = false;
	}
*/
	calulateStandard();
}

void gameScene::render(void)
{
	for (int i = _tmp.x - 2; i < _tmp.x + 3; ++i) {
		for (int j = _tmp.y - 1; j < _tmp.y + 2; ++j) {
			POINT _ttmp = CAMERAMANAGER->getAbsPosition({ i*TILESIZEX, j*TILESIZEY });
	//		IMAGEMANAGER->render(_tile[i][j], Rt, _ttmp.x, _ttmp.y);
		}
	}

	IMAGEMANAGER->alphaRender(L"노랑", Rt, 0, 0, 0.3);
	//IMAGEMANAGER->frameRender(L"캐릭터", Rt, WINSIZEX_NUM / 2 - 0.5 * (IMAGEMANAGER->findImage(L"캐릭터")->getWidth() / 10), WINSIZEY_NUM / 2 - 0.5 * (IMAGEMANAGER->findImage(L"캐릭터")->getHeight()), frame, 0);
	IMAGEMANAGER->alphaRender(L"노랑", Rt, 0, 0, 0.1);
	_character->render();

	Rt->FillRectangle(D2D1::RectF(0, 0, WINSIZEX_NUM, WINSIZEY_NUM), m_pRadialGradientBrush);

	Rt->SetTransform(D2D1::Matrix3x2F::Rotation(_time, D2D1::Point2F(1218, 46)));
	IMAGEMANAGER->render(L"시침", Rt, 1217, 6);
	Rt->SetTransform(D2D1::Matrix3x2F::Rotation(0, D2D1::Point2F(1218, 46)));

	_uimanager->render();
	_inventory->render();
}

void gameScene::calulateStandard()
{
	long i = _pt.x / TILESIZEX;
	long j = _pt.y / TILESIZEY;
	_tmp.x = i;
	_tmp.y = j;
}
