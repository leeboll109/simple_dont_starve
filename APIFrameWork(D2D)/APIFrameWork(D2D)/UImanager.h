#pragma once
#include "gameNode.h"
#include "crafting.h"
#include "Character.h"

#define STATMAX 50
#define REDUCEMENTAL 5
#define REDUCEHUNGER 5

class UImanager : public gameNode
{
private:
	int _time;

	//몇 초마다 스탯이 떨어질 것인지를 정하는 변수입니다
	int _timeMental;
	int _timeHunger;

	//테스트용!
	int _hp;
	int _hunger;
	int _mental;

	//스탯에 갖다댈 경우 현재 스탯 잔여량이 뜨게할 것인지의 불값입니다
	bool _hungerPopUp;
	bool _hpPopUp;
	bool _mentalPopUp;

	//클래스 포인터
	crafting* _craft;
	Character* _charc;

public:
	UImanager();
	~UImanager();

	HRESULT init(void);
	void release(void);
	void update(void);
	void render(void);

	inline void setHunger(int hunger) { _hunger = hunger; }
	inline void setHp(int hp) { _hp = hp; }
	inline void setMental(int mental) { _mental = mental; }

	inline void damageHunger(int damage) { _hunger -= damage; }
	inline void damageHp(int damage) { _hp -= damage; }
	inline void damageMental(int damage) { _mental -= damage; }

	inline int getTime() { return _time; }

	inline void setCharcMemoryRick(Character* charc) { _charc = charc; }
};