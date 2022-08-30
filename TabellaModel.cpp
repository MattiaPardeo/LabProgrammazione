//
// Created by mattia on 30/08/22.
//

#include "TabellaModel.h"

TabellaModel::TabellaModel() {
    tabella = new wxGridStringTable(10, 10);
}

wxGridTableBase* TabellaModel::getTable() {
    return tabella;
}

void TabellaModel::setTable(wxGridTableBase *tabella) {
    this->tabella = tabella;
}

void TabellaModel::addObserver(Observer *o) {
    obs.push_back(o);
}

void TabellaModel::removeObserver(Observer *o) {
    obs.remove(o);
}

void TabellaModel::notify() {
    for (Observer* observer : obs)
        observer->update();
}
