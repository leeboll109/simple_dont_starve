#pragma once
#include "gameNode.h"

enum ECLOCKSTATE { AFTERNOON, EVENING, NIGHT };

class Clock : public gameNode
{
private:
	//getWorldTime()�� int������ �޾� �����ϴ� ����, ���� �ð� ����
	int _timetmp;
	int _time;

	int _timeFrameX;
	int _countFrame;
	//���� ���� ���¸� ��Ÿ���� enum ����ü�Դϴ�
	ECLOCKSTATE _state;

public:
	Clock();
	~Clock();

	HRESULT init();
	void release();
	void update();
	void render();
};