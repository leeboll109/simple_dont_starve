#pragma once
#include "gameNode.h"
#include "ItemInfo.h"

enum ECRAFTMENU { NONE, TOOLS, LIGHT };

class Crafting : public gameNode
{
private:
	bool _isOpen;
	ECRAFTMENU _isClick;

	image* _craftingKind[10];

public:
	Crafting();
	~Crafting();

	HRESULT init(void);
	void release(void);
	void update(void);
	void render(void);
};