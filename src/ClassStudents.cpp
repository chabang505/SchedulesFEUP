//
// Created by Joao Ribeiro on 02/11/2022.
//

#include "ClassStudents.h"

ClassStudents::ClassStudents(string cuc, string cc, vector<int> s): codeUC(cuc), codeClass(cc), students(s) {}

ClassStudents::ClassStudents(const ClassStudents& c1) {
    this->codeUC = c1.codeUC;
    this->codeClass = c1.codeClass;
    this->students = c1.students;
}

string ClassStudents::getCodeUC() {
    return this->codeUC;
}

void ClassStudents::setCodeUC(const std::string newCodeUC) {
    this->codeUC = newCodeUC;
}

string ClassStudents::getCodeClass() {
    return this->codeClass;
}

void ClassStudents::setCodeClass(const std::string newCodeClass) {
    this->codeClass = newCodeClass;
}

void ClassStudents::addStudent(int student) {
    this->students.push_back(student);
}