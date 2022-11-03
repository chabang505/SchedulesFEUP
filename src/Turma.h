//
// Created by Joao Ribeiro on 02/11/2022.
//

#ifndef PROJ1_TURMA_H
#define PROJ1_TURMA_H

#include <string>
#include <list>

#include "StudentCard.h"

using namespace std;

class Turma {
    string code;
    list<StudentCard> students;

public:
    Turma(string c, list<StudentCard> s);
    Turma(const Turma& t1);
    string getCode();
    list<StudentCard> getStudents();
    void addStudent(const StudentCard& student);
    void removeStudent(const StudentCard& student);
    bool operator==(const Turma& t2) const;
};


#endif //PROJ1_TURMA_H
