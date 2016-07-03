#include "FindDlg.h"
#include "PluginInterface.h"

#include "resource.h"
#include "PluginDefinition.h"

FindDlg::FindDlg()
:DockingDlgInterface(IDD_DIALOG)
{
    //ctor
}

FindDlg::~FindDlg()
{
    //dtor
    _nppData = nullptr;
}

void FindDlg::showDialog()
{
    if (!isCreated()) {
         tTbData   data = {0};
         RECT rect={0,0,0,0};
         create(&data);
         ::SendMessage(_nppData->_nppHandle, NPPM_DMMREGASDCKDLG, 0, (LPARAM)&data);
    }

    display(isVisible());

}

void FindDlg::init(HINSTANCE hInst, NppData *nppData)
{
    _nppData = nppData;
    DockingDlgInterface::init(hInst, _nppData->_nppHandle);
}

void FindDlg::create(tTbData * data, bool isRTL)
{
    DockingDlgInterface::create(data, isRTL);

       // user information
   data->dlgID       = _dlgID;
   data->pszModuleName = _T("FindDlg");

   // supported features by plugin
   data->uMask	= (DWS_DF_CONT_RIGHT | DWS_PARAMSALL);
}

void FindDlg::display(bool toShow) const {
   if (toShow == isVisible()) return;
   DockingDlgInterface::display(toShow);
}
