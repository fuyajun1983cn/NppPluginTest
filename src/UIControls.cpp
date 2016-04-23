#include "UIControls.h"

#include "resource.h"

extern HANDLE g_hModule;

void UIControlsDialog::doModal(NppData *nppData, HWND parent)
{
	_nppData = nppData;
	::DialogBoxParam((HINSTANCE)g_hModule, MAKEINTRESOURCE(IDD_DIALOG), parent, UIControlsDialog::dlgProc, reinterpret_cast<LPARAM>(this));
}

BOOL UIControlsDialog::dlgProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	switch(message)
	{
		case WM_INITDIALOG:
			::SetWindowLongPtr(hWnd, GWL_USERDATA, lParam);
			return reinterpret_cast<UIControlsDialog*>(lParam)->run_dlgProc(hWnd, message, wParam, lParam);

		default:
		{
			UIControlsDialog* dlg = reinterpret_cast<UIControlsDialog*>(::GetWindowLongPtr(hWnd, GWL_USERDATA));
			if (dlg)
				return dlg->run_dlgProc(hWnd, message, wParam, lParam);
			else
				return FALSE;
		}
	}

}

BOOL UIControlsDialog::run_dlgProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM /*lParam*/)
{
	switch(message)
	{
		case WM_INITDIALOG:
			_hSelf = hWnd;
			return TRUE;

		case WM_COMMAND:
		{
			switch(LOWORD(wParam))
			{
				case IDOK:

				case IDCANCEL:
					::EndDialog(hWnd, 0);
			}
			return TRUE;
		}

		default:
			return FALSE;
	}



}
