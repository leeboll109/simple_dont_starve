#pragma once
#include "image.h"
#include "ItemInfo.h"

#define TILEX 100
#define TILEY 100
#define TILESIZEX 512
#define TILESIZEY 512
#define MAPMAX_X 512*100
#define MAPMAX_Y 512*100


class gameNode
{
protected:
	tagPos _pos;
private:
	bool _managerInit;
public:
	virtual HRESULT init(void);
	virtual HRESULT init(bool managerInit);
	virtual void release(void);
	virtual void update(void);
	virtual void render(void);
	virtual void battleRender();

	//메인 프로시져
	LRESULT MainProc(HWND hWnd, UINT iMessage, WPARAM wParam, LPARAM lParam);

	gameNode();
	virtual ~gameNode();

	tagPos* getPos() { return &_pos; }
	void setPos(int x, int y) { _pos.x = x; _pos.y = y; }

	bool compare(gameNode* a, gameNode* b);
};