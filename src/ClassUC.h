//
// Created by Joao Ribeiro on 18/10/2022.
//

#ifndef PROJ1_CLASSUC_H
#define PROJ1_CLASSUC_H

#include <string>
#include <sstream>
#include <iomanip>
using namespace std;

/**
 * Represents a class from a certain UC
 */
class ClassUC {

    string codeUC;
    string codeClass;
    int numStudents;
    int const static cap = 20; // max number of students in a class

public:
    /**
     * Creates a new ClassUC object
     * @param cUC The internal UC code
     * @param cc The internal class code
     */
    ClassUC(string cUC, string cc);

    /**
     * Creates a new ClassUC object, generating the codeClass automatically
     * @param cUC The internal UC code
     */
    explicit ClassUC(string cUC);

    /**
     * Creates a new ClassUC object
     * @param c1 A reference to an existing ClassUC object
     */
    ClassUC(const ClassUC& c1);

    /**
     * Returns the UC code for this ClassUC
     * @return The UC code for this ClassUC
     */
    string getCodeUC() const;

    /**
     * Assigns a new UC code to the ClassUC object
     * @param newCodeUC The new UC code to assign
     */
    void setCodeUC(string newCodeUC);

    /**
     * Returns the class code for this ClassUC
     * @return The class code for this ClassUC
     */
    string getCodeClass() const;

    /**
     * Assigns a new class code to the ClassUC object
     * @param newCodeClass The new class code to assign
     */
    void setCodeClass(string newCodeClass);

    /**
     * Transforms the object into a printable string
     * @return The object in the form of a printable string
     */
    string write() const;

    /**
     * Returns the number of students currently on this class
     * @return The number of students currently on this class
     */
    int getNumStudents() const;

    /**
     * Evaluates the equality between this ClassUC and another ClassUC object
     * @param c2 Reference to the ClassUC object to be compared
     * @return True if the objects are equal, false if they are different
     */
    bool operator==(const ClassUC& c2) const;

    /**
     * Less operator for ClassUC objects
     * @param c2 Reference to another ClassUC object
     * @return True if this ClassUC is less than the one compared, false otherwise
     */
    bool operator <(const ClassUC& c2) const;

    /**
     * Increments the number of students attending the ClassUC, returning a new ClassUC object
     * @return ClassUC object with number of students incremented by one
     */
    ClassUC operator ++(int);

    /**
     * Decrements the number of students attending the ClassUC, returning a new ClassUC object
     * @return ClassUC object with number of students incremented by one
     */
    ClassUC operator --(int);

    /**
     * Checks if a ClassUC has the capacity to receive one more student
     * @return True if it can receive one more student, false otherwise
     */
    bool hasCapacity() const;

    /**
     * Returns the next UC in the sequence
     * @return Next UC in the sequence
     */
    ClassUC nextUC();

};


#endif //PROJ1_CLASSUC_H
