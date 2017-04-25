#include "stdafx.h"
#include "Clock.h"


Clock::Clock()
{
}


Clock::~Clock()
{
}

HRESULT Clock::init()
{
	IMAGEMANAGER->addImage(Rt, L"clock", L"image/ui_clock.png", 71, 71);
	IMAGEMANAGER->addImage(Rt, L"clockNeedle", L"image/ui_clockneedle.png", 16, 53);
	IMAGEMANAGER->addFrameImage(Rt, L"clockRoundAfternoon", L"image/ui_clockroundafternoon.png", 1260, 94, 14, 1);
	IMAGEMANAGER->addFrameImage(Rt, L"clockRoundNight", L"image/ui_clockroundnight.png", 1260, 94, 14, 1);

	//변수 초기화입니다
	_time = 0;
	_timetmp = 0;
	_state = EVENING;

	_timeFrameX = _countFrame = 0;

	return S_OK;
}

void Clock::release()
{
}

void Clock::update()
{
	//1초마다 timetmp에 getWorldTime()을 저장합니다
	if ((int)TIMEMANAGER->getWorldTime() % 1 == 0 && (int)TIMEMANAGER->getWorldTime() != _timetmp) {
		_timetmp = (int)TIMEMANAGER->getWorldTime();
		_time++;

		//360초일때 타임 초기화합니다
		if (_time == 360) _time = 0;
	}

	//state값을 업데이트 해줍니다
	if (_time >= 0 && _time < 180) _state = AFTERNOON;
	if (_time >= 180 && _time < 315) _state = EVENING;
	if (_time >= 315 && _time < 360) _state = NIGHT;

	//프레임 렌더를 돌립니다
	_timeFrameX++;
	if (_timeFrameX > 13)
	{
		_timeFrameX = 0;
	}

	//낮일 경우
	if (_state == AFTERNOON) {
	}

	//저녁일 경우
	else if (_state == EVENING) {
	}

	//밤일 경우
	else if (_state == NIGHT) {
	}
}

void Clock::render()
{
	//상태에 따라서 렌더합니다
	if (_state == AFTERNOON) IMAGEMANAGER->frameCenterRender(L"clockRoundAfternoon", Rt, 1219, 46, _timeFrameX, 0);
	if (_state == NIGHT) IMAGEMANAGER->frameCenterRender(L"clockRoundNight", Rt, 1218.5f, 46, _timeFrameX, 0);

	IMAGEMANAGER->render(L"clock", Rt, 1183, 11);

	Rt->SetTransform(D2D1::Matrix3x2F::Rotation(_time, D2D1::Point2F(1218.5f, 46.5f)));
	IMAGEMANAGER->render(L"clockNeedle", Rt, 1209.5f, 3.5f);
	Rt->SetTransform(D2D1::Matrix3x2F::Rotation(0, D2D1::Point2F(1218.5f, 46.5f)));
	
	//필터추가
}