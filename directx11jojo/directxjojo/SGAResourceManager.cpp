#include "stdafx.h"
#include "SGAResourceManager.h"


SGAResourceManager::SGAResourceManager()
	:mhWnd(0),
	mpDevice(0)
{
}


SGAResourceManager::~SGAResourceManager()
{
}

void SGAResourceManager::Release()
{
	for (auto& resource : mShaderResources)
	{
		resource.second.Reset();	//�ʱ�ȭ
	}
	for (auto& sheet : mSpriteSheets)
	{
		sheet.second.reset();//uniqe_ptr�̶� �ҹ���
	}
}

ID3D11ShaderResourceView * SGAResourceManager::GetShaderResource(wstring filename)
{
	//�ߺ��̳�?
	// �ߺ��̸�? ������ �ִ���
	//�űԸ�?
	//new �޸� �Ҵ�

	//�O�� �ְ� 2���� ����� ã�°� �ᱹ 2���� ã�� ã�� �ְ�
	//auto iter = this->mShaderResources.find(filename);
	//if (iter == mShaderResources.cend())
	//{
	//	//Load
	//	mShaderResources.insert();
	//}
	//else
	//	iter->second

	//�̷����ϸ� ã�°Ͱ� �ٷδ����� �űԳ� �����̳� ������ ������ ������
	//auto map = std::map<string, string>();
	//auto result = map.insert(pair<string, string>("1", "abcd")); //�ϴ� ����ְ� �ߺ��̳� �ƴϳ� Ȯ���ؾ���
	//if (result.second == true)
	//{
	//	//�űԷ� insert �Ȱ�
	//	result.first->second;//�̰���  abcd iter�� first
	//}
	//else
	//	result.first->second;		//�̹������ϴ� iterator�� first

	//auto map = std::map<string,SGASpriteSheet*>();
	//auto result = map.insert(pair<string, string>("1", nullptr)); //�ϴ� ����ְ� �ߺ��̳� �ƴϳ� Ȯ���ؾ���
	//if (result.second == true)
	//{
	//	//�űԷ� insert �Ȱ�
	//	result.first->second= new SGASpriteSheet();	// �̱���� ���־��Ե�
	//}
	//else
	//	result.first->second;		//�̹������ϴ� iterator�� first

	if (mpDevice == NULL)
	{
		DXTRACE_ERR_MSGBOX(L"mpDevice is NULL. /nCall Init() first!", 0);
		return NULL;
	}
	ID3D11ShaderResourceView* pResource = NULL;

	auto result = mShaderResources.insert(
		pair<wstring, ComPtr<ID3D11ShaderResourceView>>(filename, nullptr));

	if (result.second == true)
	{
		result.first->second = ComPtr<ID3D11ShaderResourceView>();
		CreateWICTextureFromFile(mpDevice, filename.c_str(), NULL, result.first->second.GetAddressOf());
		pResource = result.first->second.Get();
		
	}
	else
		pResource = result.first->second.Get();

	return pResource;
}

SGASpriteSheet * SGAResourceManager::GetSpriteSheet(wstring filename, ID3D11ShaderResourceView * pTexture)
{
	SGASpriteSheet* pSheet = NULL;

	auto result = mSpriteSheets.insert(
		pair<wstring, unique_ptr<SGASpriteSheet>>(filename, nullptr)
	);
	if (result.second == true)
	{
		//nullptr �ƴϸ� reset �ؾ���
		result.first->second = move(make_unique<SGASpriteSheet>());
		pSheet = result.first->second.get();
		pSheet->Load(pTexture, filename.c_str());
	}
	else
		pSheet = result.first->second.get();

	return pSheet;
}

SGASpriteSheet * SGAResourceManager::GetSpriteSheet(wstring filename, wstring textureName)
{
	return GetSpriteSheet(filename,GetShaderResource(textureName));
}
