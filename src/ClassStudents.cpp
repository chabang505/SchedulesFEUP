//
// Created by johny on 02/11/2022.
//

#include "ClassStudents.h"

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