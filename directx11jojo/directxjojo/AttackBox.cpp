#include "stdafx.h"
#include "AttackBox.h"


AttackBox::AttackBox()
{
}

AttackBox::AttackBox(SpriteBatch * pBatch, SGASpriteSheet * pSheet, SpriteFont * pFont)
	:SGAActor(pBatch, pSheet, pFont),
	mAtVisible(false)
{
	
}


AttackBox::~AttackBox()
{

}

void AttackBox::Init(E_SORTID eSortID, XMFLOAT2 pos, bool visible)
{

	Animation anim[] = {
		{ "AttackBox", 1,{ { "AttackBox0", 0.3f } }
		},
	};
	mAtVisible = visible;
	SGAActor::Init(anim, 1, eSortID);
	SetPosition(pos);
	SetAnimation("AttackBox");
}

E_SCENE AttackBox::Update(float dt)
{
	E_SCENE eResult = SGAActor::Update(dt);

	if (eResult > E_SCENE_NONPASS)
		return eResult;

	return E_SCENE_NONPASS;
}

void AttackBox::Draw()
{
	XMFLOAT2 offset = XMFLOAT2(0, 0);
	Color tint = Colors::White;
	auto mouse = Mouse::Get().GetState();
	int mouseIndex = 0;
	int posIndex = 0;
	float fScrollx = ScrollMgr::Instance().GetScroll().x;
	float fScrolly = ScrollMgr::Instance().GetScroll().y;

	offset.x = (int)ScrollMgr::Instance().GetScroll().x;
	offset.y = (int)ScrollMgr::Instance().GetScroll().y;
	vector<unique_ptr<TILE>> *pVecTile = SGAActorManager::Instance().GetTileInfo();

	posIndex = GetTileIndex(mPosition);

	//���ݹ����� �����ٶ�
	if (mAtVisible)
	{
		Vector2 mousePos = Vector2(mouse.x + fScrollx, mouse.y + fScrolly);
		mouseIndex =GetTileIndex(mousePos);

		AttackScope();
		//mAtSeekScope = AttackScopeSeek();
		for (int x = 0; x < vecAtScopeIndex2.size(); ++x)
		{
			auto a = *vecAtScopeIndex2[x].get();
			Vector2 vTilePos = Vector2(
				(*pVecTile)[*vecAtScopeIndex2[x].get()]->vPos.x + JOJOTILESX / 2,
				(*pVecTile)[*vecAtScopeIndex2[x].get()]->vPos.y + JOJOTILESY / 2);
			mpSheet->Draw(mpBatch, *mpSpriteFrame, mWorldPos + vTilePos - offset, tint);
		}
		//Ÿ���� ��ġ ���� �ʱ�ȭ
		(*pVecTile)[GetTileIndex(mPosition)]->AttackNum = 0;
		for (int x = 0; x < vecAtScopeIndex2.size(); ++x)
		{
			(*pVecTile)[*vecAtScopeIndex2[x].get()]->AttackNum = 0;
		}
	}
	else //if(!SGAActorManager::Instance().GetUICheckArea() && mAtVisible== false && posIndex!=mouseIndex)
	{
		//vecAtScopeIndex.clear();
		//Release();
		//mAtSeekScope = false;
	}

}

void AttackBox::OnHit(SGAActor * pCollidee)
{
	if (typeid(*pCollidee) == typeid(FotMan))
	{
		int x = 1;
	}
}

void AttackBox::Release()
{
	vecAtScopeIndex.clear();
	auto iter = vecAtScopeIndex2.begin();
	while (iter != vecAtScopeIndex2.end())
	{
		iter->reset();
		iter = vecAtScopeIndex2.erase(iter);
	}
}

bool AttackBox::IntersecRectScope(SGAActor * pActor)
{

	RECT src = GetBoundScope();
	RECT trg = pActor->GetBound();
	RECT intersect;
	return	::IntersectRect(&intersect, &src, &trg);
}

void AttackBox::AttackScope()
{
	if (SGAFramework::mMouseTracker.leftButton == Mouse::ButtonStateTracker::ButtonState::RELEASED)
	{
		float fScrollx = ScrollMgr::Instance().GetScroll().x;
		float fScrolly = ScrollMgr::Instance().GetScroll().y;
		auto mouse = Mouse::Get().GetState();
		XMFLOAT2 mMousePos = XMFLOAT2(mouse.x + fScrollx, mouse.y + fScrolly);

		vector<unique_ptr<TILE>> *pVecTile = SGAActorManager::Instance().GetTileInfo();

		//�ɸ����� ��ġŸ�Ͽ� ���ݰŸ��� ����
		(*pVecTile)[GetTileIndex(mPosition)]->AttackNum = mAttackDistance;
		//vecAtScopeIndex.push_back(GetTileIndex(mPosition));
		//vecAtScopeIndex2.push_back(make_unique<int>(GetTileIndex(mPosition)));
		for (int mDis = mAttackDistance; mDis > 0; --mDis)
		{
			for (int i = 0; i < 20; ++i)
			{
				for (int j = 0; j < 20; ++j)
				{
					if ((*pVecTile)[i * (20) + j]->AttackNum == mDis)
					{
						if ((*pVecTile)[i * (20) + j]->AttackNum > 0)
						{
							if (i - 1 >= 0 && (*pVecTile)[(i - 1) * (20) + j]->AttackNum < mDis)
							{
								(*pVecTile)[(i - 1) * (20) + j]->AttackNum = mDis - 1;
								//vecAtScopeIndex.push_back((i - 1) * (20) + j);
								vecAtScopeIndex2.push_back(make_unique<int>((i - 1) * (20) + j));
							}
							if (i + 1 < 20 && (*pVecTile)[(i + 1) * (20) + j]->AttackNum < mDis)
							{
								(*pVecTile)[(i + 1) * (20) + j]->AttackNum = mDis - 1;
								//vecAtScopeIndex.push_back((i + 1) * (20) + j);
								vecAtScopeIndex2.push_back(make_unique<int>((i + 1) * (20) + j));
								
							}

							if (j + 1 < 20 && (*pVecTile)[i * (20) + (j + 1)]->AttackNum < mDis)
							{
								(*pVecTile)[i * (20) + (j + 1)]->AttackNum = mDis - 1;
								//vecAtScopeIndex.push_back(i * (20) + (j + 1));
								vecAtScopeIndex2.push_back(make_unique<int>(i * (20) + (j + 1)));
							}

							if (j - 1 >= 0 && (*pVecTile)[i * (20) + (j - 1)]->AttackNum < mDis)
							{
								(*pVecTile)[i * (20) + (j - 1)]->AttackNum = mDis - 1;
								//vecAtScopeIndex.push_back(i * (20) + (j - 1));
								vecAtScopeIndex2.push_back(make_unique<int>(i * (20) + (j - 1)));
							}


						}
					}
				}
			}
		}

	}
}

bool AttackBox::AttackScopeSeek()
{
	float fScrollx = ScrollMgr::Instance().GetScroll().x;
	float fScrolly = ScrollMgr::Instance().GetScroll().y;
	auto mouse = Mouse::Get().GetState();
	vector<unique_ptr<TILE>> *pVecTile = SGAActorManager::Instance().GetTileInfo();

	XMFLOAT2 mmousePos = XMFLOAT2(mouse.x + fScrollx, mouse.y + fScrolly);

	int mouseIndex = GetTileIndex(mmousePos);

	Vector2 vecMousePos = (*pVecTile)[mouseIndex]->vPos + XMFLOAT2(JOJOTILESX / 2, JOJOTILESY / 2);

	for (int i = 0; i < vecAtScopeIndex2.size(); ++i)
	{
		Vector2 vec2ScopePos = (*pVecTile)[*vecAtScopeIndex2[i]]->vPos + XMFLOAT2(JOJOTILESX / 2, JOJOTILESY / 2);
		if (vec2ScopePos.x == vecMousePos.x && vec2ScopePos.y == vecMousePos.y)
			return true;
	}

	return false;
}

RECT AttackBox::GetBoundScope()
{

	RECT rct;
	ZeroMemory(&rct, sizeof(RECT));
	float fScrollx = ScrollMgr::Instance().GetScroll().x;
	float fScrolly = ScrollMgr::Instance().GetScroll().y;
	vector<unique_ptr<TILE>> *pVecTile = SGAActorManager::Instance().GetTileInfo();
	auto mouse = Mouse::Get().GetState();
	XMFLOAT2 mmousePos = XMFLOAT2(mouse.x + fScrollx, mouse.y + fScrolly);
	int mouseIndex = GetTileIndex(mmousePos);
	Vector2 vec2MousePos = (*pVecTile)[mouseIndex]->vPos + XMFLOAT2(JOJOTILESX / 2, JOJOTILESY / 2);

	if (mAtSeekScope)
	{
		if (mpSpriteFrame != NULL)
		{
			rct = mpSpriteFrame->sourceRect;
			OffsetRect(&rct,
				static_cast<int>(vec2MousePos.x - mpSpriteFrame->pivot.x) - rct.left,
				static_cast<int>(vec2MousePos.y - mpSpriteFrame->pivot.y) - rct.top);
		}
	}
	return rct;
}
