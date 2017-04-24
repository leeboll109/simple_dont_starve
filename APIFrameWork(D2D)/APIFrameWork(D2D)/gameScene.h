#pragma once
#include "gameNode.h"
#include "Character.h"
#include "UImanager.h"
#include "inventory.h"
class gameScene : public gameNode
{
private:
	UImanager* _uimanager;
	Inventory* _inventory;

	int count;
	int frame;

	POINT _pt;
	POINT _tmp;

	tstring _tile[TILEX][TILEY];

	int  _time;
	bool _isWalk;

public:
	gameScene();
	~gameScene();

	HRESULT init(void);
	void release(void);
	void update(void);
	void render(void);

	void calulateStandard();
};