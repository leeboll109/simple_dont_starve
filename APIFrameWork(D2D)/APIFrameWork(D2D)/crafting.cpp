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

	_craftingKind[0] = IMAGEMANAGER->findImage(L"craftingKind_1");
	_craftingKind[1] = IMAGEMANAGER->findImage(L"craftingKind_2");
	_craftingKind[2] = IMAGEMANAGER->findImage(L"craftingKind_3");
	_craftingKind[3] = IMAGEMANAGER->findImage(L"craftingKind_4");
	_craftingKind[4] = IMAGEMANAGER->findImage(L"craftingKind_5");
	_craftingKind[5] = IMAGEMANAGER->findImage(L"craftingKind_6");
	_craftingKind[6] = IMAGEMANAGER->findImage(L"craftingKind_7");
	_craftingKind[7] = IMAGEMANAGER->findImage(L"craftingKind_8");
	_craftingKind[8] = IMAGEMANAGER->findImage(L"craftingKind_9");
	_craftingKind[9] = IMAGEMANAGER->findImage(L"craftingKind_10");

	
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
