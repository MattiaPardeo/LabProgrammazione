//
// Created by mattia on 30/08/22.
//

#include "TabellaModel.h"

TabellaModel::TabellaModel() {
    tabella = new wxGridStringTable(26, 15);
}

wxGridTableBase* TabellaModel::getTable() {
    return tabella;
}

void TabellaModel::setTable(wxGridTableBase *tab) {
    this->tabella = tab;
    notify();
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
