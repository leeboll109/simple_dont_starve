#pragma once
#include "gameNode.h"

enum ECLOCKSTATE { AFTERNOON, EVENING, NIGHT };

class Clock : public gameNode
{
private:
	//���� ��¥�� �����ϴ� ����
	int _day;

	//getWorldTime()�� int������ �޾� �����ϴ� ����, ���� �ð� ����
	int _timetmp;
	int _time;

	int _timeFrameX;
	int _countFrame;

	//���� ���� ���¸� ��Ÿ���� enum ����ü
	ECLOCKSTATE _state;

public:
	Clock();
	~Clock();

	HRESULT init();
	void release();
	void update();
	void render();

	//���� �ð�->���� �ð����� ��ȯ�ϴ� �Լ��Դϴ�(interval : �����ð� �� �ʸ��� ���ӽð����� ��ȯ����)
	// (timetmp, time, day�� ���� �ٲ�Ƿ� ������ ���)
	void gameTimeConv(int interval, int& timetmp, int& time, int& day);

	//��, ����, ���� �Ǻ����ִ� �Լ��Դϴ�(state���� �ٲٱ⶧���� ������ ���)
	void whatState(ECLOCKSTATE& state, int time);

	//�ð��� �޸��� ������ �����ϱ� ���� �Լ��Դϴ�
	// (timeFrameX�� ���� �ٲ�Ƿ� ������ ���)
	void clockFrameFunc(int& timeFrameX);

	//���� state(��, ����, ��)�� ���� ������ �����ϴ� �Լ��Դϴ�
	void nowStateFunc(ECLOCKSTATE state);

	//���ڰ� ���� day���� ���� �����ϱ� ���� �Լ��Դϴ�
	void dayNumberRender(int day, int x, int y);
}; 

