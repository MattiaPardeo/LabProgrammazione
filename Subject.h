//
// Created by mattia on 30/08/22.
//

#ifndef LABPROGRAMMAZIONE_SUBJECT_H
#define LABPROGRAMMAZIONE_SUBJECT_H

#include "Observer.h"

class Subject {
public:
    virtual ~Subject() {}
    virtual void notify() = 0;
    virtual void addObserver(Observer* o) = 0;
    virtual void removeObserver(Observer* o) = 0;
};


#endif //LABPROGRAMMAZIONE_SUBJECT_H
