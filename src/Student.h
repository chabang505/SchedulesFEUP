//
// Created by Joao Ribeiro on 19/10/2022.
//

#ifndef PROJ1_STUDENT_H
#define PROJ1_STUDENT_H

#include <string>
#include <list>

#include "ClassUC.h"

using namespace std;

class Student {
    string name;
    int id;
    list<ClassUC> classes;

public:
    Student(string n, int id, list<ClassUC> c);
    Student(const Student& s);
    string getName();
    void setName(string newName);
    int getId();
    void setId(int newId);
    list<ClassUC> getClasses();

    list<string> getCodeClasses();

    list<string> getCodeUC();
};


#endif //PROJ1_STUDENT_H
