//
// Created by Joao Ribeiro on 19/10/2022.
//

#include "ClassSchedule.h"

#include <utility>

ClassSchedule::ClassSchedule(string cuc, string cc, list<Slot> & s):
    codeUC(move(cuc)), codeClass(move(cc)), slots(s) {}

ClassSchedule::ClassSchedule(const ClassSchedule &cs1) {
    this->codeUC = cs1.codeUC;
    this->codeClass = cs1.codeClass;
    this->slots = cs1.slots;
}

string ClassSchedule::getCodeUC() const { return this->codeUC; }

void ClassSchedule::setCodeUC(string newCodeUC) { this->codeUC = newCodeUC; }

string ClassSchedule::getCodeClass() const { return this->codeClass; }

void ClassSchedule::setCodeClass(string newCodeClass) { this->codeClass = newCodeClass; }

list<Slot> ClassSchedule::getSlots() const { return slots; }

void ClassSchedule::setSlots(const list<Slot> &newSlots) { this->slots = newSlots; }

void ClassSchedule::addSlot(Slot &s1) {
    slots.push_back(s1);
}

int ClassSchedule::numOfSlots() const { return slots.size(); }

bool ClassSchedule::isCompatible(const ClassSchedule &cs2) {
    for (Slot s1: this->slots)
        for (Slot s2: cs2.slots)
            if (!s1.isCompatible(s2))
                return false;
    return true;
}