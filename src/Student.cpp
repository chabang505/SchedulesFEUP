//
// Created by Joao Ribeiro on 19/10/2022.
//

#include "Student.h"

using namespace std;

Student::Student(int id, string n, list<ClassUC> & c): id(id), name(std::move(n)), classes(c) {}

Student::Student(int id): id(id) {}

Student::Student(const Student &s) {
    this->name = s.name;
    this->id = s.id;
    this->classes = s.classes;
}

int Student::getId() const { return this->id; }

void Student::setId(int newId) { this->id = newId; }

string Student::getName() const { return this->name; }

void Student::setName(const string& newName) { this->name = newName; }

list<ClassUC> Student::getClasses() const { return this->classes; }

bool Student::operator < (const Student& s2) const {
    return this->id < s2.id;
}

bool Student::operator==(const Student &s2) const {
    return this->id == s2.id;
}

void Student::addClassUC(const ClassUC& newClass) {
    this->classes.push_back(newClass);
}

void Student::removeClassUC(const ClassUC& classToRemove) {
    this->classes.remove(classToRemove);
}