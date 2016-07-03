#ifndef FINDDLG_H
#define FINDDLG_H

#include "DockingDlgInterface.h"

struct NppData;

class FindDlg : public DockingDlgInterface
{
    public:
        FindDlg();
        virtual ~FindDlg();

           void init(HINSTANCE hInst, NppData *nppData);

            void create(tTbData * data, bool isRTL = false);

            void display(bool toShow = true) const ;

            void showDialog();

    protected:

    private:
                  NppData			*_nppData;
};

#endif // FINDDLG_H
