#pragma once
#include "gameNode.h"
#include "Crafting.h"
#include "Character.h"
#include "Clock.h"

#define STATMAX 50
#define REDUCEMENTAL 5
#define REDUCEHUNGER 5
#define STATIMAGE_FRAMEWIDTH 48
#define STATIMAGE_HEIGHT 48

class UImanager : public gameNode
{
private:
	//�� �ʸ��� ������ ������ �������� ���ϴ� �����Դϴ�
	int _timeMental;
	int _timeHunger;

	//�׽�Ʈ��!
	int _hp;
	int _hunger;
	int _mental;

	//���ȿ� ���ٴ� ��� ���� ���� �ܿ����� �߰��� �������� �Ұ��Դϴ�
	bool _hungerPopUp;
	bool _hpPopUp;
	bool _mentalPopUp;

	//�޴� ��ư �Դϴ� (�̹��� Ŭ���� ������ ���)
	image* _stopMenuButton;

	//��ž �޴���ư�� ���� ��� â�� �߰� �� �������� �Ұ��Դϴ�
	bool _stopMenuPopUp;

	//���� �׸� ��ư, ���� �簳 ��ư�� ������ ���� �Ұ��Դϴ�
	bool _stopMenuGameBreak;
	bool _stopMenuGameResume;

	//Ŭ���� ������
	Crafting* _craft;
	Character* _charc;
	Clock* _clock;

public:
	UImanager();
	~UImanager();

	HRESULT init(void);
	void release(void);
	void update(void);
	void render(void);

	//���� ���� �Լ�
	void reduceStat(int& timeStat, int reduceValue, int& stat);

	//���콺�� ����â�� ���ִ��ĸ� �Ǻ��ϴ� �Լ�
	void popUpCheck(bool& popUp, int x, int y);

	//�ϴ��� �Ͻ����� ��ư�� �������� �Ǻ��ϴ� �Լ�
	void stopMenuUpCheck(bool& popUp, int x, int y);

	//���콺�� ����â�� �������� ���� ������ �߰� �ϴ� �Լ�(����)
	void popUpNumberRender(bool popUp, int stat, int x, int y);

	//��ž �޴��� �߰� �ϴ� �Լ�(����) 
	// (�޴� ��ư �̹��� ��ǥ�� ���⼭ �����ϱ� ������ �����ڸ� ����մϴ�)
	void stopMenuRender(bool popUp, int x, int y);

	//��ž �޴����� ��ư�� �������� �Ǻ��ϴ� �Լ�
	void stopMenuButtonClickCheck(bool& popUpGameStop, bool& popUpGameResume, int x1, int y1, int x2, int y2);

	//��ž �޴��� ��ư�� ����� �ϵ��� �ϴ� �Լ�
	void stopMenuButtonFunc(bool popUpGameStop, bool popUpGameResume, bool& popUp);

	inline void setHunger(int hunger) { _hunger = hunger; }
	inline void setHp(int hp) { _hp = hp; }
	inline void setMental(int mental) { _mental = mental; }

	inline void damageHunger(int damage) { _hunger -= damage; }
	inline void damageHp(int damage) { _hp -= damage; }
	inline void damageMental(int damage) { _mental -= damage; }

	inline void setCharcMemoryRick(Character* charc) { _charc = charc; }
};