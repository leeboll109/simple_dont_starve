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
	_player = new Character;
	_player->init();

	return S_OK;
}

void gameScene::release(void)
{
	SAFE_DELETE(_player);
}

void gameScene::update(void)
{
	_player->update();
}

void gameScene::render(void)
{
	_player->render();
}
