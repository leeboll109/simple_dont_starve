#pragma once
#include "gameNode.h"
#include "Objects.h"

class Inventory : public gameNode
{
private:
	vector<Objects> _vObjects;
	vector<Objects>::iterator _viObjects;

public:
	Inventory();
	~Inventory();

	HRESULT init();
	void release();
	void update();
	void render();

	inline void saveObject(Objects _obj) { _vObjects.push_back(_obj); }
	inline Objects loadObject(int integer) { return _vObjects[integer]; }

	void deleteObjects(int integer);
};