#pragma once
class SGAResourceManager final
{
public:
	static SGAResourceManager& Instance()
	{
		static SGAResourceManager instance;

		return instance;
	}
private:
	SGAResourceManager();
	SGAResourceManager(SGAResourceManager const&);
	void operator = (SGAResourceManager const&);
public:
	~SGAResourceManager();

private:
	ID3D11Device*	mpDevice;
	HWND			mhWnd;
	//com�� ���ҿ����� unique_ptr�� c++ �̸��
	map<wstring, ComPtr<ID3D11ShaderResourceView>>		mShaderResources;
	map < wstring, unique_ptr<SGASpriteSheet>>			mSpriteSheets;

public:
	void Init(HWND hWnd, ID3D11Device* pDevice)
	{
		mhWnd = hWnd;
		mpDevice = pDevice;
	}
	void Release();
public:
	ID3D11ShaderResourceView*	GetShaderResource(wstring filename);	//�ؽ��͸� �����ͷ� ������
	SGASpriteSheet*				GetSpriteSheet(wstring filename,ID3D11ShaderResourceView* pTexture);
	SGASpriteSheet*				GetSpriteSheet(wstring filename, wstring textureName);
};

