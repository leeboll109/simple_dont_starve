#pragma once
#include "gameNode.h"

enum ECLOCKSTATE { AFTERNOON, EVENING, NIGHT };

class Clock : public gameNode
{
private:
	//getWorldTime()을 int값으로 받아 저장하는 변수, 현재 시간 변수
	int _timetmp;
	int _time;

	int _timeFrameX;
	int _countFrame;
	//현재 맵의 상태를 나타내는 enum 구조체입니다
	ECLOCKSTATE _state;

public:
	Clock();
	~Clock();

	HRESULT init();
	void release();
	void update();
	void render();
};