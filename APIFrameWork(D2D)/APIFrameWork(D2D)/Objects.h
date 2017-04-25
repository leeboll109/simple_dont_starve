#pragma once
#include "gameNode.h"

class OBJECT_ENVIRONMENT : public gameNode { //환경요소(ex. 나무, 라즈베리덤불 등)
private:
	//물질요소 상호참조
	EOBJKIND_ENVIRONMENT _kind;				// 종류
	EOBJ_ENVIRONMENT_STATE _state;			// 현재상태
	float _inactivateTime;					// 비활성화된 시간
	float _regenerateTime;					// 재생시간
	int _hp;
	int _count;
	int _frame;
	POINT _pt;								// 위지좌표
	int _zOrder;							// Bottom 절대값
	EOBJKIND_MATERIAL _vDropItem[3];	// 비활성화시 드랍하는 아이템들

public:
	OBJECT_ENVIRONMENT() {}
	~OBJECT_ENVIRONMENT() {}

	HRESULT init(EOBJKIND_ENVIRONMENT kind, POINT pt);
	void release();
	void update();
	void render();

	void changeState(EOBJ_ENVIRONMENT_STATE state) { _state = state; }
	void Regenerate();
	void ifZeroHP();
	void damage(int damage) { _hp -= damage; }
};

class OBJECT_MATERIAL : public gameNode { //가공가능한요소(ex. 부싯돌, 나뭇가지 등)
private:
	EOBJKIND_MATERIAL _kind;
	POINT _pt;								// 위지좌표
	int _zOrder;

public:
	OBJECT_MATERIAL() {}
	~OBJECT_MATERIAL() {}

	HRESULT init(OBJECT_MATERIAL kind, POINT pt);
	void release();
	void update();
	void render();
};

class OBJECT_EQUIPMENT : public gameNode { //장착가능한요소(ex. 도끼, 곡괭이, 가방 등)
private:
	EOBJKIND_MATERIAL _kind;
	POINT _pt;								// 위지좌표
	int _zOrder;

public:
	OBJECT_EQUIPMENT() {}
	~OBJECT_EQUIPMENT() {}

	HRESULT init(OBJECT_EQUIPMENT kind, POINT pt);
	void release();
	void update();
	void render();
};

class OBJECT_ERECTION : public gameNode { //설치가능한요소(ex. 모닥불, 창고 등)
private:
	EOBJKIND_MATERIAL _kind;
	POINT _pt;								// 위지좌표
	int _zOrder;

public:
	OBJECT_ERECTION() {}
	~OBJECT_ERECTION() {}

	HRESULT init(OBJECT_ERECTION kind, POINT pt);
	void release();
	void update();
	void render();
};