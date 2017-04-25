#include "stdafx.h"
#include "Objects.h"

// 종류에 따라 스위치 구문으로 나누어 함수를 진행

HRESULT OBJECT_ENVIRONMENT::init(EOBJKIND_ENVIRONMENT kind, POINT pt)
{
	_kind = kind;
	_pt = pt;
	Regenerate();
	return S_OK;
}

void OBJECT_ENVIRONMENT::release(void)
{
}

void OBJECT_ENVIRONMENT::update(void)
{
	switch (_kind)
	{
	case FLOWER: {
		if (_state == EOBJ_ENVIRONMENT_STATE::EES_DEAD) {
			if (TIMEMANAGER->getWorldTime() - _inactivateTime >= _regenerateTime) {
				Regenerate();
			}
		}
		else {
			ifZeroHP();
		}
	}break;
	case TREE1: {
		if (_state == EOBJ_ENVIRONMENT_STATE::EES_DEAD) {
			if (TIMEMANAGER->getWorldTime() - _inactivateTime >= _regenerateTime) {
				Regenerate();
			}
		}
		else {
			switch (_state)
			{
			case EES_IDLE:
				_count++;
				_frame = _count / 2;
				if (_frame == 21) {
					_count = 0;
				}
				break;
			case EES_DEAD:
				break;
			case EES_LEFTDYING:
				break;
			case EES_RIGHTDYING:
				break;
			case EES_CHOPPED:
				break;
			case EES_DELETE:
				break;
			default:
				break;
			}
			ifZeroHP();
		}
	}break;
	case TREE2: {
	}break;
	case RASPBERRYSTACK: {
	}break;
	case ROCK: {
	}break;
	case HAYSTACK: {
	}break;
	default: {
	}break;
	}
}

void OBJECT_ENVIRONMENT::render(void)
{
	switch (_kind)
	{
	case FLOWER: {
		switch (_state)
		{
		case EES_IDLE:
			POINT _tmp = CAMERAMANAGER->getAbsPosition(_pt);
			IMAGEMANAGER->render(L"꽃", Rt, _tmp.x, _tmp.y);
			break;
		case EES_DEAD:
			break;
		case EES_LEFTDYING:
			break;
		case EES_RIGHTDYING:
			break;
		case EES_CHOPPED:
			break;
		case EES_DELETE:
			break;
		default:
			break;
		}
	}break;
	case TREE1: {
	}break;
	case TREE2: {
	}break;
	case RASPBERRYSTACK: {
	}break;
	case ROCK: {
	}break;
	case HAYSTACK: {
	}break;
	default: {
	}break;
	}
}

void OBJECT_ENVIRONMENT::Regenerate()
{
	_state = EOBJ_ENVIRONMENT_STATE::EES_IDLE;
	_inactivateTime = NULL;
	switch (_kind)
	{
	case FLOWER: {
		_inactivateTime = NULL;
		_regenerateTime = 5.0f;
		_hp = 1;
	}break;
	case TREE1: {
		_inactivateTime = NULL;
		_regenerateTime = 1000.0f;
		_hp = 4;
		_count = 0;
		_frame = 0;
	}break;
	case TREE2: {
	}break;
	case RASPBERRYSTACK: {
	}break;
	case ROCK: {
	}break;
	case HAYSTACK: {
	}break;
	default: {
	}break;
	}
}

void OBJECT_ENVIRONMENT::ifZeroHP()
{
	if (_hp == 0) {
		_state = EOBJ_ENVIRONMENT_STATE::EES_DEAD;
		_inactivateTime = TIMEMANAGER->getWorldTime();
	}
}

HRESULT OBJECT_ERECTION::init(OBJECT_ERECTION kind, POINT pt)
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

HRESULT OBJECT_EQUIPMENT::init(OBJECT_EQUIPMENT kind, POINT pt)
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

HRESULT OBJECT_MATERIAL::init(OBJECT_MATERIAL kind, POINT pt)
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