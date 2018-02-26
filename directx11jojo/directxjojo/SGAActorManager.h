#pragma once
class SGAActorManager final
{
public:
	// ������ǥ��
	/*static SGAActorManager* INstance2()
	{
		static SGAActorManager instance;
		return &instance;
	}*/
	//���۷��� ǥ��
	static SGAActorManager& Instance()
	{
		static SGAActorManager instance;
		return instance;
	}
private:
	SGAActorManager();
	SGAActorManager(SGAActorManager const&);
	void operator = (SGAActorManager const&);
public:
	~SGAActorManager();
private:
	E_SCENE meScene;
private:
	int mClickCount;
	int posIndex2;
	bool mUiCheck;
	bool mTurn;
	bool mActionAter;
	XMFLOAT2 tmpPos;
public:
	E_SCENE Update(float dt);
	void CheckCollidion();
	void CheckAction();
	void RePosAndVisiMB();
	void RePosAndVisiUI();
	void RePosAndVisiAt();

	void Draw();
	void Release();
	void SortActors();
	
	E_SCENE GetScene();
	bool GetMBSeekScope();
	bool GetUICheckArea();
	vector<unique_ptr<int>>* GetvecAtScopeIndex();
	bool GetTurn() { return mTurn; }

	void SetMBVisible(bool visible);
	vector<unique_ptr<TILE>>* GetTileInfo();
	void SetUIVisible(bool visible);
	void SetClickCount(int count) { mClickCount = count; }
	void SetAtVisible(bool visible);
	void SetUiCheck(bool uiCheck) { mUiCheck = uiCheck; }
	void SetTurn(bool turn) { mTurn = turn; }
	//void InsertMap(string str, unique_ptr<SGAActor> actor);
public:
	//���ø��� ����ȭ ��� ���ڸ� �޾Ƶ� ��밡���ϵ���
	template<class T,class...Types> inline
		T* Create(Types&&...args)
	{
		mActors.push_back(
			unique_ptr<T>(						//����Ʈ�����ͷ� ����� ���Ϳ� �������
				new T(forward<Types>(args)...)	//�����ڿ� ���� �Ķ���Ͱ�
				)
		);
		return dynamic_cast<T*>(mActors.back().get());
	}
public:
	void SingleRegister(SGAActor* pActors)
	{
		//auto iter = mActors.begin();
		//while (iter != mActors.cend())
		//{
		//	auto iter2 = iter;
		//	std::advance(iter2, 1);
		//	if (typeid(*iter->get()) == typeid(*pActors))
		//	{
		//		break;
		//	}
		//	else if (iter2 == mActors.cend())
		//	{
		//		mActors.push_back(unique_ptr<SGAActor>(pActors));
		//	}
		//	iter++;
		//}
		
		//for (auto &actor : mActors)
		//{
		//	if (typeid(*actor) == typeid(*pActors))
		//	{
		//		break;
		//	}
		//	else if (iter == mActors.cend())
		//	{
		//		iter = actor;
		//		mActors.push_back(unique_ptr<SGAActor>(pActors));
		//	}
		//}
		//if (mActors.size() == 0) 
		//{
		//	mActors.push_back(unique_ptr<SGAActor>(pActors));
		//}
	}
private:
	//map<string, unique_ptr <SGAActor>> mMapActors;
	list<unique_ptr <SGAActor>> mActors;
	//vector<TILE*> mVectile;
};