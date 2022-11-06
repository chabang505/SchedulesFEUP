//
// Created by Joao Ribeiro on 19/10/2022.
//

#include "Student.h"

#include <utility>

using namespace std;

Student::Student(int id, string n, list<ClassUC> & c) {
    this->id = id;
    this->name = std::move(n);
    this->classes = c;
    this->numClasses = this->classes.size();
}

Student::Student(int id): id(id) {}

Student::Student(int id, int nc): id(id), numClasses(nc) {}

Student::Student(const Student &s) {
    this->name = s.name;
    this->id = s.id;
    this->numClasses = s.classes.size();
    this->classes = s.classes;
}

int Student::getId() const { return this->id; }

void Student::setId(int newId) { this->id = newId; }

string Student::getName() const { return this->name; }

void Student::setName(const string& newName) { this->name = newName; }

list<ClassUC> Student::getClasses() const { return this->classes; }

size_t Student::getNumClasses() const {
    return this->numClasses;
}

bool Student::operator < (const Student& s2) const {
    if (this->numClasses == s2.numClasses)
        return this->id < s2.id;
    return this->numClasses < s2.numClasses;
}

bool Student::operator==(const Student &s2) const {
    return this->id == s2.id;
}

void Student::addClassUC(const ClassUC& newClass) {
    this->classes.push_back(newClass);
    this->numClasses = classes.size();
}

void Student::removeClassUC(const ClassUC& classToRemove) {
    this->classes.remove(classToRemove);
    this->numClasses = classes.size();
}