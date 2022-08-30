//
// Created by mattia on 30/08/22.
//

#ifndef LABPROGRAMMAZIONE_CONTROLLER_H
#define LABPROGRAMMAZIONE_CONTROLLER_H

#include "TabellaModel.h"

class Controller {
public:
    Controller(TabellaModel* tm) : tabella(tm){}

private:
    TabellaModel* tabella;
};


#endif //LABPROGRAMMAZIONE_CONTROLLER_H
