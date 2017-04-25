#pragma once
#include "gameNode.h"
#include "Objects.h"

class Inventory : public gameNode
{
private:
	vector<OBJECT_IN_INVENTORY> _vObjects;
	vector<OBJECT_IN_INVENTORY>::iterator _viObjects;

	image* _invenItemSlot;
	image* _invenHandSlot;
	image* _invenArmorSlot;
	image* _invenHelmetSlot;

public:
	Inventory();
	~Inventory();

	HRESULT init();
	void release();
	void update();
	void render();

	inline void saveObject(OBJECT_IN_INVENTORY _obj) { _vObjects.push_back(_obj); }
	inline OBJECT_IN_INVENTORY loadObject(int integer) { return _vObjects[integer]; }

	void deleteObjects(int integer);
};