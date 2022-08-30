//
// Created by mattia on 30/08/22.
//

#ifndef LABPROGRAMMAZIONE_FINESTRAVIEW_H
#define LABPROGRAMMAZIONE_FINESTRAVIEW_H

#include <wx/frame.h>
#include <wx/grid.h>
#include "Observer.h"
#include "TabellaModel.h"
#include "Controller.h"

class FinestraView : public wxFrame, public Observer{
public:
    FinestraView(TabellaModel* model, Controller* ctrl, wxWindow* parent=nullptr, wxWindowID id = wxID_ANY,
                 const wxString& title = wxEmptyString, const wxPoint& pos = wxDefaultPosition,
                 const wxSize& size = wxSize( 1280,720 ), long style = wxDEFAULT_FRAME_STYLE|wxTAB_TRAVERSAL );
    void update() override;
private:
    wxGrid *griglia;

    Controller *controller;
    TabellaModel *tabella;
};


#endif //LABPROGRAMMAZIONE_FINESTRAVIEW_H
