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

    /**
     * Creates a new Turma object
     * @param c String containing code of the Turma
     */
    explicit Turma(string c);

    /**
     * Creates a new Turma object
     * @param c String containing code of the Turma
     * @param s List of StudentCards belonging to the Turma
     */
    Turma(string c, list<StudentCard> & s);

    /**
     * Creates a new Turma object
     * @param t1 Reference to an existing Turma object
     */
    Turma(const Turma& t1);

    /**
     * Returns the code of this Turma object
     * @return Code of this Turma object
     */
    string getCode() const;

    /**
     * Returns the list of StudentCards on this Turma object
     * @return List of StudentCards on this Turma object
     */
    list<StudentCard> getStudents() const;

    /**
     * Adds a StudentCard to the Turma
     * @param student Reference to the StudentCard to be added
     */
    void addStudent(const StudentCard& student);

    /**
     * Removes a StudentCard from the Turma
     * @param student Reference to the StudentCard to be removed
     */
    void removeStudent(const StudentCard& student);

    /**
     * Equality operator between Turma objects
     * @param t2 Reference to another Turma object
     * @return True if the Turmas are equal, false otherwise
     */
    bool operator==(const Turma& t2) const;
};


#endif //PROJ1_TURMA_H
