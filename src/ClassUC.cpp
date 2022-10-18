//
// Created by johny on 18/10/2022.
//

#include "ClassUC.h"

ClassUC::ClassUC(string cUC, string cc): codeUC(cUC), codeClass(cc) {}
ClassUC::ClassUC(const ClassUC& c1) {
    this->codeUC = c1.codeUC;
    this->codeClass = c1.codeClass;
}

string ClassUC::getCodeUC() { return this->codeUC; }

void ClassUC::setCodeUC(string newCodeUC) { this->codeUC = newCodeUC; }

string ClassUC::getCodeClass() { return this->codeClass; }

void ClassUC::setCodeClass(string newCodeClass) { this->codeClass = newCodeClass; }

bool ClassUC::operator==(const ClassUC &c2) const {
    return (this->codeUC == c2.codeUC && this->codeClass == c2.codeClass);
}

string ClassUC::write() const {
    stringstream oss;
    oss << codeUC << "\n" << codeClass;
    return oss.str();
}