#include "stdafx.h"
#include "UImanager.h"


UImanager::UImanager()
{
}


UImanager::~UImanager()
{
}

HRESULT UImanager::init(void)
{
	_craft = new crafting;
	_craft->init();
	return S_OK;
}

void UImanager::release(void)
{
	_craft->release();
}

void UImanager::update(void)
{
	_craft->update();
}

void UImanager::render(void)
{
	_craft->render();
}