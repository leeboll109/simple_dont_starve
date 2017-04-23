#pragma once
#include "gameNode.h"
#include "crafting.h"

class UImanager : public gameNode
{
private:
	int _time;
	int _hp;
	int _mental;
	int _hunger;

	bool _PopUp;

	crafting* _craft;

public:
	UImanager();
	~UImanager();

	HRESULT init(void);
	void release(void);
	void update(void);
	void render(void);

	inline void setHP(int hp) { _hp = hp; }
	inline void setMENTAL(int mental) { _mental = mental; }
	inline void setHUNGER(int hunger) { _hunger = hunger; }

	inline bool getPopUP() { return _PopUp; }
	inline int getTime() { return _time; }
};