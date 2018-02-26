#pragma once

class MoveBox : public SGAActor
{
public:
	//static MoveBox *Instance()
	//{
	//	static unique_ptr<MoveBox> instance(new MoveBox);
	//	return instance.get();
	//}
	//static MoveBox *Instance()
	//{
	//	static MoveBox instance;
	//	return &instance;
	//}
public:
	MoveBox();
	MoveBox(SpriteBatch * pBatch, SGASpriteSheet * pSheet, SpriteFont * pFont);
public:
	virtual ~MoveBox();

private:
	float mLimitDis;
	bool mVisible;
	bool mSeekScope;
	int mMoveDistance;//�ɸ����� �̵��Ÿ�
	vector<XMFLOAT2> vecScopePos;		//������ �ش��ϴ� ��ġ ����
	vector<int> vecScopeIndex;			//������ �ش��ϴ� Ÿ�� �ε��� ����
	Player* mpPlayer;
public:
	virtual void Init(E_SORTID eSortID, XMFLOAT2 pos, float limitDis, bool visible);
	virtual void Init(SpriteBatch *pBatch, SGASpriteSheet *pSheet, SpriteFont *pFont, E_SORTID eSortID, XMFLOAT2 pos, float limitDis, bool visible);
	virtual E_SCENE Update(float dt);
	virtual void Draw();
	void TileScope();
	//virtual void OnHit(SGAActor* pCollidee);
	//unique_ptr<MoveBox> mpMoveBox;

	void SetVisible(bool visible) { mVisible = visible; }
	bool GetVisible() { return mVisible; }
	void SetMoveDis(int moveDis) { mMoveDistance = moveDis; }
	void SetPlayer(Player* player) { mpPlayer = player; }

	Player* GetPlayer() { return mpPlayer; }
	vector<XMFLOAT2> GetVecScopePos() { return vecScopePos; }
	bool GetSeekScope() { return mSeekScope; }
	bool ScopeSeek();

};

