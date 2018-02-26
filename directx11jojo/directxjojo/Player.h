#pragma once
//#include "SGAActor.h"
#include "Character.h"
#include "UI.h"

class Player:
	public Character
{
public:
	Player();
	Player(SpriteBatch* pBatch, SGASpriteSheet *pSheet, SpriteFont * pFont);
	virtual ~Player();
public:
	virtual void Init(
		float moveSpeed,
		XMFLOAT2 startpos, E_SORTID eSortID);
	virtual E_SCENE Update(float dt);
protected:
	XMFLOAT2 mmousePos;
	XMFLOAT2 mvForward;	//���� ������ ����
	//UI *mpUi;
	//float mfMoveSpeed;	//�ʴ� �̵��Ÿ�
	//vector<vector<Vector2>> tilepos;
public:
	Vector2 mpCamerapos;
protected:
	virtual void UpdateMove(float dt);
public:

	void SetCamerapos(float x, float y) { mpCamerapos.x = x; mpCamerapos.y = y; }
};

