//
// Created by mattia on 30/08/22.
//

#include <numeric>
#include "Controller.h"

void Controller::min(int rigaIniziale, int rigaFinale, int colonnaIniziale, int colonnaFinale, wxGridTableBase *tab) {
    std::vector<int> celle;
    if (rigaIniziale == rigaFinale) {
        for (int i = colonnaIniziale; i < colonnaFinale; i++) {
            celle.push_back(wxAtoi(tab->GetValue(rigaIniziale, i)));
        }
        float minimo = (float)*std::min_element(celle.begin(), celle.end());
        tab->SetValue(rigaIniziale, colonnaFinale, wxString::Format(wxT("%g"), minimo)); // %g per non avere cifre decimali se non servono
    }
    if (colonnaIniziale == colonnaFinale) {
        for (int i = rigaIniziale; i < rigaFinale; i++) {
            celle.push_back(wxAtoi(tab->GetValue(i, colonnaIniziale)));
        }
        float minimo = (float)*std::min_element(celle.begin(), celle.end());
        tab->SetValue(rigaFinale, colonnaIniziale, wxString::Format(wxT("%g"), minimo));
    }

    tabella->setTable(tab);
}

void Controller::max(int rigaIniziale, int rigaFinale, int colonnaIniziale, int colonnaFinale, wxGridTableBase *tab) {
    std::vector<int> celle;
    if (rigaIniziale == rigaFinale) {
        for (int i = colonnaIniziale; i < colonnaFinale; i++) {
            celle.push_back(wxAtoi(tab->GetValue(rigaIniziale, i)));
        }
        float massimo = (float)*std::max_element(celle.begin(), celle.end());
        tab->SetValue(rigaIniziale, colonnaFinale, wxString::Format(wxT("%g"), massimo));
    }
    if (colonnaIniziale == colonnaFinale) {
        for (int i = rigaIniziale; i < rigaFinale; i++) {
            celle.push_back(wxAtoi(tab->GetValue(i, colonnaIniziale)));
        }
        float massimo = (float)*std::max_element(celle.begin(), celle.end());
        tab->SetValue(rigaFinale, colonnaIniziale, wxString::Format(wxT("%g"), massimo));
    }

    tabella->setTable(tab);
}

void Controller::media(int rigaIniziale, int rigaFinale, int colonnaIniziale, int colonnaFinale, wxGridTableBase *tab) {
    std::vector<int> celle;
    if (rigaIniziale == rigaFinale) {
        for (int i = colonnaIniziale; i < colonnaFinale; i++) {
            celle.push_back(wxAtoi(tab->GetValue(rigaIniziale, i)));
        }
        float media = (float)std::accumulate(celle.begin(), celle.end(), 0)/(float)celle.size();
        tab->SetValue(rigaIniziale, colonnaFinale, wxString::Format(wxT("%g"), media));
    }
    if (colonnaIniziale == colonnaFinale) {
        for (int i = rigaIniziale; i < rigaFinale; i++) {
            celle.push_back(wxAtoi(tab->GetValue(i, colonnaIniziale)));
        }
        float media = (float)std::accumulate(celle.begin(), celle.end(), 0)/(float)celle.size();
        tab->SetValue(rigaFinale, colonnaIniziale, wxString::Format(wxT("%g"), media));
    }

    tabella->setTable(tab);
}

void Controller::somma(int rigaIniziale, int rigaFinale, int colonnaIniziale, int colonnaFinale, wxGridTableBase *tab) {
    std::vector<int> celle;
    if (rigaIniziale == rigaFinale) {
        for (int i = colonnaIniziale; i < colonnaFinale; i++) {
            celle.push_back(wxAtoi(tab->GetValue(rigaIniziale, i)));
        }
        float somma = (float)std::accumulate(celle.begin(), celle.end(), 0);
        tab->SetValue(rigaIniziale, colonnaFinale, wxString::Format(wxT("%g"), somma));
    }
    if (colonnaIniziale == colonnaFinale) {
        for (int i = rigaIniziale; i < rigaFinale; i++) {
            celle.push_back(wxAtoi(tab->GetValue(i, colonnaIniziale)));
        }
        float somma = (float)std::accumulate(celle.begin(), celle.end(), 0);
        tab->SetValue(rigaFinale, colonnaIniziale, wxString::Format(wxT("%g"), somma));
    }

    tabella->setTable(tab);
}
