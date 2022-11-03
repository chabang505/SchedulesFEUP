//
// Created by Joao Ribeiro on 02/11/2022.
//

#ifndef PROJ1_CLASSSTUDENTS_H
#define PROJ1_CLASSSTUDENTS_H

#include <string>
#include <list>
#include <vector>

using namespace std;

class ClassStudents {
    string codeUC;
    string codeClass;
    vector<int> students;

public:
    /**
     * Creates a new ClassStudents object
     * @param cuc Code of the UC
     * @param cc Code of the class
     * @param students Vector of students attending the class+UC
     */
    ClassStudents(string  cuc, string  cc, const vector<int> & students);

    /**
     * Creates a new ClassStudents object
     * @param c1 Reference to an existing ClassStudents object
     */
    ClassStudents(const ClassStudents& c1);

    /**
     * Returns the code of the UC of the ClassStudents object
     * @return Code of the UC of the ClassStudents object
     */
    string getCodeUC();

    /**
     * Assigns a new UC code to the ClassStudents object
     * @param newCodeUC UC code to be assigned to the object
     */
    void setCodeUC(const string& newCodeUC);

    /**
     * Returns the code of the class of the ClassStudents object
     * @return Code of the class of the ClassStudents object
     */
    string getCodeClass();

    /**
     * Assigns a new class code to the ClassStudents object
     * @param newCodeClass Class code to be assigned to the object
     */
    void setCodeClass(const string& newCodeClass);

    /**
     * Adds a student ID to the ClassStudents object
     * @param student Student ID to be added
     */
    void addStudent(int student);
};


#endif //PROJ1_CLASSSTUDENTS_H
