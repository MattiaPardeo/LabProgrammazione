//
// Created by mattia on 30/08/22.
//

#ifndef LABPROGRAMMAZIONE_TABELLAMODEL_H
#define LABPROGRAMMAZIONE_TABELLAMODEL_H

#include "Subject.h"
#include <list>
#include <wx/grid.h>

class TabellaModel : public Subject{
public:
    TabellaModel();
    wxGridTableBase* getTable();
    void setTable(wxGridTableBase *tabella);
    void addObserver(Observer* o) override;
    void removeObserver(Observer* o) override;
    void notify() override;
private:
    std::list<Observer*> obs;
    wxGridTableBase* tabella;
};


#endif //LABPROGRAMMAZIONE_TABELLAMODEL_H
