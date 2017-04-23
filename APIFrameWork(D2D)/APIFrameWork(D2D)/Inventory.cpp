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
}

void Inventory::deleteObjects(int integer)
{
	_viObjects = _vObjects.begin();
	_viObjects += integer;
	_vObjects.erase(_viObjects);
}