#pragma once
#include "gameNode.h"
#include "Crafting.h"
#include "Character.h"
#include "Clock.h"

#define STATMAX 50
#define REDUCEMENTAL 5
#define REDUCEHUNGER 5
#define STATIMAGE_FRAMEWIDTH 48
#define STATIMAGE_HEIGHT 48

class UImanager : public gameNode
{
private:
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

	//메뉴 버튼 입니다 (이미지 클래스 포인터 사용)
	image* _stopMenuButton;

	//스탑 메뉴버튼을 누를 경우 창이 뜨게 할 것인지의 불값입니다
	bool _stopMenuPopUp;

	//게임 그만 버튼, 게임 재개 버튼을 눌렀을 때의 불값입니다
	bool _stopMenuGameBreak;
	bool _stopMenuGameResume;

	//클래스 포인터
	Crafting* _craft;
	Character* _charc;
	Clock* _clock;

public:
	UImanager();
	~UImanager();

	HRESULT init(void);
	void release(void);
	void update(void);
	void render(void);

	//스탯 감소 함수
	void reduceStat(int& timeStat, int reduceValue, int& stat);

	//마우스가 스탯창에 가있느냐를 판별하는 함수
	void popUpCheck(bool& popUp, int x, int y);

	//하단의 일시정지 버튼을 눌렀는지 판별하는 함수
	void stopMenuUpCheck(bool& popUp, int x, int y);

	//마우스가 스탯창에 가있으면 현재 스탯을 뜨게 하는 함수(렌더)
	void popUpNumberRender(bool popUp, int stat, int x, int y);

	//스탑 메뉴를 뜨게 하는 함수(렌더) 
	// (메뉴 버튼 이미지 좌표를 여기서 설정하기 때문에 참조자를 사용합니다)
	void stopMenuRender(bool popUp, int x, int y);

	//스탑 메뉴안의 버튼을 눌렀는지 판별하는 함수
	void stopMenuButtonClickCheck(bool& popUpGameStop, bool& popUpGameResume, int x1, int y1, int x2, int y2);

	//스탑 메뉴의 버튼이 기능을 하도록 하는 함수
	void stopMenuButtonFunc(bool popUpGameStop, bool popUpGameResume, bool& popUp);

	inline void setHunger(int hunger) { _hunger = hunger; }
	inline void setHp(int hp) { _hp = hp; }
	inline void setMental(int mental) { _mental = mental; }

	inline void damageHunger(int damage) { _hunger -= damage; }
	inline void damageHp(int damage) { _hp -= damage; }
	inline void damageMental(int damage) { _mental -= damage; }

	inline void setCharcMemoryRick(Character* charc) { _charc = charc; }
};