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
    /**
     * Creates a new UC object
     * @param c String with the code of the object
     */
    explicit UC(string c);

    /**
     * Creates a new UC object
     * @param c String with the code of the object
     * @param t List of Turmas belonging to that UC
     */
    UC(string c, list<Turma> t);

    /**
     * Creates a new UC object
     * @param uc1 Reference to an existing UC object
     */
    UC(const UC& uc1);

    /**
     * Returns the code for the UC object
     * @return Code for the UC object
     */
    string getCode();

    /**
     * Returns the list of Turmas on this UC object
     * @return List of Turmas on this UC object
     */
    list<Turma> getTurmas();

    /**
     * Gives an iterator to a Turma within the UC object
     * @param codeClass String containing the code of the Turma to find
     * @return Iterator to the required Turma, if exists, end() iterator otherwise
     */
    list<Turma>::iterator findTurma(const string& codeClass);

    /**
     * Adds a Turma to the UC object
     * @param turma Reference to the Turma to be added
     */
    void addTurma(const Turma& turma);

    /**
     * Removes a Turma from the UC object
     * @param turma Reference to the Turma to be removed
     */
    void removeTurma(const Turma& turma);

    /**
     * Equality operator between two UC objects
     * @param uc2 Reference to another UC object
     * @return True if objects are equal, false otherwise
     */
    bool operator==(const UC& uc2) const;
};


#endif //PROJ1_UC_H
