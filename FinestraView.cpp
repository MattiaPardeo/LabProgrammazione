//
// Created by mattia on 30/08/22.
//

#include "FinestraView.h"

FinestraView::FinestraView(TabellaModel *model, Controller *ctrl, wxWindow *parent, wxWindowID id,
                           const wxString &title, const wxPoint &pos, const wxSize &size, long style) : tabella(model),
                           controller(ctrl), wxFrame( parent, id, title, pos, size, style ) {

    //this->SetMaxSize(size);
    //this->SetMinSize(size);

    tabella->addObserver(this);

    griglia = new wxGrid(this, wxID_ANY);
    griglia->SetTable(tabella->getTable());
    griglia->SetGridLineColour(*wxBLACK);
    griglia->DisableDragGridSize();

    min = new wxButton(this, wxID_ANY,wxT("Minimo"), wxDefaultPosition, wxDefaultSize, 0 );
    max = new wxButton(this, wxID_ANY,wxT("Massimo"), wxDefaultPosition, wxDefaultSize, 0 );
    media = new wxButton(this, wxID_ANY,wxT("Media"), wxDefaultPosition, wxDefaultSize, 0 );
    somma = new wxButton(this, wxID_ANY,wxT("Somma"), wxDefaultPosition, wxDefaultSize, 0 );

    wxBoxSizer* sizerPulsanti = new wxBoxSizer(wxHORIZONTAL);
    sizerPulsanti->Add(min, 0, wxALL, 5);
    sizerPulsanti->Add(max, 0, wxALL, 5);
    sizerPulsanti->Add(media, 0, wxALL, 5);
    sizerPulsanti->Add(somma, 0, wxALL, 5);
    //Layout();
    wxBoxSizer* sizerFinestra = new wxBoxSizer(wxVERTICAL);

    sizerFinestra->Add(griglia, 1, wxEXPAND, 5);
    sizerFinestra->Add(sizerPulsanti, 1, wxEXPAND, 5);
    this->SetSizer(sizerFinestra);

    min->Connect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(FinestraView::onMinClick), nullptr, this);
    max->Connect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(FinestraView::onMaxClick), nullptr, this);
    media->Connect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(FinestraView::onMediaClick), nullptr, this);
    somma->Connect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(FinestraView::onSommaClick), nullptr, this);
}

FinestraView::~FinestraView(){
    min->Disconnect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(FinestraView::onMinClick), nullptr, this);
    max->Disconnect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(FinestraView::onMaxClick), nullptr, this);
    media->Disconnect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(FinestraView::onMediaClick), nullptr, this);
    somma->Disconnect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(FinestraView::onSommaClick), nullptr, this);

    tabella->removeObserver(this);
}

void FinestraView::update() {
    griglia->SetTable(tabella->getTable());
    griglia->Refresh();
}

void FinestraView::onMinClick(wxCommandEvent& event) {
    wxGridCellCoordsArray btl = griglia->GetSelectionBlockTopLeft();
    wxGridCellCoordsArray bbr = griglia->GetSelectionBlockBottomRight();

    int rigaIniziale = btl[0].GetRow();
    int colonnaIniziale = btl[0].GetCol();
    int rigaFinale = bbr[0].GetRow();
    int colonnaFinale = bbr[0].GetCol();

    controller->min(rigaIniziale, rigaFinale, colonnaIniziale, colonnaFinale, griglia);
}

void FinestraView::onMaxClick(wxCommandEvent& event) {
    wxGridCellCoordsArray btl = griglia->GetSelectionBlockTopLeft();
    wxGridCellCoordsArray bbr = griglia->GetSelectionBlockBottomRight();

    int rigaIniziale = btl[0].GetRow();
    int colonnaIniziale = btl[0].GetCol();
    int rigaFinale = bbr[0].GetRow();
    int colonnaFinale = bbr[0].GetCol();

    controller->max(rigaIniziale, rigaFinale, colonnaIniziale, colonnaFinale, griglia);
}

void FinestraView::onMediaClick(wxCommandEvent& event) {
    wxGridCellCoordsArray btl = griglia->GetSelectionBlockTopLeft();
    wxGridCellCoordsArray bbr = griglia->GetSelectionBlockBottomRight();

    int rigaIniziale = btl[0].GetRow();
    int colonnaIniziale = btl[0].GetCol();
    int rigaFinale = bbr[0].GetRow();
    int colonnaFinale = bbr[0].GetCol();

    controller->media(rigaIniziale, rigaFinale, colonnaIniziale, colonnaFinale, griglia);
}

void FinestraView::onSommaClick(wxCommandEvent& event) {
    wxGridCellCoordsArray btl = griglia->GetSelectionBlockTopLeft();
    wxGridCellCoordsArray bbr = griglia->GetSelectionBlockBottomRight();

    int rigaIniziale = btl[0].GetRow();
    int colonnaIniziale = btl[0].GetCol();
    int rigaFinale = bbr[0].GetRow();
    int colonnaFinale = bbr[0].GetCol();

    controller->somma(rigaIniziale, rigaFinale, colonnaIniziale, colonnaFinale, griglia);
}
