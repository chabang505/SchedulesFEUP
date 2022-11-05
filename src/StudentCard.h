//
// Created by Joao Ribeiro on 02/11/2022.
//

#ifndef PROJ1_STUDENTCARD_H
#define PROJ1_STUDENTCARD_H

#include <string>

using namespace std;

class StudentCard {
    int id;
    string name;

public:

    /**
     * Creates a new StudentCard object
     * @param id ID of the student
     * @param n Name of the student
     */
    StudentCard(int id, string n);

    /**
     * Creates a new StudentCard object
     * @param id ID of the student
     */
    explicit StudentCard(int id);

    /**
     * Creates a new StudentCard object
     * @param s1 Reference to an existing StudentCard object
     */
    StudentCard(const StudentCard& s1);

    /**
     * Returns the ID of the StudentCard object
     * @return ID of the StudentCard object
     */
    int getID() const;

    /**
     * Assigns a new ID to the StudentCard object
     * @param newID New ID to be assigned
     */
    void setID(int newID);

    /**
     * Returns the name of the StudentCard object
     * @return Name of the StudentCard object
     */
    string getName() const;

    /**
     * Assigns a new name to the StudentCard object
     * @param newName New name to be assigned
     */
    void setName(const string& newName);

    /**
     * Equality operator for StudentCards objects
     * @param c2 Reference to another StudentCard object
     * @return True if objects are equal, false otherwise
     */
    bool operator==(const StudentCard& c2) const;
};


#endif //PROJ1_STUDENTCARD_H
