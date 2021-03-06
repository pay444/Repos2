// stdafx.h : 자주 사용하지만 자주 변경되지는 않는
// 표준 시스템 포함 파일 또는 프로젝트 관련 포함 파일이
// 들어 있는 포함 파일입니다.
//

#pragma once

#include "targetver.h"

#define WIN32_LEAN_AND_MEAN             // 거의 사용되지 않는 내용은 Windows 헤더에서 제외합니다.
// Windows 헤더 파일:
#include <windows.h>
#include <wrl.h>
#include <map>
#include <vector>
#include <sstream>
#include <list>
#include <algorithm>

// C 런타임 헤더 파일입니다.
#include <stdlib.h>
#include <malloc.h>
#include <memory.h>
#include <tchar.h>


// TODO: 프로그램에 필요한 추가 헤더는 여기에서 참조합니다.
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