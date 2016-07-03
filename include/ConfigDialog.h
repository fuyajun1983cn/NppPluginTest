#ifndef CONFIGDIALOG_H
#define CONFIGDIALOG_H

#include "StaticDialog.h"
#include "windows.h"

struct NppData;

class ConfigDialog : public StaticDialog
{
    public:
        ConfigDialog();
        void init(HINSTANCE hInst, NppData *nppData);
        void doDialog(int FuncCmdId=0);
         virtual void destroy() {
                // remove data
                _nppData = nullptr;
         }

    protected:
            INT_PTR CALLBACK run_dlgProc(UINT message, WPARAM wParam, LPARAM lParam) ;
    private:
          /* Handles */
          NppData			*_nppData;
          int _cmdId;
};

#endif // CONFIGDIALOG_H
