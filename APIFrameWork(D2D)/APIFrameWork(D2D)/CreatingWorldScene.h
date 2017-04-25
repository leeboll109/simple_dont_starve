#pragma once
#include "gameNode.h"
class CreatingWorldScene : public gameNode
{
public:
	CreatingWorldScene();
	~CreatingWorldScene();

	HRESULT init(void);
	void release(void);
	void update(void);
	void render(void);
};