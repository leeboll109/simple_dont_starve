#pragma once
enum EOBJKIND_ENVIRONMENT {FLOWER, TREE1, TREE2, RASPBERRYSTACK, ROCK, HAYSTACK/*건초더미*/};
enum EOBJKIND_MATERIAL { FLINT/*부싯돌*/, STONE, CARROT, RASPBERRY, BRANCH, LOG, HAY};
enum EOBJKIND_EQUIPMENT {AXE, PICKAXE/*곡괭이*/, TORCH/*횃불*/, BAG};
enum EOBJKIND_ERECTION {BONFIRE/*모닥불*/, STORAGE/*저장소*/};

/*
struct OBJECT_ENVIRONMENT { //환경요소(ex. 나무, 라즈베리덤불 등)
	tstring _imageKey[2];				// [0]에 활성화중이미지키
										// [1]에 비활성화중이미지키
	EOBJKIND_ENVIRONMENT _kind;			// 종류
	bool _activation;					// 활성화유무
	int _regenerateTime;				// 재생시간
	float _x, _y;						// 위지좌표
	vector<OBJECT_MATERIAL> _vDropItem;	// 비활성화시 드랍하는 아이템들
};

struct OBJECT_MATERIAL { //가공가능한요소(ex. 부싯돌, 나뭇가지 등)
	tstring _imageKey;
	EOBJKIND_MATERIAL _kind;
	float _x, _y;
};

struct OBJECT_EQUIPMENT { //장착가능한요소(ex. 도끼, 곡괭이, 가방 등)
	tstring _imageKey;
	EOBJKIND_EQUIPMENT _kind;
	float _x, _y;
};

struct OBJECT_ERECTION { //설치가능한요소(ex. 모닥불, 창고 등)
	tstring _imageKey;
	EOBJKIND_ERECTION _kind;
	float _x, _y;
};
*/