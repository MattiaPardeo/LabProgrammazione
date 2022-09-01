//
// Created by mattia on 30/08/22.
//

#include "Controller.h"

void Controller::min(int rigaIniziale, int rigaFinale, int colonnaIniziale, int colonnaFinale, wxGridTableBase *tab) {
    std::vector<int> colonna;
    if (rigaIniziale == rigaFinale) {
        for (int i = colonnaIniziale; i < colonnaFinale; i++) {
            colonna.push_back(wxAtoi(tab->GetValue(rigaIniziale, i)));
        }
        int minimo = *std::min_element(colonna.begin(), colonna.end());
        tab->SetValue(rigaIniziale, colonnaFinale, wxString::Format(wxT("%i"), minimo));
    }
    if (colonnaIniziale == colonnaFinale) {
        for (int i = rigaIniziale; i < rigaFinale; i++) {
            colonna.push_back(wxAtoi(tab->GetValue(i, colonnaIniziale)));
        }
        int minimo = *std::min_element(colonna.begin(), colonna.end());
        tab->SetValue(rigaFinale, colonnaIniziale, wxString::Format(wxT("%i"), minimo));
    }

    tabella->setTable(tab);
}

void Controller::max(int rigaIniziale, int rigaFinale, int colonnaIniziale, int colonnaFinale, wxGridTableBase *tab) {
    std::vector<int> colonna;
    if (rigaIniziale == rigaFinale) {
        for (int i = colonnaIniziale; i < colonnaFinale; i++) {
            colonna.push_back(wxAtoi(tab->GetValue(rigaIniziale, i)));
        }
        int massimo = *std::max_element(colonna.begin(), colonna.end());
        tab->SetValue(rigaIniziale, colonnaFinale, wxString::Format(wxT("%i"), massimo));
    }
    if (colonnaIniziale == colonnaFinale) {
        for (int i = rigaIniziale; i < rigaFinale; i++) {
            colonna.push_back(wxAtoi(tab->GetValue(i, colonnaIniziale)));
        }
        int massimo = *std::max_element(colonna.begin(), colonna.end());
        tab->SetValue(rigaFinale, colonnaIniziale, wxString::Format(wxT("%i"), massimo));
    }

    tabella->setTable(tab);
}

void Controller::media(int rigaIniziale, int rigaFinale, int colonnaIniziale, int colonnaFinale, wxGridTableBase *tab) {

}

void Controller::somma(int rigaIniziale, int rigaFinale, int colonnaIniziale, int colonnaFinale, wxGridTableBase *tab) {

}
