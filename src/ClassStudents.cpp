//
// Created by Joao Ribeiro on 02/11/2022.
//

#include "ClassStudents.h"

#include <utility>

ClassStudents::ClassStudents(string  cuc, string  cc, const vector<int> & s): codeUC(std::move(cuc)), codeClass(std::move(cc)), students(s) {}

ClassStudents::ClassStudents(const ClassStudents& c1) {
    this->codeUC = c1.codeUC;
    this->codeClass = c1.codeClass;
    this->students = c1.students;
}

string ClassStudents::getCodeUC() const{
    return this->codeUC;
}

void ClassStudents::setCodeUC(const string& newCodeUC) {
    this->codeUC = newCodeUC;
}

string ClassStudents::getCodeClass() const{
    return this->codeClass;
}

void ClassStudents::setCodeClass(const string& newCodeClass) {
    this->codeClass = newCodeClass;
}

void ClassStudents::addStudent(const int student) {
    this->students.push_back(student);
}