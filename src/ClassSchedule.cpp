//
// Created by Joao Ribeiro on 19/10/2022.
//

#include "ClassSchedule.h"

ClassSchedule::ClassSchedule(string cuc, string cc, list<Slot> s): codeUC(cuc), codeClass(cc), slots(s) {}
ClassSchedule::ClassSchedule(const ClassSchedule &cs1) {
    this->codeUC = cs1.codeUC;
    this->codeClass = cs1.codeClass;
    this->slots = cs1.slots;
}

string ClassSchedule::getCodeUC() { return this->codeUC; }

void ClassSchedule::setCodeUC(string newCodeUC) { this->codeUC = newCodeUC; }

string ClassSchedule::getCodeClass() { return this->codeClass; }

void ClassSchedule::setCodeClass(string newCodeClass) { this->codeClass = newCodeClass; }

list<Slot> ClassSchedule::getSlots() { return slots; }

void ClassSchedule::setSlots(const list<Slot> &newSlots) { this->slots = newSlots; }

void ClassSchedule::addSlot(Slot &s1) {
    slots.push_back(s1);
}

int ClassSchedule::numOfSlots() { return slots.size(); }