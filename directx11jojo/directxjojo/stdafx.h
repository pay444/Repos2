// stdafx.h : ���� ��������� ���� ��������� �ʴ�
// ǥ�� �ý��� ���� ���� �Ǵ� ������Ʈ ���� ���� ������
// ��� �ִ� ���� �����Դϴ�.
//

#pragma once

#include "targetver.h"

#define WIN32_LEAN_AND_MEAN             // ���� ������ �ʴ� ������ Windows ������� �����մϴ�.
// Windows ��� ����:
#include <windows.h>
#include <wrl.h>
#include <map>
#include <vector>
#include <sstream>
#include <list>
#include <algorithm>

// C ��Ÿ�� ��� �����Դϴ�.
#include <stdlib.h>
#include <malloc.h>
#include <memory.h>
#include <tchar.h>


// TODO: ���α׷��� �ʿ��� �߰� ����� ���⿡�� �����մϴ�.
#include <d3d11.h>
#include <SimpleMath.h>
#include <SpriteBatch.h>
#include <Keyboard.h>
#include <Mouse.h>
#include <WICTextureLoader.h>
#include <SpriteFont.h>

#pragma comment (lib, "d3d11.lib")

using namespace std;
using namespace Microsoft::WRL;
using namespace DirectX;
using namespace DirectX::SimpleMath;

#include <mmsystem.h>
#include "dxerr.h"
#include "Defines.h"

#include "SGAFramework.h"
#include "SGASpriteSheet.h"
#include "SGAActor.h"
#include "SGAActorManager.h"
#include "SGAResourceManager.h"
//#include "SGAProjectile.h"
#include "SGAFSM.h"
#include "SGATimer.h"
#include "SceneMgr.h"
#include "ScrollMgr.h"
//#include "ySortMgr.h"
//#include "EnemyState.h"

#include "World.h"
#include "GameMain.h"
#include "Player.h"
#include "MoveBox.h"