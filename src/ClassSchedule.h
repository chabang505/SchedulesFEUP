//
// Created by Joao Ribeiro on 19/10/2022.
//

#ifndef PROJ1_CLASSSCHEDULE_H
#define PROJ1_CLASSSCHEDULE_H

#include <string>
#include <list>

#include "Slot.h"

using namespace std;

class ClassSchedule {
    string codeUC;
    string codeClass;
    list<Slot> slots;

public:
    ClassSchedule(string cuc, string cc, list<Slot> s);
    ClassSchedule(const ClassSchedule& cs1);
    string getCodeUC();
    void setCodeUC(string newCodeUC);
    string getCodeClass();
    void setCodeClass(string newCodeClass);
    list<Slot> getSlots();
    void setSlots(const list<Slot> &newSlots);
    void addSlot(Slot& s1);
    int numOfSlots();

};


#endif //PROJ1_CLASSSCHEDULE_H
