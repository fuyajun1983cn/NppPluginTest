#ifndef UICONTROLS_DIALOG_H
#define UICONTROLS_DIALOG_H

#include "windows.h"

struct NppData;

class UIControlsDialog
{
    public:
        UIControlsDialog():_nppData(NULL) , _hSelf(NULL) {}
        virtual ~UIControlsDialog() {}

        void doModal(NppData *nppData, HWND parent);

    private:
        static BOOL CALLBACK dlgProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);
        BOOL CALLBACK run_dlgProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);

        NppData *_nppData;
        HWND   _hSelf;
};

#endif // UICONTROLS_H
