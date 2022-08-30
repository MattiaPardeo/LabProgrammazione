//
// Created by mattia on 30/08/22.
//

#include "Controller.h"

void Controller::min(int rigaIniziale, int rigaFinale, int colonnaIniziale, int colonnaFinale, const wxGrid* griglia) {
    if (rigaIniziale != rigaFinale && colonnaIniziale != colonnaFinale){
        wxMessageDialog *dial = new wxMessageDialog(NULL,wxT("Selezionare una sola riga od una sola colonna"), wxT("Errore"), wxOK);
        dial->ShowModal();
        delete dial;
    } else {
        wxGridTableBase* tab = griglia->GetTable();
        std::vector<int> colonna;
        if(rigaIniziale == rigaFinale){
            for (int i = colonnaIniziale; i < colonnaFinale; i++){
                colonna.push_back(wxAtoi(tab->GetValue(rigaIniziale, i)));
            }
            int minimo = *std::min_element(colonna.begin(), colonna.end());
            tab->SetValue(rigaIniziale, colonnaFinale, wxString::Format(wxT("%i"),minimo));
        }
        if(colonnaIniziale == colonnaFinale){
            for (int i = rigaIniziale; i < rigaFinale; i++){
                colonna.push_back(wxAtoi(tab->GetValue(i, colonnaIniziale)));
            }
            int minimo = *std::min_element(colonna.begin(), colonna.end());
            tab->SetValue(rigaFinale, colonnaIniziale, wxString::Format(wxT("%i"),minimo));
        }

        tabella->setTable(tab);
    }
}

void Controller::max(int rigaIniziale, int rigaFinale, int colonnaIniziale, int colonnaFinale, wxGrid* griglia) {

}

void Controller::media(int rigaIniziale, int rigaFinale, int colonnaIniziale, int colonnaFinale, wxGrid* griglia) {

}

void Controller::somma(int rigaIniziale, int rigaFinale, int colonnaIniziale, int colonnaFinale, wxGrid* griglia) {

}
