//
// Created by Joao Ribeiro on 18/10/2022.
//

#include "ClassUC.h"

ClassUC::ClassUC(string cUC, string cc): codeUC(cUC), codeClass(cc), numStudents(0) {}

ClassUC::ClassUC(std::string cUC) {
    this->codeUC = cUC;
    int numPart = stoi(cUC.substr(5, 3));
    if (numPart < 10) {
        this->codeClass = "1LEIC01";
    } else if (numPart < 20) {
        this->codeClass = "2LEIC01";
    } else
        this->codeClass = "3LEIC01";
}

ClassUC::ClassUC(const ClassUC& c1) {
    this->codeUC = c1.codeUC;
    this->codeClass = c1.codeClass;
    this->numStudents = c1.numStudents;
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
    if (this->codeUC == c2.codeUC)
        return this->codeClass < c2.codeClass;
    else
        return this->codeUC < c2.codeUC;
}

ClassUC ClassUC::operator ++(int) {
    ClassUC temp(*this);
    numStudents++;
    temp.numStudents = numStudents;
    return temp;
}

ClassUC ClassUC::operator --(int) {
    ClassUC temp(*this);
    numStudents--;
    temp.numStudents = numStudents;
    return temp;
}

bool ClassUC::hasCapacity() const {
    return cap > numStudents + 1;
}

ClassUC ClassUC::nextUC() {
    ClassUC temp = ClassUC(*this);
    int numPart = stoi(codeUC.substr(5, 3));
    if (numPart % 5 == 0) {
        if (numPart == 25) {
            temp.codeUC = "UP001";
            temp.codeClass = "1LEIC01";
            return temp;
        }
        numPart += 5;
        int numYear = stoi(codeClass.substr(0, 1));
        numYear += 1;
        string newClassCode = to_string(numYear) + codeClass.substr(1, 6);
        temp.codeClass = newClassCode;
    }
    numPart += 1;
    stringstream s;
    s << setw(3) << setfill('0') << to_string(numPart);
    string newNumPart;
    s >> newNumPart;
    string newUCCode = codeUC.substr(0, 5) + newNumPart;
    temp.codeUC = newUCCode;
    return temp;
}