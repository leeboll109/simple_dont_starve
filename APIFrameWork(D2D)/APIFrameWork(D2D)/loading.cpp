#include "stdafx.h"
#include "loading.h"


loading::loading()
{
}


loading::~loading()
{
}

HRESULT loading::init()
{
	// Because the CreateWindow function takes its size in pixels,
	// obtain the system DPI and use it to scale the window size.
	FLOAT dpiX, dpiY;

	// The factory returns the current system DPI. This is also the value it will use
	// to create its own windows.
	Factory->GetDesktopDpi(&dpiX, &dpiY);

	_background = IMAGEMANAGER->addImage(Rt, L"loading", L"image/loadImage.png", WINSIZEX_NUM, WINSIZEY_NUM);

	_currentGauge = 0;
	return S_OK;
}

void loading::release()
{
}

void loading::update()
{
}

void loading::render()
{
	IMAGEMANAGER->render(L"loading", Rt);
}

void loading::loadImage(tstring keyName, const TCHAR * fileName, int width, int height)
{
	loadItem* item = new loadItem;
	item->initForImage(keyName, fileName, width, height);

	_vLoadItem.push_back(item);
}

void loading::loadImage(tstring keyName, const TCHAR * fileName, int x, int y, int width, int height)
{
	loadItem* item = new loadItem;
	item->initForImage(keyName, fileName, x,y,width, height);

	_vLoadItem.push_back(item);
}

void loading::loadFrameImage(tstring keyName, const TCHAR * fileName, int width, int height, int frameX, int frameY)
{
	loadItem* item = new loadItem;
	item->initForFrameImage(keyName, fileName, width, height, frameX, frameY);

	_vLoadItem.push_back(item);
}


BOOL loading::loadingDone()
{
	if (_currentGauge >= _vLoadItem.size()) return true;

	loadItem* item = _vLoadItem[_currentGauge];

	tagImageResource img = item->getImageResource();
	
	switch (item->getLoadingKind())
	{
	case LOAD_KIND_IMAGE_0:
		IMAGEMANAGER->addImage(Rt, img.keyName, img.fileName, img.width, img.height);
		break;
	case LOAD_KIND_IMAGE_1:
		IMAGEMANAGER->addImage(Rt, img.keyName, img.fileName, img.x, img.y, img.width, img.height);
		break;
	case LOAD_KIND_FRAMEIMAGE_0:
		IMAGEMANAGER->addFrameImage(Rt, img.keyName, img.fileName, img.width, img.height, img.frameX, img.frameY);
		break;
	case LOAD_KIND_SOUND:
		break;
	case LOAD_KIND_END:
		break;
	default:
		break;
	}

	// Ä«¿îÆ®
	_currentGauge++;

	return false;
}

HRESULT loadItem::initForImage(tstring keyName, const TCHAR * fileName, int width, int height)
{
	_kind = LOAD_KIND_IMAGE_0;
	memset(&_imageResource, 0, sizeof(tagImageResource));

	_imageResource.keyName = keyName;
	_imageResource.fileName = fileName;
	_imageResource.width = width;
	_imageResource.height = height;

	return S_OK;
}

HRESULT loadItem::initForImage(tstring keyName, const TCHAR * fileName, int x, int y, int width, int height)
{
	_kind = LOAD_KIND_IMAGE_1;
	memset(&_imageResource, 0, sizeof(tagImageResource));

	_imageResource.keyName = keyName;
	_imageResource.fileName = fileName;
	_imageResource.x = x;
	_imageResource.y = y;
	_imageResource.width = width;
	_imageResource.height = height;

	return S_OK;
}

HRESULT loadItem::initForFrameImage(tstring keyName, const TCHAR * fileName, int width, int height, int frameX, int frameY)
{
	_kind = LOAD_KIND_FRAMEIMAGE_0;
	memset(&_imageResource, 0, sizeof(tagImageResource));

	_imageResource.keyName = keyName;
	_imageResource.fileName = fileName;
	_imageResource.width = width;
	_imageResource.height = height;
	_imageResource.frameX = frameX;
	_imageResource.frameY = frameY;

	return S_OK;
}
