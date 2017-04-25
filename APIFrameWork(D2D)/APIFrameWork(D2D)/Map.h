#pragma once
#include "gameNode.h"
#include "Objects.h"
#include "Tiles.h"
#include "Character.h"
#include "Minimap.h"

class Map : public gameNode
{
private:
	Tiles _tile[TILEX][TILEY];
	map<POINT, vector<OBJECT_ENVIRONMENT>> _mObjEnvi;

public:
	Map();
	~Map();

	HRESULT init(void);
	void release(void);
	void update(void);
	void render(void);
};