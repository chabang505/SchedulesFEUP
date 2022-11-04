//
// Created by Joao Ribeiro on 18/10/2022.
//

#include "ClassUC.h"

ClassUC::ClassUC(string cUC, string cc): codeUC(cUC), codeClass(cc), numStudents(0) {}
ClassUC::ClassUC(const ClassUC& c1) {
    this->codeUC = c1.codeUC;
    this->codeClass = c1.codeClass;
    this->numStudents = 0;
}

string ClassUC::getCodeUC() const { return this->codeUC; }

void ClassUC::setCodeUC(string newCodeUC) { this->codeUC = newCodeUC; }

string ClassUC::getCodeClass() const { return this->codeClass; }

void ClassUC::setCodeClass(string newCodeClass) { this->codeClass = newCodeClass; }

string ClassUC::write() const {
    stringstream oss;
    oss << codeUC << "\n" << codeClass;
    return oss.str();
}

int ClassUC::getNumStudents() const{
    return numStudents;
}

bool ClassUC::operator==(const ClassUC &c2) const {
    return (this->codeUC == c2.codeUC && this->codeClass == c2.codeClass);
}

bool ClassUC::operator< (const ClassUC& c2) const {
    if (this->codeClass == c2.codeClass)
        return this->codeUC < c2.codeUC;
    else
        return this->codeClass < c2.codeClass;
}