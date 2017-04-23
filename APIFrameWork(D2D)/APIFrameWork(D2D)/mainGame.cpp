#include "stdafx.h"
#include "mainGame.h"
#include "d2d1effects.h"
#define MAPMAX_X 512*100
#define MAPMAX_Y 512*100

mainGame::mainGame()
{
}


mainGame::~mainGame()
{
}

void mainGame::calulateStandard()
{
	POINT _pt = { _x, _y };
	for (int i = 0; i < 100; ++i) {
		for (int j = 0; j < 100; ++j) {
			if (IsInRect(_pt, { 512 * i, 512 * j , 512 * i + 512 , 512 * j + 512 })) {
				_tmp.x = i;
				_tmp.y = j;
				_standard.x = _x - 512 * (i + 1) + 256;
				_standard.y = _y - 512 * (j + 1) + 256;
				break;
			}
		}
	}
}

HRESULT mainGame::init(void)
{
	gameNode::init(true);

	SCENEMANAGER->addScene("gameScene", new gameScene);
	SCENEMANAGER->addScene("loadingGame", new LoadingMapScene);

	SCENEMANAGER->changeScene("loadingGame");

	return S_OK;
}

void mainGame::release(void)
{
	gameNode::release();
}

void mainGame::update(void)
{
	gameNode::update();
	SOUNDMANAGER->update();
	SCENEMANAGER->update();

	/*count++;
	frame = count / 2;
	if (frame == 20) {
		count = 0;
	}
	if (KEYMANAGER->isStayKeyDown(VK_LEFT)) {
		_x -= 3.0f;
		_isWalk = true;
	}
	if (KEYMANAGER->isStayKeyDown(VK_RIGHT)) {
		_x += 3.0f;
		_isWalk = true;
	}
	if (KEYMANAGER->isStayKeyDown(VK_UP)) {
		_y -= 3.0f;
		_isWalk = true;
	}
	if (KEYMANAGER->isStayKeyDown(VK_DOWN)) {
		_y += 3.0f;
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
	if (_isWalk) {
		if (!SOUNDMANAGER->isPlaySound("발걸음")) {
			SOUNDMANAGER->play("발걸음");
		}
	}
	calulateStandard();
	if (KEYMANAGER->isOnceKeyDown('E')) {
		int a = 0;
	}*/
}

void mainGame::render(void)
{

	Rt->BeginDraw();
	Rt->SetTransform(D2D1::Matrix3x2F::Identity());
	Rt->Clear();

	D2D1_RECT_F rect = D2D1::RectF(0, 0, WINSIZEX_NUM, WINSIZEY_NUM);
	//==================================================================
	SCENEMANAGER->render();

	//IMAGEMANAGER->render(_tile[_tmp.x][_tmp.y], Rt, -620 + 2 * 512 - _standard.x, -408 + 512 - _standard.y);
	/*
	for (int i = _tmp.x - 2 ; i < _tmp.x + 3; ++i) {
		for (int j = _tmp.y - 1; j < _tmp.y + 2; ++j) {
			IMAGEMANAGER->render(_tile[i][j], Rt,  -620  + (i - (_tmp.x - 2)) * 512 - _standard.x, -408 + (j - (_tmp.y - 1)) * 512 - _standard.y);
		}
	}

	IMAGEMANAGER->alphaRender(L"노랑", Rt, 0, 0, 0.3);

	IMAGEMANAGER->frameRender(L"캐릭터", Rt, WINSIZEX_NUM / 2 - 0.15 * (IMAGEMANAGER->findImage(L"캐릭터")->getWidth()/10), WINSIZEY_NUM / 2 - 0.5 * (IMAGEMANAGER->findImage(L"캐릭터")->getHeight()), frame, 0);
	IMAGEMANAGER->alphaRender(L"노랑", Rt, 0, 0, 0.1);
*/
	//IMAGEMANAGER->render(L"ground", Rt);

	//IMAGEMANAGER->frameRender(L"player_wakeup", Rt, 0, 0, 0, 0);

	TIMEMANAGER->render(Rt);
	//==================================================================
	Rt->EndDraw();

	gameNode::render();
}