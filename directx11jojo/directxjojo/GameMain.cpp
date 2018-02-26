#include "stdafx.h"
#include "GameMain.h"


GameMain::GameMain()
{
}


GameMain::~GameMain()
{
}

void GameMain::InitD3D(HWND hWnd)
{
	//DXTRACE_MSG(L"this is Error message")		//directx ������ ���־� ��Ʃ��� ���â�� ����
	//DXTRACE_ERR(L"Error", 0);//HRESULT)			//���â������
	//DXTRACE_ERR_MSGBOX(L"Error", 0);			//��� ������ ���Դ��� �˼����� �޼����ڽ���

	/*
	//�̰��� �⺻ vs c++ ���� ��밡�������� �����Ƽ� �������� �ҷ��°���
	wostringstream stream;
	stream << __FILEW__ << " : " << __LINE__ << endl;		//���� �������� �ҽ������� ���� �˼����� ���ε� �˼�����
	MessageBox(NULL, stream.str().c_str(), "TITLE", MB_OK);	//�޼��� �ڽ��� �˼�����
	*/
	SGAFramework::InitD3D(hWnd);

	//mspStates = std::make_unique<CommonStates>(mspDevice.Get());
	//mspStage = make_unique<World>(mspSpriteBatch.get(),mScreenWidth,mScreenHeight);
	//mspStage = SGAActorManager::Instance().Create<World>(mspSpriteBatch.get(), mScreenWidth, mScreenHeight);
	//mspStage->Init("Images\\Map\\stage3.tmx", E_SORTID_SECOND);
	
	//auto pTexture = SGAResourceManager::Instance().GetShaderResource(L"Images\\jojoWalk\\jojoWalk.png");//(L"Images\\sprites.png");
	//auto pSheet = SGAResourceManager::Instance().GetSpriteSheet(L"Images\\jojoWalk\\jojoWalk.xml", pTexture); //(L"Images\\sprites.xml",pTexture);

	//mpPlayer = SGAActorManager::Instance().Create<Player>(mspSpriteBatch.get(), pSheet);
	//GunGeon::Blackboard::Instance().SetPlayer(mpPlayer);


	//mpPlayer->Init(
	//	100.0f,
	//	XMFLOAT2(mScreenWidth * 0.5f, mScreenHeight * 0.5f), E_SORTID_FIRST);

	//mpPlayer->SetStaus(100, 10);
	//SceneMgr::Instance().SetEScene(E_SCENE_STAGE);
	SceneMgr::Instance().InitScene(mspSpriteBatch.get(),mspspriteFont.get(), E_SCENE_LOGO);

	
	//////
	//Player *pPlayer = SGAActorManager::Instance().CreatePlayer();
	//Monster *pMonster = SGAActorManager::Instance().CreateMonster();

	//unique_ptr<Player> p = make_unique<Player>();
	//unique_ptr<Monster> m = make_unique<Monster>();

	//SGAActorManager::Instance().SortActors();
}

void GameMain::ClearD3D()
{
	SGAFramework::ClearD3D();
}

void GameMain::Update(float dt)
{
	SGAFramework::Update(dt);


	//offset = Vector2(0.0f, 0.0f);
	//float speed = 48;
	//
	//auto state = Keyboard::Get().GetState();

	//if (state.D1)
	//	offset.y = speed * dt;
	//if (mspKeyboard->GetState().IsKeyDown(Keyboard::W))
	//{
	//	offset.y = -speed * dt;
	//}
	//else if (mspKeyboard->GetState().IsKeyDown(Keyboard::S))
	//{
	//	offset.y = speed * dt;
	//}

	//if (mspKeyboard->GetState().IsKeyDown(Keyboard::A))
	//{
	//	offset.x = -speed * dt;
	//}
	//else if (mspKeyboard->GetState().IsKeyDown(Keyboard::D))
	//{
	//	offset.x = speed * dt;
	//}

	//if (((mspStage->GetmCameraPosition().x > mspStage->GetWorldSize().x) && (mspStage->GetmCameraPosition().x >= 0))
	//	&& ((mspStage->GetmCameraPosition().y > mspStage->GetWorldSize().y) && (mspStage->GetmCameraPosition().y >= 0)))
	//{
	//	
	//	mspStage->SetmCameraPosition(mspStage->GetmCameraPosition().x, mspStage->GetmCameraPosition().y);
	//}
	//else

	//mspStage->Scroll(offset);

	//Ÿ���� ������� ��ġ�� ����
	//if ((mspStage->GetmCameraPosition().x < 0) )
	//{
	//	mspStage->SetmCameraPosition(0.0f, mspStage->GetmCameraPosition().y);
	//}
	//else if(mspStage->GetmCameraPosition().y < 0)
	//{
	//	mspStage->SetmCameraPosition(mspStage->GetmCameraPosition().x, 0.0f);
	//}
	//else if (((mspStage->GetmCameraPosition().y + mspStage->GetmTileCountY()) * mspStage->GetmTileHeight()) > (mspStage->GetWorldSize().y))
	//{
	//	
	//	mspStage->SetmCameraPosition(mspStage->GetmCameraPosition().x,floor((((mspStage->GetWorldSize().y / mspStage->GetmTileHeight() - mspStage->GetmTileCountY())))));
	//}
	//else if (((mspStage->GetmCameraPosition().x + mspStage->GetmTileCountX()) * mspStage->GetmTileWidth()) > mspStage->GetWorldSize().x)
	//{
	//	mspStage->SetmCameraPosition(((mspStage->GetWorldSize().x / mspStage->GetmTileWidth() - mspStage->GetmTileCountX())), mspStage->GetmCameraPosition().y);
	//}
	//else
	//mspStage->Scroll(offset);


}

void GameMain::Render()
{
	//mspSpriteBatch->Begin(SpriteSortMode_Deferred, mspStates->Opaque(), mspStates->LinearWrap());
	//mspSpriteBatch->Begin();
	

//	mspStage->Render();

	//SGAActorManager::Instance().Draw();
	
	////����׿� ȭ����� 
	////WCHAR sre[258];
	//char buf[512];
	//sprintf(buf, "mCameraPosition.x = %f \n", mspStage->GetmCameraPosition().x);
	////wsprintf(sre, L"%f", mspStage->GetmCameraPosition().x);
	//
	//OutputDebugStringA(buf);
	//sprintf(buf, "mCameraPosition.y = %f \n", mspStage->GetmCameraPosition().y);
	//OutputDebugStringA(buf);

	//spriteFont->DrawString(mspSpriteBatch.get(), sre, XMFLOAT2(100, 100));
	//wsprintf(sre, L"%f", mspStage->GetmCameraPosition().y);
	//spriteFont->DrawString(mspSpriteBatch.get(), sre, XMFLOAT2(100, 200));

	//mspSpriteBatch->End();
}
