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

    void min(int rigaIniziale, int rigaFinale, int colonnaIniziale, int colonnaFinale, const wxGrid* griglia);
    void max(int rigaIniziale, int rigaFinale, int colonnaIniziale, int colonnaFinale, wxGrid* griglia);
    void media(int rigaIniziale, int rigaFinale, int colonnaIniziale, int colonnaFinale, wxGrid* griglia);
    void somma(int rigaIniziale, int rigaFinale, int colonnaIniziale, int colonnaFinale, wxGrid* griglia);

private:
    TabellaModel* tabella;
};


#endif //LABPROGRAMMAZIONE_CONTROLLER_H
