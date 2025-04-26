#include <windows.h>

// ���� const�� �����Ͱ� ���ڿ��� ������ �����Ҽ� ������ �ǹ��Ѵ�. �ּҰ��� ���氡��
const char* g_Text="��Ƽ����Ʈ ���ڿ�(��, �Ϲ����� ASCII �Ǵ� UTF-8 ���ڵ� ���ڿ�)�Դϴ�.";
LPCSTR g_Text2 = g_Text;
const wchar_t* g_wText = L"�����ڵ� ���̵� ���ڿ� �Դϴ�";
LPCWSTR	g_wText2 = g_wText;
const TCHAR* g_TText = TEXT("TCHAR ���ڿ� �Դϴ�");
bool g_boolType = false; // 0�� false, 0�ƴѰ��� true �� ��ȯ
BOOL g_BoolType = -1;

// ������ ���ν���
// ������ �޽����� ó���ϴ� �Լ�
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam) 
{
	if (message == WM_DESTROY) 
	{
		PostQuitMessage(0); // WM_QUIT �޽����� ť�� �־��ݴϴ�.
		return 0;
	}
	//�츮�� ���� ó������ ���� �޽����� DefWindowProc�� �Ѱ���� Windows�� �⺻ ó���� ���ݴϴ�.
	return DefWindowProc(hWnd, message, wParam, lParam);
}

// WinMain �Լ�
// ���α׷��� ������
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,
	LPSTR lpCmdLine, int nCmdShow) // ����	�ɼ�
{
	WNDCLASS wc = { 0 };
	wc.lpfnWndProc = WndProc;	// ������ ���ν���
	wc.hInstance = hInstance;   // ����޸𸮿��� EXE����� �����ּ�
	wc.lpszClassName = TEXT("MyWindowClass");	// Ŭ���� �̸�
	wc.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);	// ������ ����
	wc.hCursor = LoadCursor(NULL, IDC_ARROW);	// �⺻ Ŀ�� ���
	wc.hIcon = LoadIcon(NULL, IDI_APPLICATION);	// �⺻ ������ ���

	RegisterClass(&wc);

	HWND hWnd = CreateWindow(
		TEXT("MyWindowClass"),      // Ŭ���� �̸�
		TEXT("My Basic Window"),    // ������ Ÿ��Ʋ
		WS_OVERLAPPEDWINDOW,   // ������ ��Ÿ��
		CW_USEDEFAULT, CW_USEDEFAULT, 800, 600, // ���� ��Ÿ���� ������	ũ��
		NULL, NULL, hInstance, NULL);

	ShowWindow(hWnd, nCmdShow); // ������ ���̱�
	UpdateWindow(hWnd);		 // ������ ������Ʈ

	MSG msg;	// �޽��� ����ü�� ���� 
	// GetMessage�� ť�� �޽����� ������ ���(Block)�� ,WM_QUIT �޽����� �߻��ϸ� 0 �� ��ȯ
	while (GetMessage(&msg, NULL, 0, 0))  
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}

	return (int)msg.wParam;
}