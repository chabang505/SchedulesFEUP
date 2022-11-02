//
// Created by Joao Ribeiro on 02/11/2022.
//

#include "UC.h"

UC::UC(std::string c, list<Turma> t): code(c), turmas(t) {}

UC::UC(const UC &uc1) {
    this->code = uc1.code;
    this->turmas = uc1.turmas;
}

string UC::getCode() {
    return this->code;
}

list<Turma> UC::getTurmas() {
    return this->turmas;
}

void UC::addTurma(const Turma &turma) {
    this->turmas.push_back(turma);
}

void UC::removeTurma(const Turma &turma) {
    this->turmas.remove(turma);
}

bool UC::operator==(const UC &uc2) const {
    return this->code == uc2.code;
}