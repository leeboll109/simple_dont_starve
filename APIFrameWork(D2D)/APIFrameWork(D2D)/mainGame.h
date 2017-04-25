#pragma once
#include "gameNode.h"
#include "gameScene.h"
#include "LoadingMainScene.h"
class mainGame : public gameNode
{
public:
	mainGame();
	~mainGame();

	HRESULT init(void);
	void release(void);
	void update(void);
	void render(void);
};