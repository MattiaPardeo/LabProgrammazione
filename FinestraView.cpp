//
// Created by mattia on 30/08/22.
//

#include "FinestraView.h"

void FinestraView::update() {
    griglia->SetTable(tabella->getTable());

}

FinestraView::FinestraView(TabellaModel *model, Controller *ctrl, wxWindow *parent, wxWindowID id,
                           const wxString &title, const wxPoint &pos, const wxSize &size, long style) : tabella(model),
                           controller(ctrl), wxFrame( parent, id, title, pos, size, style ) {

    tabella->addObserver(this);
    griglia = new wxGrid(this, -1);
    griglia->SetTable(tabella->getTable());
    griglia->SetGridLineColour(*wxBLACK);
    griglia->DisableDragGridSize();
}
