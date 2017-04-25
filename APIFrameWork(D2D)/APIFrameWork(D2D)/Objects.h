#pragma once
#include "gameNode.h"

class OBJECT_ENVIRONMENT : public gameNode { //ȯ����(ex. ����, ��������� ��)
private:
	//������� ��ȣ����
	EOBJKIND_ENVIRONMENT _kind;				// ����
	EOBJ_ENVIRONMENT_STATE _state;			// �������
	float _inactivateTime;					// ��Ȱ��ȭ�� �ð�
	float _regenerateTime;					// ����ð�
	int _hp;
	int _count;
	int _frame;
	POINT _pt;								// ������ǥ
	int _zOrder;							// Bottom ���밪
	EOBJKIND_MATERIAL _vDropItem[3];	// ��Ȱ��ȭ�� ����ϴ� �����۵�

public:
	OBJECT_ENVIRONMENT() {}
	~OBJECT_ENVIRONMENT() {}

	HRESULT init(EOBJKIND_ENVIRONMENT kind, POINT pt);
	void release();
	void update();
	void render();

	void changeState(EOBJ_ENVIRONMENT_STATE state) { _state = state; }
	void Regenerate();
	void ifZeroHP();
	void damage(int damage) { _hp -= damage; }
};

class OBJECT_MATERIAL : public gameNode { //���������ѿ��(ex. �ν˵�, �������� ��)
private:
	EOBJKIND_MATERIAL _kind;
	POINT _pt;								// ������ǥ
	int _zOrder;

public:
	OBJECT_MATERIAL() {}
	~OBJECT_MATERIAL() {}

	HRESULT init(OBJECT_MATERIAL kind, POINT pt);
	void release();
	void update();
	void render();
};

class OBJECT_EQUIPMENT : public gameNode { //���������ѿ��(ex. ����, ���, ���� ��)
private:
	EOBJKIND_MATERIAL _kind;
	POINT _pt;								// ������ǥ
	int _zOrder;

public:
	OBJECT_EQUIPMENT() {}
	~OBJECT_EQUIPMENT() {}

	HRESULT init(OBJECT_EQUIPMENT kind, POINT pt);
	void release();
	void update();
	void render();
};

class OBJECT_ERECTION : public gameNode { //��ġ�����ѿ��(ex. ��ں�, â�� ��)
private:
	EOBJKIND_MATERIAL _kind;
	POINT _pt;								// ������ǥ
	int _zOrder;

public:
	OBJECT_ERECTION() {}
	~OBJECT_ERECTION() {}

	HRESULT init(OBJECT_ERECTION kind, POINT pt);
	void release();
	void update();
	void render();
};