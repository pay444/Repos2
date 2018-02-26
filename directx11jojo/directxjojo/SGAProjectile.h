#pragma once
//#include "SGAActor.h"
class SGAProjectile :
	public SGAActor
{
public:
	SGAProjectile();
	SGAProjectile(SpriteBatch *pBatch, SGASpriteSheet *pSheet,SpriteFont * pFont);
	virtual ~SGAProjectile();

public:
	virtual void Init(XMFLOAT2 position, XMFLOAT2 direction,
		float speed, float lifeTime, float ditance);
	virtual E_SCENE Update(float dt);

protected:
	XMFLOAT2	mvDirection;		//x,y�������ε� �Ѿ��� ���� ������
	float		mfSpeed;			//�ӵ�
	float		mfLifeTIme;			//�ð��� ������ �ڵ�������
	float		mfMaxDistance;		//�̸�ŭ �̵��ϸ� ������

protected:
	float		mfElapsedTime;		//����ð�
	float		mfDistance;			
};

