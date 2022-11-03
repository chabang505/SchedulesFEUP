//
// Created by Joao Ribeiro on 02/11/2022.
//

#include "Year.h"

Year::Year(int n): number(n) {}

Year::Year(int n, list<UC> ucs): number(n), ucs(ucs) {}

Year::Year(const Year& y1) {
    this->number = y1.number;
    this->ucs = y1.ucs;
}

int Year::getNumber() {
    return this->number;
}

list<UC> Year::getUCs() {
    return this->ucs;
}

list<UC>::iterator Year::end() {
    return ucs.end();
}

list<UC>::iterator Year::findUC(const string& codeUC) {
    for (auto it = this->ucs.begin(); it != this->ucs.end(); it++) {
        if ((*it).getCode() == codeUC)
            return it;
    }
    return this->ucs.end();
}

void Year::addUC(const UC &uc) {
    this->ucs.push_back(uc);
}

void Year::removeUC(const UC &uc) {
    this->ucs.remove(uc);
}
