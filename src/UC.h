//
// Created by Joao Ribeiro on 02/11/2022.
//

#ifndef PROJ1_UC_H
#define PROJ1_UC_H

#include <string>
#include <list>

#include "Turma.h"

using namespace std;

class UC {
    string code;
    list<Turma> turmas;

public:
    UC(string c, list<Turma> t);
    UC(const UC& uc1);
    string getCode();
    list<Turma> getTurmas();
    void addTurma(const Turma& turma);
    void removeTurma(const Turma& turma);
    bool operator==(const UC& uc2) const;
};


#endif //PROJ1_UC_H
