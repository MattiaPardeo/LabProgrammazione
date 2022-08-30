#include <iostream>
#include <wx/wxprec.h>
#ifndef WX_PRECOMP
    #include <wx/wx.h>
#endif

#include "FinestraView.h"
#include "TabellaModel.h"
#include "Controller.h"

class MyApp: public wxApp
{
public:
    virtual bool OnInit();
};

wxIMPLEMENT_APP(MyApp);

bool MyApp::OnInit() {
    TabellaModel *tabella = new TabellaModel();
    Controller *ctrl = new Controller(tabella);
    FinestraView *finestra = new FinestraView(tabella, ctrl);
    finestra->Show();

    return true;
}