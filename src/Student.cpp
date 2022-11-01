//
// Created by Joao Ribeiro on 19/10/2022.
//

#include "Student.h"
#include "ClassUC.h"

using namespace std;

Student::Student(string n, int id, list<ClassUC> c): name(n), id(id), classes(c) {}

Student::Student(const Student &s) {
    this->name = s.name;
    this->id = s.id;
    this->classes = s.classes;
}

string Student::getName() { return this->name; }

void Student::setName(string newName) { this->name = newName; }

int Student::getId() { return this->id; }

void Student::setId(int newId) { this->id = newId; }

list<ClassUC> Student::getClasses() {

    return this->classes;
}
list<string> Student::getCodeClasses() { //turmas
    list<string> res;
    for (ClassUC c: classes){
        res.push_back(c.getCodeClass());
    }
    return res;
}
list<string> Student::getCodeUC() { //cadeiras
    list<string> res;
    for (ClassUC c: classes){
        res.push_back(c.getCodeUC());
    }
    return res;
}


