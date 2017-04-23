#pragma once
#include "gameNode.h"
#include "gameScene.h"
#include "LoadingMapScene.h"


class mainGame : public gameNode
{
private:
	int count;
	int frame;

	int _x, _y;
	POINT _tmp;
	POINT _standard;

	tstring _tile[100][100];

	bool _isWalk;
public:
	HRESULT init(void);
	void release(void);
	void update(void);
	void render(void);

	mainGame();
	~mainGame();

	void calulateStandard();
};