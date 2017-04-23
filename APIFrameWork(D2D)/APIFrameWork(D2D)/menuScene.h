#pragma once
#include "gameNode.h"
class menuScene : public gameNode
{
public:
	menuScene();
	~menuScene();

	HRESULT init(void);
	void release(void);
	void update(void);
	void render(void);
};