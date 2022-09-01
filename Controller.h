//
// Created by mattia on 30/08/22.
//

#ifndef LABPROGRAMMAZIONE_CONTROLLER_H
#define LABPROGRAMMAZIONE_CONTROLLER_H

#include <wx/msgdlg.h>

#include "TabellaModel.h"

class Controller {
public:
    Controller(TabellaModel* tm) : tabella(tm){}

    void min(int rigaIniziale, int rigaFinale, int colonnaIniziale, int colonnaFinale, wxGridTableBase* tab);
    void max(int rigaIniziale, int rigaFinale, int colonnaIniziale, int colonnaFinale, wxGridTableBase* tab);
    void media(int rigaIniziale, int rigaFinale, int colonnaIniziale, int colonnaFinale, wxGridTableBase* tab);
    void somma(int rigaIniziale, int rigaFinale, int colonnaIniziale, int colonnaFinale, wxGridTableBase* tab);

private:
    TabellaModel* tabella;
};


#endif //LABPROGRAMMAZIONE_CONTROLLER_H
