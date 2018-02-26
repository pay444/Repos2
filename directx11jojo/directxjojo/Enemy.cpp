#include "stdafx.h"
#include "Enemy.h"


Enemy::Enemy()
{
}

Enemy::Enemy(SpriteBatch * pBatch, SGASpriteSheet * pSheet, SpriteFont * pFont)
	: Character(pBatch, pSheet, pFont)
{
}


Enemy::~Enemy()
{
}

void Enemy::Init(float moveSpeed, XMFLOAT2 startpos, E_SORTID eSortID)
{

	Character::Init();

	//SGAActor::Init(anim, 4, eSortID);
	mAnimName2 = "DOWN";
	SetAnimation(mAnimName2);
	SetPosition(startpos);
	mfMoveSpeed = moveSpeed;
	//mpJoAStar = make_unique<AStar>();

	//�ʱ� ��ġ�� ������ ���� ���ֱ�
	vector<unique_ptr<TILE>> * pVecTile = SGAActorManager::Instance().GetTileInfo();
	int istartIndex = GetTileIndex(mPosition);
	(*pVecTile)[istartIndex]->underObject = 1;
	(*pVecTile)[istartIndex]->byOption = 1;
	mPosition = XMFLOAT2((*pVecTile)[istartIndex]->vPos.x + JOJOTILESX / 2,
		(*pVecTile)[istartIndex]->vPos.y + JOJOTILESY / 2);
}

E_SCENE Enemy::Update(float dt)
{
	Character::Update(dt);

	//auto state = Keyboard::Get().GetState();

	//if (state.D2)
	//	meScene = E_SCENE_LOGO;
	//else if (state.D3)
	//	meScene = E_SCENE_STAGE;
	//else
	//	meScene = E_SCENE_NONPASS;

	//return meScene;

	return E_SCENE_NONPASS;
}
