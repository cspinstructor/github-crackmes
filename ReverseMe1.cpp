#include <Windows.h>
#include "resource.h"

//page 40 HNP book

BOOL CALLBACK Callback(HWND, UINT, WPARAM, LPARAM);
HWND hDlg;

int WINAPI
WinMain(HINSTANCE h, HINSTANCE p, LPSTR s, int n)
{
	hDlg = CreateDialog(h, MAKEINTRESOURCE(IDD_DIALOG1), 0, Callback);
	ShowWindow(hDlg, SW_SHOWNORMAL);
	MSG msg;
	while (GetMessage(&msg, hDlg, 0, 0))//0 is WM_QUIT
	{
		if (!IsDialogMessage(hDlg, &msg))
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
	}
	return 0;
}

BOOL CALLBACK Callback(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	char szIP[48] = { 0 };

	switch (message)
	{
	case WM_COMMAND:
		switch (LOWORD(wParam))
		{
		case IDOK:
			GetDlgItemText(hDlg, IDC_EDIT1, szIP, 48);
			MessageBox(0, szIP, "Sorry", MB_OK);
			break;
		case IDABOUT:
			MessageBox(0, szIP, "About", MB_OK);
		case IDCANCEL:
			PostQuitMessage(0);
		}
		break;
	}
	return 0;
}