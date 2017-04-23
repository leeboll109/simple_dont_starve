#pragma once
#include "image.h"
#include "ItemInfo.h"

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