//
// Created by Joao Ribeiro on 18/10/2022.
//

#ifndef PROJ1_CLASSUC_H
#define PROJ1_CLASSUC_H

#include <string>
#include <sstream>
using namespace std;

/**
 * Represents a class from a certain UC
 */
class ClassUC {

    string codeUC;
    string codeClass;
    int numStudents;
    int const static cap = 30; // max number of students in a class

public:
    /**
     * Creates a new ClassUC object
     * @param cUC The internal UC code
     * @param cc The internal class code
     */
    ClassUC(string cUC, string cc);

    /**
     * Creates a new ClassUC object
     * @param c1 A reference to an existing ClassUC object
     */
    ClassUC(const ClassUC& c1);

    /**
     * Returns the UC code for this ClassUC
     * @return The UC code for this ClassUC
     */
    string getCodeUC();

    /**
     * Assigns a new UC code to the ClassUC object
     * @param newCodeUC The new UC code to assign
     */
    void setCodeUC(string newCodeUC);

    /**
     * Returns the class code for this ClassUC
     * @return The class code for this ClassUC
     */
    string getCodeClass();

    /**
     * Assigns a new class code to the ClassUC object
     * @param newCodeClass The new class code to assign
     */
    void setCodeClass(string newCodeClass);

    /**
     * Evaluates the equality between this ClassUC and another ClassUC object
     * @param c2 Reference to the ClassUC object to be compared
     * @return True if the objects are equal, false if they are different
     */
    bool operator==(const ClassUC& c2) const;

    /**
     * Transforms the object into a printable string
     * @return The object in the form of a printable string
     */
    string write() const;

    /**
     * Returns the number of students currently on this class
     * @return The number of students currently on this class
     */
    int getNumStudents();


};


#endif //PROJ1_CLASSUC_H
