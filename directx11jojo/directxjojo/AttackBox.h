#pragma once
class AttackBox : public SGAActor
{
public:
	AttackBox();
	AttackBox(SpriteBatch * pBatch, SGASpriteSheet * pSheet, SpriteFont * pFont);
	~AttackBox();
private:
	bool mAtVisible;
	bool mAtSeekScope;
	int mAttackDistance;//ĳ������ �̵��Ÿ�
	int mAttackDamge;	//�ش� ĳ������ ���ݷ�
	int mCamp;			//�ش� ĳ������ ����
	vector<XMFLOAT2> vecAtScopePos;		//������ �ش��ϴ� ��ġ ����
	vector<int> vecAtScopeIndex;			//������ �ش��ϴ� Ÿ�� �ε��� ����
	vector<unique_ptr<int>> vecAtScopeIndex2;			//������ �ش��ϴ� Ÿ�� �ε���2 �Ȼ����
	Character* mpCharacter;
public:
	virtual void Init(E_SORTID eSortID, XMFLOAT2 pos, bool visible);
	virtual E_SCENE Update(float dt);
	virtual void Draw();
	virtual void OnHit(SGAActor* pCollidee);
	void Release();

	bool IntersecRectScope(SGAActor* pActor);
	void AttackScope();
	bool AttackScopeSeek();
	void SetAttackDis(int AttackDis) { mAttackDistance = AttackDis; }
	void SetAttackDamge(int damge) { mAttackDamge = damge; }
	void SetCamp(int camp) { mCamp = camp; }
	void SetCharacter(Character * character) { mpCharacter = character; }

	Character* GetCharacter() { return mpCharacter; }
	int GetAttack() { return mAttackDamge; }
	bool GetAtScopeSeek() { return mAtSeekScope; }
	RECT GetBoundScope();
	vector<unique_ptr<int>>* GetVecAtScopeIndex() { return &vecAtScopeIndex2; }
	vector<XMFLOAT2> GetVecAtScopePos() { return vecAtScopePos; }
	void SetVisible(bool visible) { mAtVisible = visible; }
};

