#include <windows.h>
#include <stdio.h>

LPCTSTR g_title = TEXT("������ Ÿ��Ʋ�ٿ� ǥ���� ���ڿ�");
LPCTSTR g_szClassName = TEXT("������ Ŭ���� �̸�");
int g_width = 1024;
int g_height = 768;

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

// �޽��� ID�� ���ڿ� �̸����� ��ȯ
const char* GetMessageName(UINT msg)
{
	switch (msg)
	{
	case WM_NULL: return "WM_NULL";
	case WM_CREATE: return "WM_CREATE";
	case WM_DESTROY: return "WM_DESTROY";
	case WM_MOVE: return "WM_MOVE";
	case WM_SIZE: return "WM_SIZE";
	case WM_ACTIVATE: return "WM_ACTIVATE";
	case WM_SETFOCUS: return "WM_SETFOCUS";
	case WM_KILLFOCUS: return "WM_KILLFOCUS";
	case WM_ENABLE: return "WM_ENABLE";
	case WM_SETREDRAW: return "WM_SETREDRAW";
	case WM_SETTEXT: return "WM_SETTEXT";
	case WM_GETTEXT: return "WM_GETTEXT";
	case WM_GETTEXTLENGTH: return "WM_GETTEXTLENGTH";
	case WM_PAINT: return "WM_PAINT";
	case WM_CLOSE: return "WM_CLOSE";
	case WM_QUERYENDSESSION: return "WM_QUERYENDSESSION";
	case WM_QUIT: return "WM_QUIT";
	case WM_QUERYOPEN: return "WM_QUERYOPEN";
	case WM_ERASEBKGND: return "WM_ERASEBKGND";
	case WM_SYSCOLORCHANGE: return "WM_SYSCOLORCHANGE";
	case WM_SHOWWINDOW: return "WM_SHOWWINDOW";
	case WM_WININICHANGE: return "WM_WININICHANGE";
	case WM_DEVMODECHANGE: return "WM_DEVMODECHANGE";
	case WM_ACTIVATEAPP: return "WM_ACTIVATEAPP";
	case WM_FONTCHANGE: return "WM_FONTCHANGE";
	case WM_TIMECHANGE: return "WM_TIMECHANGE";
	case WM_CANCELMODE: return "WM_CANCELMODE";
	case WM_SETCURSOR: return "WM_SETCURSOR";
	case WM_MOUSEACTIVATE: return "WM_MOUSEACTIVATE";
	case WM_CHILDACTIVATE: return "WM_CHILDACTIVATE";
	case WM_QUEUESYNC: return "WM_QUEUESYNC";
	case WM_GETMINMAXINFO: return "WM_GETMINMAXINFO";

		// ���콺 ����	
	case WM_LBUTTONDOWN: return "WM_LBUTTONDOWN";
	case WM_LBUTTONUP: return "WM_LBUTTONUP";
	case WM_LBUTTONDBLCLK: return "WM_LBUTTONDBLCLK";
	case WM_RBUTTONDOWN: return "WM_RBUTTONDOWN";
	case WM_RBUTTONUP: return "WM_RBUTTONUP";
	case WM_RBUTTONDBLCLK: return "WM_RBUTTONDBLCLK";
	case WM_MBUTTONDOWN: return "WM_MBUTTONDOWN";
	case WM_MBUTTONUP: return "WM_MBUTTONUP";
	case WM_MBUTTONDBLCLK: return "WM_MBUTTONDBLCLK";
	case WM_MOUSEWHEEL: return "WM_MOUSEWHEEL";
	case WM_MOUSEHWHEEL: return "WM_MOUSEHWHEEL";

		// Ű���� ����
	case WM_KEYDOWN: return "WM_KEYDOWN";
	case WM_KEYUP: return "WM_KEYUP";
	case WM_CHAR: return "WM_CHAR";
	case WM_DEADCHAR: return "WM_DEADCHAR";
	case WM_SYSKEYDOWN: return "WM_SYSKEYDOWN";
	case WM_SYSKEYUP: return "WM_SYSKEYUP";
	case WM_SYSCHAR: return "WM_SYSCHAR";
	case WM_SYSDEADCHAR: return "WM_SYSDEADCHAR";
	case WM_HOTKEY: return "WM_HOTKEY";

		// ��Ŭ���̾�Ʈ ����
	case WM_NCMOUSEMOVE: return "WM_NCMOUSEMOVE";
	case WM_NCLBUTTONDOWN: return "WM_NCLBUTTONDOWN";
	case WM_NCLBUTTONUP: return "WM_NCLBUTTONUP";
	case WM_NCLBUTTONDBLCLK: return "WM_NCLBUTTONDBLCLK";
	case WM_NCRBUTTONDOWN: return "WM_NCRBUTTONDOWN";
	case WM_NCRBUTTONUP: return "WM_NCRBUTTONUP";
	case WM_NCRBUTTONDBLCLK: return "WM_NCRBUTTONDBLCLK";
	case WM_NCMBUTTONDOWN: return "WM_NCMBUTTONDOWN";
	case WM_NCMBUTTONUP: return "WM_NCMBUTTONUP";
	case WM_NCMBUTTONDBLCLK: return "WM_NCMBUTTONDBLCLK";
	case WM_NCHITTEST: return "WM_NCHITTEST";
	case WM_NCPAINT: return "WM_NCPAINT";
	case WM_NCACTIVATE: return "WM_NCACTIVATE";

		// �ý��� ���
	case WM_SYSCOMMAND: return "WM_SYSCOMMAND";

		// ��Ÿ
	case WM_TIMER: return "WM_TIMER";
	case WM_COMMAND: return "WM_COMMAND";
	case WM_INITDIALOG: return "WM_INITDIALOG";

	default: return "Unknown Message";
	}
}

LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	switch (msg)
	{
	case WM_CREATE:
		printf("WM_CREATE: �����찡 �����Ǿ����ϴ�.\n");
		break;

	case WM_PAINT:
	{
		PAINTSTRUCT ps;
		HDC hDC = BeginPaint(hwnd, &ps);
		const char* text = "������ �޽������ ��";
		TextOutA(hDC, 10, 10, text, (int)strlen(text));
					
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
				Ellipse(hDC, left, top, right, bottom);
			}
		}

		EndPaint(hwnd, &ps);
		printf("WM_PAINT: ȭ�� �ٽ� �׸���\n");
	}
	break;

	case WM_KEYDOWN:
		printf("WM_KEYDOWN: VK_CODE = %d\n", (int)wParam);
		break;

	case WM_CHAR:
		printf("WM_CHAR: ���� �Է� = '%c'\n", (char)wParam);
		break;

	case WM_LBUTTONDOWN:
		printf("WM_LBUTTONDOWN: Ŭ�� ��ġ x=%d y=%d\n", LOWORD(lParam), HIWORD(lParam));
		break;
	
	// �޼����� �ʹ� ���� �����°��� ������� ����
	case WM_MOUSEMOVE:
	case WM_NCHITTEST:
	case WM_NCMOUSEMOVE:
	case WM_SETCURSOR:
		break;
	

	case WM_DESTROY:
		printf("WM_DESTROY: ���α׷� ����\n");
		PostQuitMessage(0);
		break;

	default:		
		printf("%s (0x%04X)\n", GetMessageName(msg), msg);
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

	MSG msg;
	// �޽��� ����
	while (GetMessage(&msg, NULL, 0, 0)) // GetMessage�� ť�� �޽����� ������ ���(Block)��	
	{
		TranslateMessage(&msg);	// �̺κ��� ���ָ�	WM_CHAR �̺�Ʈ����
		DispatchMessage(&msg);  // ������ ���ν����� �޽��� ����
	}

	UninitConsole();  // �ܼ� ��� ����
	return (int)msg.wParam;
}
