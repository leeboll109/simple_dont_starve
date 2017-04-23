#pragma once
#include "gameNode.h"
class LoadingMainScene : public gameNode
{
public:
	LoadingMainScene();
	~LoadingMainScene();

	HRESULT init(void);
	void release(void);
	void update(void);
	void render(void);

	void totalLoading();
};