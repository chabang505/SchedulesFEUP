//
// Created by Joao Ribeiro on 02/11/2022.
//

#include "Turma.h"

Turma::Turma(string c): code(c) {}

Turma::Turma(std::string c, list<StudentCard> s): code(c), students(s) {}

Turma::Turma(const Turma &t1) {
    this->code = t1.code;
    this->students = t1.students;
}

string Turma::getCode() {
    return this->code;
}

list<StudentCard> Turma::getStudents() {
    return students;
}

void Turma::addStudent(const StudentCard& student) {
    students.push_back(student);
}

void Turma::removeStudent(const StudentCard& student) {
    students.remove(student);
}

bool Turma::operator==(const Turma &t2) const {
    return this->code == t2.code;
}