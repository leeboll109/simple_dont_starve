#include "stdafx.h"
#include "LoadingMapScene.h"


LoadingMapScene::LoadingMapScene()
{
}


LoadingMapScene::~LoadingMapScene()
{
}

HRESULT LoadingMapScene::init(void)
{
	_loading = new loading;
	_loading->init();

	this->totalLoading();
	// 파일 위치 인덱스
	/*wcscat(directory, L"image/player/");

	wcscat(directoryName[NONE_DOWN], L"_down.png");
	wcscat(directoryName[NONE_SIDE], L"_side.png");
	wcscat(directoryName[NONE_UP], L"_up.png");
	wcscat(directoryName[PRE_DOWN], L"_pre_down.png");
	wcscat(directoryName[PRE_SIDE], L"_pre_side.png");
	wcscat(directoryName[PRE_UP], L"_pre_down.png");
	wcscat(directoryName[LOOP_DOWN], L"_loop_down.png");
	wcscat(directoryName[LOOP_SIDE], L"_loop_side.png");
	wcscat(directoryName[LOOP_UP], L"_loop_up.png");
	wcscat(directoryName[PST_DOWN], L"_pst_down.png");
	wcscat(directoryName[PST_SIDE], L"_pst_side.png");
	wcscat(directoryName[PST_UP], L"_pst_up.png");*/
	return S_OK;
}

void LoadingMapScene::release(void)
{
}

void LoadingMapScene::update(void)
{
	_loading->update();
	if (_loading->loadingDone()) {
		SCENEMANAGER->changeScene("gameScene");
	}
}

void LoadingMapScene::render(void)
{
	_loading->render();
}

void LoadingMapScene::totalLoading()
{
	// Because the CreateWindow function takes its size in pixels,
	// obtain the system DPI and use it to scale the window size.
	FLOAT dpiX, dpiY;

	// The factory returns the current system DPI. This is also the value it will use
	// to create its own windows.
	Factory->GetDesktopDpi(&dpiX, &dpiY);

	// 배경
	_loading->loadImage(L"ground", L"image/ground.png", WINSIZEX_NUM, WINSIZEY_NUM);

	// wake up
	_loading->loadFrameImage(L"player_wakeup", L"image/player/player_wakeup_f45.png", 4950, 100, 45, 1);

	// idle
	_loading->loadFrameImage(L"player_idle_down", L"image/player/idle/player_idle_down.png", 630, 100, 10, 1);
	_loading->loadFrameImage(L"player_idle_up", L"image/player/idle/player_idle_up.png", 630, 100, 10, 1);
	_loading->loadFrameImage(L"player_idle_side", L"image/player/idle/player_idle_side.png", 630, 100, 10, 1);

	// run
	_loading->loadFrameImage(L"player_run_pre_down", L"image/player/run/player_run_pre_down.png", 630, 100, 10, 1);
	_loading->loadFrameImage(L"player_run_pre_side", L"image/player/run/player_run_pre_side.png", 630, 100, 10, 1);
	_loading->loadFrameImage(L"player_run_pre_up", L"image/player/run/player_run_pre_up.png", 630, 100, 10, 1);
	_loading->loadFrameImage(L"player_run_loop_down", L"image/player/run/player_run_loop_down.png", 630, 100, 10, 1);
	_loading->loadFrameImage(L"player_run_loop_side", L"image/player/run/player_run_loop_side.png", 630, 100, 10, 1);
	_loading->loadFrameImage(L"player_run_loop_up", L"image/player/run/player_run_loop_up.png", 630, 100, 10, 1);
	_loading->loadFrameImage(L"player_run_pst_down", L"image/player/run/player_run_pst_down.png", 630, 100, 10, 1);
	_loading->loadFrameImage(L"player_run_pst_side", L"image/player/run/player_run_pst_side.png", 630, 100, 10, 1);
	_loading->loadFrameImage(L"player_run_pst_up", L"image/player/run/player_run_pst_up.png", 630, 100, 10, 1);
	// item
	//IMAGEMANAGER->addFrameImage(Rt, L"player_idle_down", L"image/player/idle/player_idle_down", 630, 100, 10, 1);
	//IMAGEMANAGER->addFrameImage(Rt, L"player_idle_down", L"image/player/idle/player_idle_down", 630, 100, 10, 1);
	//IMAGEMANAGER->addFrameImage(Rt, L"player_idle_down", L"image/player/idle/player_idle_down", 630, 100, 10, 1);
}
