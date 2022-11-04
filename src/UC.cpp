//
// Created by Joao Ribeiro on 02/11/2022.
//

#include "UC.h"

UC::UC(string c): code(std::move(c)) {}

UC::UC(string c, list<Turma> & t): code(std::move(c)), turmas(t) {}

UC::UC(const UC& uc1) {
    this->code = uc1.code;
    this->turmas = uc1.turmas;
}

string UC::getCode() const {
    return this->code;
}

list<Turma> UC::getTurmas() const{
    return this->turmas;
}

list<Turma>::iterator UC::findTurma(const string &codeClass) {
    for (auto it = this->turmas.begin(); it != this->turmas.end(); it++) {
        if ((*it).getCode() == codeClass)
            return it;
    }
    return this->turmas.end();
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