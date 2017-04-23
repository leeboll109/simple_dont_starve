#include "stdafx.h"
#include "gameNode.h"


gameNode::gameNode()
{
}


gameNode::~gameNode()
{
}

HRESULT gameNode::init(void)
{
	_managerInit = false;
	return S_OK;
}

HRESULT gameNode::init(bool managerInit)
{
	Factory->CreateHwndRenderTarget(
		D2D1::RenderTargetProperties(),
		D2D1::HwndRenderTargetProperties(hWnd, D2D1::SizeU(WINSIZEX_NUM, WINSIZEY_NUM)),
		&Rt);

	Rt->CreateCompatibleRenderTarget(D2D1::SizeF(WINSIZEX_NUM, WINSIZEY_NUM), D2D1::SizeU(WINSIZEX_NUM, WINSIZEY_NUM), &CRt);

	Rt->CreateSolidColorBrush(D2D1::ColorF(D2D1::ColorF::White), &Brush);

	DWInit(L"나눔고딕", 15.0f, &WriteFactory, &TextFormat);

	_managerInit = managerInit;
	if (managerInit)
	{
		KEYMANAGER->init();					//키매니져 셋팅
		IMAGEMANAGER->init();				//이미지매니져 셋팅
		TIMEMANAGER->init();
		SOUNDMANAGER->init();
		SCENEMANAGER->init();				//씬매니져 셋팅
	}
	return S_OK;
}

void gameNode::release(void)
{
	if (_managerInit)
	{
		KEYMANAGER->releaseSingleton();
		//이미지매니져 해제, 싱글톤 해제
		IMAGEMANAGER->release();
		IMAGEMANAGER->releaseSingleton();
		//타임매니져 해제, 싱글톤 해제
		TIMEMANAGER->release();
		TIMEMANAGER->releaseSingleton();
		//씬매니져 해제, 싱글톤 해제
		SCENEMANAGER->release();
		SCENEMANAGER->releaseSingleton();
		//사운드 매니져 해제
		SOUNDMANAGER->release();
		SOUNDMANAGER->releaseSingleton();
	}
}

void gameNode::update(void)
{

}

void gameNode::render(void)
{

}
void gameNode::battleRender()
{

}

LRESULT gameNode::MainProc(HWND hWnd, UINT iMessage, WPARAM wParam, LPARAM lParam)
{
	//PAINTSTRUCT ps;
	//HDC hdc;

	switch (iMessage)
	{
	case WM_MOUSEMOVE:
		_ptMouse.x = static_cast<float>LOWORD(lParam);
		_ptMouse.y = static_cast<float>HIWORD(lParam);
		break;
	case WM_KEYDOWN:
		switch (wParam)
		{
			case VK_ESCAPE:
				PostMessage(hWnd, WM_DESTROY, 0, 0);
			break;
		}
		break;
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	}

	return (DefWindowProc(hWnd, iMessage, wParam, lParam));
}

bool gameNode::compare(gameNode* a, gameNode* b)
{
	if (a->getPos()->y <= b->getPos()->y)
	{
		return true;
	}
	else
	{
		return false;
	}

}