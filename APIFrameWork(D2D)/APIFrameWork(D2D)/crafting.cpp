#include "stdafx.h"
#include "crafting.h"


crafting::crafting()
{
}


crafting::~crafting()
{
}

HRESULT crafting::init(void)
{
	IMAGEMANAGER->addImage(Rt, L"craftingMenu", L"image/ui_1.png", 43, 462);

	_craftingKind[0] = IMAGEMANAGER->addImage(Rt, L"craftingKind_1", L"image/ui_1_1.png", 29, 38);
	_craftingKind[1] = IMAGEMANAGER->addImage(Rt, L"craftingKind_2", L"image/ui_1_2.png", 29, 38);
	_craftingKind[2] = IMAGEMANAGER->addImage(Rt, L"craftingKind_3", L"image/ui_1_3.png", 29, 38);
	_craftingKind[3] = IMAGEMANAGER->addImage(Rt, L"craftingKind_4", L"image/ui_1_4.png", 29, 38);
	_craftingKind[4] = IMAGEMANAGER->addImage(Rt, L"craftingKind_5", L"image/ui_1_5.png", 29, 38);
	_craftingKind[5] = IMAGEMANAGER->addImage(Rt, L"craftingKind_6", L"image/ui_1_6.png", 29, 38);
	_craftingKind[6] = IMAGEMANAGER->addImage(Rt, L"craftingKind_7", L"image/ui_1_7.png", 29, 38);
	_craftingKind[7] = IMAGEMANAGER->addImage(Rt, L"craftingKind_8", L"image/ui_1_8.png", 29, 38);
	_craftingKind[8] = IMAGEMANAGER->addImage(Rt, L"craftingKind_9", L"image/ui_1_9.png", 29, 38);
	_craftingKind[9] = IMAGEMANAGER->addImage(Rt, L"craftingKind_10", L"image/ui_1_10.png", 29, 38);

	return S_OK;
}

void crafting::release(void)
{
	//SAFE_DELETE(_craftingKind);
}

void crafting::update(void)
{
}

void crafting::render(void)
{
	IMAGEMANAGER->render(L"craftingMenu", Rt, 0, 129);

	for (int i = 0; i < 10; i++)
	{
		_craftingKind[i]->render(Rt, 0, 144 + i * 40);		//세로 38 + 간격 2
	}
}
