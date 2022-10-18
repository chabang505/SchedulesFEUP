//
// Created by johny on 19/10/2022.
//

#ifndef PROJ1_CLASSSCHEDULE_H
#define PROJ1_CLASSSCHEDULE_H

#include <string>
#include <List>

#include "Slot.h"

class ClassSchedule {
    string codeUC;
    string codeClass;
    List<Slot> slots;

    ClassSchedule(string cuc, string cc, List<Slot> s);
    ClassSchedule(const ClassSchedule& cs1);
    string getCodeUC();
    void setCodeUC(string newCodeUC);
    string getCodeClass();
    void setCodeClass(string newCodeClass);
    List<Slot> getSlots();
    void setSlots(const List<Slot> &newSlots);
    void addSlot(Slot& s1);
    int numOfSlots();

};


#endif //PROJ1_CLASSSCHEDULE_H
