//
// Created by mattia on 30/08/22.
//

#ifndef LABPROGRAMMAZIONE_FINESTRAVIEW_H
#define LABPROGRAMMAZIONE_FINESTRAVIEW_H

#include <wx/frame.h>
#include <wx/grid.h>
#include <wx/button.h>
#include <wx/sizer.h>

#include "Observer.h"
#include "TabellaModel.h"
#include "Controller.h"

class FinestraView : public wxFrame, public Observer{
public:
    FinestraView(TabellaModel* model, Controller* ctrl, wxWindow* parent=nullptr, wxWindowID id = wxID_ANY,
                 const wxString& title = wxEmptyString, const wxPoint& pos = wxDefaultPosition,
                 const wxSize& size = wxSize( 1290,720 ), long style = wxDEFAULT_FRAME_STYLE|wxTAB_TRAVERSAL );
    ~FinestraView() override;
    void update() override;

    void onMinClick(wxCommandEvent& event);
    void onMaxClick(wxCommandEvent& event);
    void onMediaClick(wxCommandEvent& event);
    void onSommaClick(wxCommandEvent& event);
private:
    wxGrid* griglia;
    wxButton* min;
    wxButton* max;
    wxButton* media;
    wxButton* somma;

    Controller* controller;
    TabellaModel* tabella;
};


#endif //LABPROGRAMMAZIONE_FINESTRAVIEW_H
