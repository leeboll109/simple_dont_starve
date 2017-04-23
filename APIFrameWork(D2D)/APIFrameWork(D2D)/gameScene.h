#pragma once
#include "gameNode.h"
#include "Character.h"

class gameScene : public gameNode
{
private:
	Character* _player;

public:
	gameScene();
	~gameScene();

	HRESULT init(void);
	void release(void);
	void update(void);
	void render(void);
};