//
// Created by mattia on 30/08/22.
//

#ifndef LABPROGRAMMAZIONE_OBSERVER_H
#define LABPROGRAMMAZIONE_OBSERVER_H

class Observer {
public:
    virtual ~Observer() {}
    virtual	void update() = 0;
};


#endif //LABPROGRAMMAZIONE_OBSERVER_H
