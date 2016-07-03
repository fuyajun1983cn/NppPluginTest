#include "ConfigDialog.h"
#include "resource.h"
#include "PluginDefinition.h"

ConfigDialog::ConfigDialog()
{
    //ctor
}

void ConfigDialog::init(HINSTANCE hInst, NppData *nppData)
{
    _nppData = nppData;
    Window::init(hInst, nppData->_nppHandle);
}

void ConfigDialog::doDialog(int FuncCmdId)
{
     if (!isCreated()) {
              create(IDD_DIALOG);
     }

     _cmdId = FuncCmdId;

      // position dialog to the center of the screen
      goToCenter();

}

BOOL CALLBACK ConfigDialog::run_dlgProc(UINT Message, WPARAM wParam, LPARAM lParam)
{
   switch (Message)
   {
   case WM_INITDIALOG :
      {
         return TRUE;
      }
   case WM_CLOSE :
      {
         ::SendMessage(_hParent, NPPM_SETMENUITEMCHECK, (WPARAM)_cmdId, (LPARAM)false);
         break;
      }

   case WM_COMMAND :
      {
         switch (wParam)
         {
                case IDC_OK:

				case IDC_CANCEL:
					::EndDialog(_hSelf, 0);
                    return TRUE;

                 default :
                    break;
         }
         break;
      }
   case WM_SIZE :
      {
         break;
      }
   case WM_DESTROY:
      {
         break;
      }
   default:;
   } // switch


   return FALSE;
}
