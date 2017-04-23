#include "stdafx.h"
#include "mainGame.h"

mainGame::mainGame()
{
}


mainGame::~mainGame()
{
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
}

void mainGame::render(void)
{

	Rt->BeginDraw();
	Rt->SetTransform(D2D1::Matrix3x2F::Identity());
	Rt->Clear();

	D2D1_RECT_F rect = D2D1::RectF(0, 0, WINSIZEX_NUM, WINSIZEY_NUM);
	//==================================================================
	SCENEMANAGER->render();
	TIMEMANAGER->render(Rt);
	//==================================================================
	Rt->EndDraw();

	gameNode::render();
}