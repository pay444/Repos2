#include "stdafx.h"
//#include "SGAActor.h"
#include "MoveBox.h"


MoveBox::MoveBox() :SGAActor(),
mSeekScope(false)
{
	mAnimations.clear();
}

MoveBox::MoveBox(SpriteBatch * pBatch, SGASpriteSheet * pSheet, SpriteFont * pFont)
	:SGAActor(pBatch, pSheet, pFont),
	mSeekScope(false),
	mpPlayer(nullptr)
{

}


MoveBox::~MoveBox()
{
}

void MoveBox::Init(E_SORTID eSortID, XMFLOAT2 pos, float limitDis, bool visible)
{
	//MoveBox(pBatch, pSheet, pFont);

	//mpBatch = pBatch;
	//mpSheet = pSheet;
	//mpFont = pFont;

	Animation anim[] = {
		{ "CursorBox", 2,{ { "CursorBox0", 0.3f },
		{ "CursorBox1", 0.3f }, }
		},
	};
	//�Ѱ�Ÿ�
	mLimitDis = limitDis;
	//�̵��Ÿ�
	//mMoveDistance = moveDis;
	//���̰� �Ⱥ��̰�
	mVisible = visible;
	SGAActor::Init(anim, 1, eSortID);
	SetPosition(pos);
	SetAnimation("CursorBox");

}

void MoveBox::Init(SpriteBatch* pBatch, SGASpriteSheet *pSheet, SpriteFont *pFont, E_SORTID eSortID, XMFLOAT2 pos, float limitDis, bool visible)
{
	SGAActor();

	//mAnimations.clear();

	mpBatch = pBatch;
	mpSheet = pSheet;
	mpFont = pFont;

	Animation anim[] = {
		{ "CursorBox", 2,{ { "CursorBox0", 0.3f },
		{ "CursorBox1", 0.3f }, }
		},
	};
	//�Ѱ�Ÿ�
	mLimitDis = limitDis;
	//�̵��Ÿ�
	//mMoveDistance = moveDis;
	//���̰� �Ⱥ��̰�
	mVisible = visible;
	SGAActor::Init(anim, 1, eSortID);
	SetPosition(pos);
	SetAnimation("CursorBox");
}

E_SCENE MoveBox::Update(float dt)
{
	E_SCENE eResult = SGAActor::Update(dt);

	if (eResult > E_SCENE_NONPASS)
		return eResult;

	return E_SCENE_NONPASS;
}

void MoveBox::Draw()
{
	XMFLOAT2 offset = XMFLOAT2(0, 0);
	Color tint = Colors::White;

	offset.x = (int)ScrollMgr::Instance().GetScroll().x;
	offset.y = (int)ScrollMgr::Instance().GetScroll().y;

	vector<unique_ptr<TILE>> *pVecTile = SGAActorManager::Instance().GetTileInfo();
	//XMFLOAT2 pos1, pos2, pos3;
	//pos1 = XMFLOAT2(24.0f, 24.0f);
	//pos2 = XMFLOAT2(24.0f + 24.0f, 24.0f);
	//pos3 = XMFLOAT2(24.0f + 48.0f, 24.0f);

	//vector<XMFLOAT2> vecpos;
	//vecpos.push_back(pos1);
	//vecpos.push_back(pos2);
	//vecpos.push_back(pos3);

	//if (mVisible)
	//{
	//	TileScope();
	//	mSeekScope = ScopeSeek();
	//	for (int x = 0; x < vecScopePos.size(); ++x)
	//	{
	//		mpSheet->Draw(mpBatch, *mpSpriteFrame, mWorldPos + vecScopePos[x] - offset, tint);
	//	}
	//	vecScopePos.clear();
	//}

	if (mVisible)
	{
		TileScope();
		mSeekScope = ScopeSeek();
		for (int x = 0; x < vecScopeIndex.size(); ++x)
		{
			Vector2 vTilePos = Vector2(
				(*pVecTile)[vecScopeIndex[x]]->vPos.x + JOJOTILESX / 2,
				(*pVecTile)[vecScopeIndex[x]]->vPos.y + JOJOTILESY / 2);
			mpSheet->Draw(mpBatch, *mpSpriteFrame, mWorldPos + vTilePos - offset, tint);
		}
		for (int x = 0; x < vecScopeIndex.size(); ++x)
		{
			(*pVecTile)[vecScopeIndex[x]]->moveNum = 0;
		}
		vecScopeIndex.clear();
	}
	else
	{
		mSeekScope = false;
	}

}

void MoveBox::TileScope()
{
	float fScrollx = ScrollMgr::Instance().GetScroll().x;
	float fScrolly = ScrollMgr::Instance().GetScroll().y;
	auto mouse = Mouse::Get().GetState();
	XMFLOAT2 mMousePos = XMFLOAT2(mouse.x + fScrollx, mouse.y + fScrolly);

	vector<unique_ptr<TILE>> *pVecTile = SGAActorManager::Instance().GetTileInfo();

	//int iIndex = 0;

	//int i = 1;
	//float Distance = 0;
	//Vector2 vPos = mPosition;
	//Vector2 vTilePos = XMFLOAT2(0.0f, 0.0f);
	RECT rectScope;
	rectScope.left = mPosition.x - mLimitDis;
	rectScope.right = mPosition.x + mLimitDis;
	rectScope.top = mPosition.y - mLimitDis;
	rectScope.bottom = mPosition.y + mLimitDis;

	//XMFLOAT2 fiindex = XMFLOAT2(mPosition.x + mLimitDis, mPosition + mLimitDis);
	//int iindex = GetTileIndex(mPosition.x + mLimitDis);
	XMFLOAT2 sLeftt = XMFLOAT2(rectScope.left, rectScope.top);
	XMFLOAT2 sRightt = XMFLOAT2(rectScope.right, rectScope.top);
	XMFLOAT2 sLeftb = XMFLOAT2(rectScope.left, rectScope.bottom);
	XMFLOAT2 sRightb = XMFLOAT2(rectScope.right, rectScope.bottom);

	int sLTIndex = GetTileIndex(sLeftt);
	int sRTIndex = GetTileIndex(sRightt);
	int sLBIndex = GetTileIndex(sLeftb);
	int sRBIndex = GetTileIndex(sRightb);

	//if (sLTIndex < 0)
	//	sLTIndex = 0;
	//if (sRTIndex > 400)
	//	sRTIndex = 400;
	//if (sLBIndex < 0)
	//	sLBIndex = 0;
	//if (sRBIndex > 400)
	//	sRBIndex = 400;
	//for (int i = 0; i < sLBIndex- sLTIndex; ++i)
	//{
	//	for (int j = 0; j < sRBIndex - sLBIndex; ++j)
	//	{
	//		if (i * (20) + j+(sLTIndex) >= 400)
	//			break;
	//		//if ((*pVecTile)[i * (sLTIndex) + j]->byOption == 1)
	//		//	continue;
	//		Vector2 vTilePos = Vector2((*pVecTile)[i * (20) + j+(sLTIndex)]->vPos.x + JOJOTILESX / 2, (*pVecTile)[i * (20) + j+(sLTIndex)]->vPos.y + JOJOTILESY / 2);
	//		Vector2 vPos = mPosition;

	//		float Distance = Vector2::Distance(vPos, vTilePos);

	//		if (Distance <= mLimitDis)
	//		{
	//			vecScopePos.push_back(vTilePos);
	//		}

	//	}
	//}
	//�ɸ����� ��ġŸ�Ͽ� �̵��Ÿ��� ����
	(*pVecTile)[GetTileIndex(mPosition)]->moveNum = mMoveDistance;
	vecScopeIndex.push_back(GetTileIndex(mPosition));
	for (int mDis = mMoveDistance; mDis > 0; --mDis)
	{
		for (int i = 0; i < 20; ++i)
		{
			for (int j = 0; j < 20; ++j)
			{
				if ((*pVecTile)[i * (20) + j]->moveNum == mDis)
				{
					if ((*pVecTile)[i * (20) + j]->moveNum > 0)
					{
						if (i - 1 >= 0 && (*pVecTile)[(i - 1) * (20) + j]->moveNum < mDis && (*pVecTile)[(i - 1) * (20) + j]->byOption != 1)
						{
							(*pVecTile)[(i - 1) * (20) + j]->moveNum = mDis - 1;
							vecScopeIndex.push_back((i - 1) * (20) + j);
						}
						if (i + 1 < 20 && (*pVecTile)[(i + 1) * (20) + j]->moveNum < mDis && (*pVecTile)[(i + 1) * 20 + j]->byOption != 1)
						{
							(*pVecTile)[(i + 1) * (20) + j]->moveNum = mDis - 1;
							vecScopeIndex.push_back((i + 1) * (20) + j);
						}

						if (j + 1 < 20 && (*pVecTile)[i * (20) + (j + 1)]->moveNum < mDis && (*pVecTile)[i * 20 + (j + 1)]->byOption != 1)
						{
							(*pVecTile)[i * (20) + (j + 1)]->moveNum = mDis - 1;
							vecScopeIndex.push_back(i * (20) + (j + 1));
						}

						if (j - 1 >= 0 && (*pVecTile)[i * (20) + (j - 1)]->moveNum < mDis && (*pVecTile)[i * 20 + (j - 1)]->byOption != 1)
						{
							(*pVecTile)[i * (20) + (j - 1)]->moveNum = mDis - 1;
							vecScopeIndex.push_back(i * (20) + (j - 1));
						}


					}
				}
			}
		}
	}
	//���밪 ���̾� ��� ������� �ϴ¹��
	/*
	for (int i = sLTIndex; i < sRBIndex; i+=11)
	{
	for (int j = 1; j < 10; ++j)
	{
	if (i > 400 || i < 0)
	{
	i = 0;
	}
	//if ((*pVecTile)[i * (sLTIndex)+j]->byOption == 1)
	//	continue;

	Vector2 vTilePos = Vector2((*pVecTile)[i]->vPos.x + JOJOTILESX / 2, (*pVecTile)[i]->vPos.y + JOJOTILESY / 2);
	Vector2 vPos = mPosition;

	//float Distance = Vector2::Distance(vPos, vTilePos);

	//if (Distance <= mLimitDis)
	//{
	//	vecScopePos.push_back(vTilePos);
	//}

	float x = vPos.x - vTilePos.x;
	float y = vPos.y - vTilePos.y;

	if (abs(x) + abs(y) <= abs(mLimitDis))
	{
	vecScopePos.push_back(vTilePos);
	}
	i += 1;
	}
	}
	*/

	/*
	while (true)	// Ż������ ? ��尡 �������� �����Ҷ�����...
	{
	int JOJOCX = 20;
	int JOJOCY = 20;


	//if(�����ϴ� Ÿ���̳�?,
	//���� �ִ� Ÿ���̳�?,
	//�̹������߰ų�,
	//���¸���Ʈ�� �߰����ִ� �༮ ����)

	// ��
	iIndex = GetTileIndex(mPosition) - JOJOCX*i;

	vTilePos = Vector2((*pVecTile)[iIndex]->vPos.x + JOJOTILESX / 2, (*pVecTile)[iIndex]->vPos.y + JOJOTILESY / 2);


	Distance = Vector2::Distance(vPos, vTilePos);

	if (iIndex >= JOJOCX && Distance <= mLimitDis)
	{
	vecScopePos.push_back(vTilePos);
	}

	// ������ ��
	iIndex = GetTileIndex(mPosition) -
	(JOJOCX - 1)*i;
	vTilePos = Vector2((*pVecTile)[iIndex]->vPos.x + JOJOTILESX / 2, (*pVecTile)[iIndex]->vPos.y + JOJOTILESY / 2);


	Distance = Vector2::Distance(vPos, vTilePos);

	if (iIndex >= JOJOCX &&
	iIndex % (JOJOCX) != JOJOCX - 1 &&
	Distance <= mLimitDis)
	{
	vecScopePos.push_back(vTilePos);
	}
	// ������
	iIndex = GetTileIndex(mPosition) + 1 * i;
	vTilePos = Vector2((*pVecTile)[iIndex]->vPos.x + JOJOTILESX / 2, (*pVecTile)[iIndex]->vPos.y + JOJOTILESY / 2);

	Distance = Vector2::Distance(vPos, vTilePos);

	if (iIndex % JOJOCX != JOJOCX - 1 &&
	Distance <= mLimitDis)
	{
	vecScopePos.push_back(vTilePos);
	}

	// ������ �Ʒ�
	iIndex = GetTileIndex(mPosition) +
	(JOJOCX + 1) * i;

	vTilePos = Vector2((*pVecTile)[iIndex]->vPos.x + JOJOTILESX / 2, (*pVecTile)[iIndex]->vPos.y + JOJOTILESY / 2);


	Distance = Vector2::Distance(vPos, vTilePos);

	if (iIndex < JOJOCX * JOJOCY &&
	iIndex % JOJOCX != JOJOCX - 1 &&
	Distance <= mLimitDis)
	{
	vecScopePos.push_back(vTilePos);
	}
	// �Ʒ�
	iIndex = GetTileIndex(mPosition) + JOJOCX*i;

	vTilePos = Vector2((*pVecTile)[iIndex]->vPos.x + JOJOTILESX / 2, (*pVecTile)[iIndex]->vPos.y + JOJOTILESY / 2);


	float Distance = Vector2::Distance(vPos, vTilePos);

	if (iIndex < JOJOCX * JOJOCY - JOJOCX &&
	Distance <= mLimitDis)
	{
	vecScopePos.push_back(vTilePos);
	}

	// ���� �Ʒ�
	iIndex = GetTileIndex(mPosition) +
	(JOJOCX - 1)*i;

	vTilePos = Vector2((*pVecTile)[iIndex]->vPos.x + JOJOTILESX / 2, (*pVecTile)[iIndex]->vPos.y + JOJOTILESY / 2);


	Distance = Vector2::Distance(vPos, vTilePos);

	if (iIndex < JOJOCX * JOJOCY - JOJOCX &&
	iIndex % JOJOCX != 0 &&
	Distance <= mLimitDis)
	{
	vecScopePos.push_back(vTilePos);
	}

	// ����
	iIndex = GetTileIndex(mPosition) - 1 * i;

	vTilePos = Vector2((*pVecTile)[iIndex]->vPos.x + JOJOTILESX / 2, (*pVecTile)[iIndex]->vPos.y + JOJOTILESY / 2);


	Distance = Vector2::Distance(vPos, vTilePos);

	if (iIndex % (JOJOCX) != 0 && Distance <= mLimitDis)
	{
	vecScopePos.push_back(vTilePos);
	}
	// ���� ��
	iIndex = GetTileIndex(mPosition) -
	(JOJOCX + 1)*i;

	vTilePos = Vector2((*pVecTile)[iIndex]->vPos.x + JOJOTILESX / 2, (*pVecTile)[iIndex]->vPos.y + JOJOTILESY / 2);


	Distance = Vector2::Distance(vPos, vTilePos);

	if (iIndex >= JOJOCX &&
	iIndex % (JOJOCX) != 0 &&
	Distance <= mLimitDis)
	{
	vecScopePos.push_back(vTilePos);
	}

	// Parent�� ���� 8���� ���簡 ���� ����,
	// 8���� ����߿� �� �� �ִ� ��带 OpenList�� �־�ξ���.
	// �� �߿��� �ڽ�Ʈ�� ���� ���� ����. -> �������� ����
	// Sort(�Լ�������);
	//sort(vecScopePos.begin(),vecScopePos.end());

	i++;
	if (i >= JOJOCX)
	i = 1;

	if (vecScopePos.empty())
	return;

	// Ż�� !
	if (Distance >= mLimitDis)
	{
	break;
	}
	}
	*/
}

bool MoveBox::ScopeSeek()
{
	float fScrollx = ScrollMgr::Instance().GetScroll().x;
	float fScrolly = ScrollMgr::Instance().GetScroll().y;
	auto mouse = Mouse::Get().GetState();
	vector<unique_ptr<TILE>> *pVecTile = SGAActorManager::Instance().GetTileInfo();

	XMFLOAT2 mmousePos = XMFLOAT2(mouse.x + fScrollx, mouse.y + fScrolly);

	int mouseIndex = GetTileIndex(mmousePos);
	//Vector2 vecMousePos = (*pVecTile)[mouseIndex]->vPos + XMFLOAT2(JOJOTILESX / 2, JOJOTILESY / 2);
	//for (int i = 0; i < vecScopePos.size(); ++i)
	//{
	//	if ((vecScopePos[i].x == vecMousePos.x) && (vecScopePos[i].y == vecMousePos.y))
	//		return true;
	//}
	Vector2 vecMousePos = (*pVecTile)[mouseIndex]->vPos + XMFLOAT2(JOJOTILESX / 2, JOJOTILESY / 2);

	for (int i = 0; i < vecScopeIndex.size(); ++i)
	{
		Vector2 vec2ScopePos = (*pVecTile)[vecScopeIndex[i]]->vPos + XMFLOAT2(JOJOTILESX / 2, JOJOTILESY / 2);
		if (vec2ScopePos.x == vecMousePos.x && vec2ScopePos.y == vecMousePos.y)
			return true;
	}

	return false;
}
