//
// Created by johny on 18/10/2022.
//

#ifndef PROJ1_CLASSUC_H
#define PROJ1_CLASSUC_H

#include <string>
#include <sstream>
using namespace std;

class ClassUC {

    string codeUC;
    string codeClass;

    ClassUC(string cUC, string cc);
    ClassUC(const ClassUC& c1);
    string getCodeUC();
    void setCodeUC(newCodeUC);
    string getCodeClass();
    void setCodeClass(newCodeClass);
    bool operator==(const ClassUC& c2) const;
    string write() const;

};


#endif //PROJ1_CLASSUC_H
