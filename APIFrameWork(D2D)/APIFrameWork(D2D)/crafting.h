#pragma once
#include "gameNode.h"
#include "ItemInfo.h"
enum ECRAFTMENU {NONE, TOOLS, LIGHT};

class crafting : public gameNode
{
private:
	bool _isOpen;
	ECRAFTMENU _isClick;

public:
	crafting();
	~crafting();

	HRESULT init(void);
	void release(void);
	void update(void);
	void render(void);
};