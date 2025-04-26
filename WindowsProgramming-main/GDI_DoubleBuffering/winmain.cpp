#include <windows.h>
#include <stdio.h>

LPCTSTR g_title = TEXT("������ Ÿ��Ʋ�ٿ� ǥ���� ���ڿ�");
LPCTSTR g_szClassName = TEXT("������ Ŭ���� �̸�");

int g_width = 1024;
int g_height = 768;

HWND g_hWnd;
HDC g_ClientDC;    // �ո� DC
HDC g_MemDC;    // �޸� DC
HBITMAP g_Bitmap;

// �ܼ� �ʱ�ȭ
void InitConsole()
{
	AllocConsole();
	FILE* fp;
	freopen_s(&fp, "CONOUT$", "w", stdout);
	SetConsoleTitle(L"������ �޽��� �ܼ� �α�");
	printf("�ܼ� �α� ����...\n\n");
}

void UninitConsole()
{
	// ǥ�� ��� ��Ʈ�� �ݱ�
	fclose(stdout);
	// �ܼ� ����
	FreeConsole();
}


LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	switch (msg)
	{	
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	}

	return DefWindowProc(hwnd, msg, wParam, lParam);
}

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,
	LPSTR lpCmdLine, int nCmdShow)
{
	InitConsole();  // �ܼ� ��� �ʱ�ȭ

	WNDCLASS wc = { 0 };
	wc.lpfnWndProc = WndProc;
	wc.hInstance = hInstance;
	wc.lpszClassName = g_szClassName;
	wc.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
	wc.hCursor = LoadCursor(NULL, IDC_ARROW);	// �⺻ Ŀ�� ���
	wc.hIcon = LoadIcon(NULL, IDI_APPLICATION);	// �⺻ ������ ���
	RegisterClass(&wc);

	// ���ϴ� ũ�Ⱑ �����Ǿ� ����
	RECT rcClient = { 0, 0, (LONG)g_width, (LONG)g_height };
	AdjustWindowRect(&rcClient, WS_OVERLAPPEDWINDOW, FALSE);

	//����
	HWND hwnd = CreateWindow(
		g_szClassName,
		g_title,
		WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT, CW_USEDEFAULT,
		rcClient.right - rcClient.left, rcClient.bottom - rcClient.top,
		NULL, NULL, hInstance, NULL);

	ShowWindow(hwnd, nCmdShow);
	UpdateWindow(hwnd);

	////////Renderer::Initialize
	g_ClientDC = GetDC(hwnd); //������ Ŭ���̾�Ʈ ������ DeviceContext���
	g_MemDC = CreateCompatibleDC(g_ClientDC); // ȣȯ�Ǵ� DeviceContext ����
	g_Bitmap = CreateCompatibleBitmap(g_ClientDC, g_width, g_height); // �޸� ��������
	SelectObject(g_MemDC, g_Bitmap); // MemDC�� �޸𸮿��� ����
	
	MSG msg;
	while (true)
	{
		if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
		{
			if (msg.message == WM_QUIT)
				break;

			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}

		// Renderer::BeginDraw()
		PatBlt(g_MemDC, 0, 0, g_width, g_height, WHITENESS);

		// Render()
		const int CELL_SIZE = 300;     // �� ũ��
		const int PADDING = 10;       // �� ���� ����
		int cols = g_width / CELL_SIZE;
		int rows = g_height / CELL_SIZE;

		RECT rect = { 0, 0, g_width, g_height };
		for (int y = 0; y < rows; ++y)
		{
			for (int x = 0; x < cols; ++x)
			{
				int left = x * CELL_SIZE + PADDING;
				int top = y * CELL_SIZE + PADDING;
				int right = (x + 1) * CELL_SIZE - PADDING;
				int bottom = (y + 1) * CELL_SIZE - PADDING;
				Ellipse(g_MemDC, left, top, right, bottom);
			}
		}

		// Renderer::EndDraw()
		BitBlt(g_ClientDC, 0, 0, g_width, g_height, g_MemDC, 0, 0, SRCCOPY);
	}
	
	// Renderer::Uninitialize
	DeleteObject(g_Bitmap);
	DeleteDC(g_MemDC);
	ReleaseDC(hwnd, g_ClientDC);
	//////////////////////////////////////////////////////////////////////////

	UninitConsole();  // �ܼ� ��� ����
	return (int)msg.wParam;
}
