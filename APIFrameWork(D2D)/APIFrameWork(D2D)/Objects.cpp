#include "stdafx.h"
#include "Objects.h"

// 종류에 따라 스위치 구문으로 나누어 함수를 진행

HRESULT OBJECT_ENVIRONMENT::init(EOBJKIND_ENVIRONMENT kind)
{
	return S_OK;
}

void OBJECT_ENVIRONMENT::release(void)
{
}

void OBJECT_ENVIRONMENT::update(void)
{
}

void OBJECT_ENVIRONMENT::render(void)
{
}

void OBJECT_ENVIRONMENT::Regenerate()
{
	if (TIMEMANAGER->getWorldTime() - _inactivateTime >= _regenerateTime && _activation == false) {
		_activation = true;
	}
}

HRESULT OBJECT_ERECTION::init(OBJECT_ERECTION kind)
{
	return S_OK;
}

void OBJECT_ERECTION::release(void)
{
}

void OBJECT_ERECTION::update(void)
{
}

void OBJECT_ERECTION::render(void)
{
}

HRESULT OBJECT_EQUIPMENT::init(OBJECT_EQUIPMENT kind)
{
	return S_OK;
}

void OBJECT_EQUIPMENT::release(void)
{
}

void OBJECT_EQUIPMENT::update(void)
{
}

void OBJECT_EQUIPMENT::render(void)
{
}

HRESULT OBJECT_MATERIAL::init(OBJECT_MATERIAL kind)
{
	return S_OK;
}

void OBJECT_MATERIAL::release(void)
{
}

void OBJECT_MATERIAL::update(void)
{
}

void OBJECT_MATERIAL::render(void)
{
}