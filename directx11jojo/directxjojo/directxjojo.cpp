// directxjojo.cpp : ���� ���α׷��� ���� �������� �����մϴ�.
//

#include "stdafx.h"
#include "directxjojo.h"
#include "GameMain.h"
#include <stdio.h>

int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
                     _In_opt_ HINSTANCE hPrevInstance,
                     _In_ LPWSTR    lpCmdLine,
                     _In_ int       nCmdShow)
{
	////�ܼ�â ����
	//AllocConsole();
	//freopen("CONOUT$", "wt", stdout);
	////CONOUT$ - console â
	////wt - �ؽ�Ʈ ���� ���
	////stdout - ��µ� ���� ������(����ͷ� ����)

	//printf("hello DEBUG\n");

	GameMain main;

	main.InitWindow(hInstance);

	return (int)main.GameLoop();
}