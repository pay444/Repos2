#include "stdafx.h"
//#include "SGAActor.h"


SGAActor::SGAActor() : 
	mpSheet(NULL),
	mFrames(NULL),
	mpSpriteFrame(NULL),
	mfElapsedTime(0.0f),
	mPosition(0.0f, 0.0f),
	mWorldPos(0.0f,0.0f),
	mbDestroyed(false),
	mbEnabledCollision(true),
	mCamp(0),
	meSortID(E_SORTID_FOURTH),
	meScene(E_SCENE_NONPASS)
{
	mAnimations.clear();
}

SGAActor::SGAActor(SpriteBatch * pBatch, SGASpriteSheet * pSheet, SpriteFont * pFont)
	: SGAActor() // c++11 ���ķ� �⺻ �����ڸ� �ҷ��ü�����
{
	mpSheet = pSheet;
	mpBatch = pBatch;
	mpFont = pFont;
}


SGAActor::~SGAActor()
{
	//int x = 0;
}

void SGAActor::Init(SpriteBatch* pBatch, SGASpriteSheet *pSheet, Animation *anims, int animCount,E_SORTID eSortID)
{
	mpSheet = pSheet;
	mpBatch = pBatch;

	Init(anims, animCount, eSortID); //������ �Ǵ� �κе��� ���� �Լ��ν� ����ؾ���
}

void SGAActor::Init(Animation * anims, int animCount,E_SORTID eSortID)
{
	for (int i = 0; i < animCount; ++i)
	{
		vector<FrameInfo> frames;
		for (int j = 0; j < anims[i].TotalFrames; ++j)
		{
			FrameInfo frame;
			frame.DelayPerFrame = anims[i].FrameInfos[j].DelayPerFrame;
			frame.FrameName = anims[i].FrameInfos[j].FrameName;
			frames.push_back(frame);
		}

		mAnimations.insert(pair<string, vector<FrameInfo>>(anims[i].Name, frames));
	}
	meSortID = eSortID;
}

void SGAActor::Init(Animation * anims, int animCount)
{
	for (int i = 0; i < animCount; ++i)
	{
		vector<FrameInfo> frames;
		for (int j = 0; j < anims[i].TotalFrames; ++j)
		{
			FrameInfo frame;
			frame.DelayPerFrame = anims[i].FrameInfos[j].DelayPerFrame;
			frame.FrameName = anims[i].FrameInfos[j].FrameName;
			frames.push_back(frame);
		}

		mAnimations.insert(pair<string, vector<FrameInfo>>(anims[i].Name, frames));
	}
}

E_SCENE SGAActor::Update(float dt)
{
	if (mpSheet == NULL)
		return E_SCENE_NONPASS;

	mfElapsedTime += dt;

	if (mFrames == NULL)
		return E_SCENE_NONPASS;

	if (mCurFrame->DelayPerFrame != 0.0f && mfElapsedTime > mCurFrame->DelayPerFrame)
	{
		mCurFrame++;
		mfElapsedTime = 0.0f;
		if (mCurFrame == mFrames->cend())
			mCurFrame = mFrames->begin();

		mpSpriteFrame = mpSheet->Find(mCurFrame->FrameName.c_str());
	}

	return meScene;
}

void SGAActor::Draw()
{
	if (mpBatch == NULL || mpSheet == NULL)
		return;

	if (mpSpriteFrame == NULL)
		return;

	mpSheet->Draw(mpBatch, *mpSpriteFrame, mPosition);
}

void SGAActor::SetAnimation(string name)
{
	if (mCurAnim == name)
		return;

	mCurAnim = name;

	auto result = mAnimations.find(name);

	if (result == mAnimations.cend())
	{
		OutputDebugString(L"Can not find animation!");
		return;
	}

	mFrames = &result->second;
	mCurFrame = result->second.begin();
	mfElapsedTime = 0.0f;
	mpSpriteFrame = mpSheet->Find(mCurFrame->FrameName.c_str());
}

bool SGAActor::IntersecRect(SGAActor* pActor)
{
	RECT src = GetBound();
	RECT trg = pActor->GetBound();
	RECT intersect;
	return	::IntersectRect(&intersect, &src, &trg);
}

int SGAActor::GetTileIndex(const Vector2 vPos)
{
	const vector<unique_ptr<TILE>>* spVecTIle =
		SGAActorManager::Instance().GetTileInfo();

	for (UINT i = 0; i < spVecTIle->size(); ++i)
	{
		if (CollisionMouseToTile(vPos, (*spVecTIle)[i].get()))
			return i;
	}
	return -1;
}

bool SGAActor::CollisionMouseToTile(const Vector2 vPos, const TILE * pTileInfo)
{
	Vector2 vPoint[4];
	vPoint[0] = Vector2(
		pTileInfo->vPos.x,
		pTileInfo->vPos.y);	// ��������
	vPoint[1] = Vector2(
		pTileInfo->vPos.x + JOJOTILESX,
		pTileInfo->vPos.y);	// ������ ����
	vPoint[2] = Vector2(
		pTileInfo->vPos.x,
		pTileInfo->vPos.y + JOJOTILESY);	// ���� �Ʒ���
	vPoint[3] = Vector2(
		pTileInfo->vPos.x + JOJOTILESX,
		pTileInfo->vPos.y + JOJOTILESY);	// ������ �Ʒ���

	if ((vPos.x >= vPoint[0].x && vPos.y >= vPoint[0].y) && // ���� ����,
		(vPos.x <= vPoint[1].x && vPos.y >= vPoint[1].y) && // ������ ����,
		(vPos.x >= vPoint[2].x && vPos.y <= vPoint[2].y) &&// ���� �Ʒ���
		(vPos.x <= vPoint[3].x && vPos.y <= vPoint[3].y))  // ������ �Ʒ���
	{
		return true;
	}
	return false;
}
