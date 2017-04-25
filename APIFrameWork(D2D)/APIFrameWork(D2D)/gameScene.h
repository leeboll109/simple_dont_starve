#pragma once
#include "gameNode.h"
#include "UImanager.h"
#include "inventory.h"
#include "Objects.h"
#include "Character.h"

class gameScene : public gameNode
{
private:
	Character* _character;
	UImanager* _uimanager;
	Inventory* _inventory;

	tstring _tile[TILEX][TILEY];
	POINT _tmp;

	OBJECT_ENVIRONMENT* _obj;

public:
	gameScene();
	~gameScene();

	HRESULT init(void);
	void release(void);
	void update(void);
	void render(void);

	void calulateStandard();
};