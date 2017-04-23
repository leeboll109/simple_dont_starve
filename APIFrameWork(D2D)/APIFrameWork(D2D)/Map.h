#pragma once
#include "gameNode.h"
#include "Objects.h"
#include "Tiles.h"

class Map : public gameNode
{
private:
	// Tiles tile[tileMax];
	// vector<Objects> _vObject;
	// vector<Objects>::iterator _viObject;

public:
	Map();
	~Map();

	HRESULT init(void);
	void release(void);
	void update(void);
	void render(void);
};