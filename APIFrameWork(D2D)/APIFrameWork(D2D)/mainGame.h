#pragma once
#include "gameNode.h"
#include "gameScene.h"
#include "LoadingMapScene.h"


class mainGame : public gameNode
{
public:
	HRESULT init(void);
	void release(void);
	void update(void);
	void render(void);

	mainGame();
	~mainGame();
};