//
// Created by Joao Ribeiro on 19/10/2022.
//

#include "Student.h"

using namespace std;

Student::Student(int id, string n, list<ClassUC> c): id(id), name(n), classes(c) {}

Student::Student(const Student &s) {
    this->name = s.name;
    this->id = s.id;
    this->classes = s.classes;
}

string Student::getName() { return this->name; }

void Student::setName(string newName) { this->name = newName; }

int Student::getId() { return this->id; }

void Student::setId(int newId) { this->id = newId; }

list<ClassUC> Student::getClasses() { return this->classes; }

bool Student::operator < (const Student& s2) const {
    return this->id < s2.id;
}

void Student::addClass(const ClassUC& newClass) {
    this->classes.push_back(newClass);
}