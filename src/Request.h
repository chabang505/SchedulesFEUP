//
// Created by Joao Ribeiro on 19/10/2022.
//

#ifndef PROJ1_REQUEST_H
#define PROJ1_REQUEST_H

#include <string>
#include <list>

#include "ClassUC.h"

using namespace std;

class Request {
    string type;
    string student;
    list<ClassUC> currentClasses;
    list<ClassUC> requestedClasses;

public:
    // tipos de pedidos:
    // remover aluno de turma/UC
    // adicionar aluno a turma/UC
    // alterar turma/UC de aluno
    // alterar várias turmas/UC de aluno


};


#endif //PROJ1_REQUEST_H
