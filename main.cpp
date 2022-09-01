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
    wxMessageDialog *dial = new wxMessageDialog(NULL, wxT("FUNZIONAMENTO: selezionare trascinando col "
                                                          "mouse una sola riga od una sola colonna su cui effettuare le "
                                                          "operazioni, l'ultima cella a destra (se riga) o l'ultima cella in "
                                                          "basso (se colonna) sarà la cella su cui verrà stampato il risultato"),
                                                wxT("Info"), wxOK);
    dial->ShowModal();
    delete dial;

    return true;
}