//
// Created by Joao Ribeiro on 19/10/2022.
//

#ifndef PROJ1_STUDENT_H
#define PROJ1_STUDENT_H

#include <string>
#include <list>

#include "ClassUC.h"

using namespace std;

/**
 * Represents a student in the system
 */
class Student {
    string name;
    int id;
    list<ClassUC> classes;

public:
    /**
     * Creates a new Student object
     * @param n Name of the student
     * @param id Internal ID of the student
     * @param c List of CLassUC the student is enrolled in
     */
    Student(string n, int id, list<ClassUC> c);

    /**
     * Creates a new Student object
     * @param s Reference to an existing Student object
     */
    Student(const Student& s);

    /**
     * Returns the name of the student
     * @return The name of the student
     */
    string getName();

    /**
     * Assigns a new name to the Student
     * @param newName The new name to assign
     */
    void setName(string newName);

    /**
     * Returns the internal ID of the student
     * @return The internal ID of the student
     */
    int getId();

    /**
     * Assigns a new internal ID to the student
     * @param newId The new internal ID to assign
     */
    void setId(int newId);

    /**
     * Returns a list of the ClassUCs the student is enrolled in
     * @return List of the ClassUCs the student is enrolled in
     */
    list<ClassUC> getClasses();
};


#endif //PROJ1_STUDENT_H
