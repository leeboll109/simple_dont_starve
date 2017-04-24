#include "stdafx.h"
#include "Inventory.h"


Inventory::Inventory()
{
}


Inventory::~Inventory()
{
}

HRESULT Inventory::init()
{
	IMAGEMANAGER->addImage(Rt, L"invenMenu", L"image/ui_4.png", 761, 47);

	_invenItemSlot = IMAGEMANAGER->addImage(Rt, L"invenBox", L"image/ui_inventorybox.png", 32, 32);
	_invenHandSlot = IMAGEMANAGER->addImage(Rt, L"invenHandBox", L"image/ui_inventoryhandbox.png", 32, 32);
	_invenArmorSlot = IMAGEMANAGER->addImage(Rt, L"invenArmorBox", L"image/ui_inventoryarmorbox.png", 32, 32);
	_invenHelmetSlot = IMAGEMANAGER->addImage(Rt, L"invenHelmetBox", L"image/ui_inventoryhelmetbox.png", 32, 32);

	return S_OK;
}

void Inventory::release()
{
}

void Inventory::update()
{
}

void Inventory::render()
{
	IMAGEMANAGER->render(L"invenMenu", Rt, 259, 673);

	for (int i = 0; i < 5; i++)
	{
		IMAGEMANAGER->render(L"invenBox", Rt, 290 + i * 38, 689);   // 가로 32 + 간격 6
	}

	for (int i = 0; i < 5; i++)
	{
		IMAGEMANAGER->render(L"invenBox", Rt, 489 + i * 38, 689);   // 가로 32 + 간격 6
	}

	for (int i = 0; i < 5; i++)
	{
		IMAGEMANAGER->render(L"invenBox", Rt, 684 + i * 38, 689);   // 가로 32 + 간격 6
	}

	IMAGEMANAGER->render(L"invenHandBox", Rt, 881, 689);
	IMAGEMANAGER->render(L"invenArmorBox", Rt, 919, 689);
	IMAGEMANAGER->render(L"invenHelmetBox", Rt, 957, 689);
}

void Inventory::deleteObjects(int integer)
{
	_viObjects = _vObjects.begin();
	_viObjects += integer;
	_vObjects.erase(_viObjects);
}