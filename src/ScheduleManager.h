//
// Created by Joao Ribeiro on 19/10/2022.
//

#ifndef PROJ1_SCHEDULEMANAGER_H
#define PROJ1_SCHEDULEMANAGER_H

#include <queue>
#include <set>

#include "Request.h"
#include "Student.h"
#include "ClassSchedule.h"
#include "ClassStudents.h"
#include "Year.h"

using namespace std;

class ScheduleManager {
    set<Student> students;
    vector<ClassStudents> classStudents;
    queue<Request> requests;
    vector<ClassSchedule> classSchedules;
    set<ClassUC> classUCs;

public:
    /**
     * Creates a new ScheduleManager object
     */
    ScheduleManager();

    int classScheduleExists(const string& codeClass, const string& codeUC);

    /**
     * Reads the CSV file containing information on the classes
     * @param file Name of the file to be read
     */
    void readClassesFile(const string& file);

    /**
     * Reads the CSV file containing information on the classes for each UC
     * @param file Name of the file to be read
     */
    void readClassesPerUC(const string& fname);

    /**
     * Reads the CSV file containing information on the students
     * @param file
     */
    void readStudentsFile(const string& fname);

    /**
     * Checks if a certain class and UC are already in a ClassStudents vector
     * @param classes Vector of ClassStudents objects
     * @param codeUC String with the code of the UC
     * @param codeClass String with the code of the class
     * @return Index of the element, if found, -1 otherwise
     */
    int hasClass(vector<ClassStudents> classes, string& codeUC, string& codeClass);

    /**
     * Reads students CSV file to create vector of ClassStudents
     * @param fname Name of the file to be read
     */
    void createClassStudents(const string& fname);


    void orderByUCCode();
    void orderByName();

    // mais funcoes de ordenaçao

    // funcoes de consulta:
    // - recolha de todos os dados necessarios para uma lista temporaria
    // - ordenar essa lista de acordo com o criterio do utilizador

    void receiveRequest(Request& request);

    /**
     * Removes a student from a class or UC
     * @param request Reference to a request containing the information needed
     * @return A string that reflects the success of the operation
     */
    string removeStudent(Request& request);

    /**
     * Adds a student to a class or UC
     * @param request Reference to a request containing the information needed
     * @return A string that reflects the success of the operation
     */
    string addStudent(Request& request);

    /**
     * Performs a switch in a student's schedule, either between UCs or between classes
     * @param request Reference to a request containing the information needed
     * @return A string that reflects the success of the operation
     */
    string changeStudentClass(Request& request);

    /**
     * Performs multiple changes in a student's schedule, either between UCs or between classes
     * @param request Reference to a request containing the information needed
     * @return A string that reflects the success of the operation
     */
    string changeStudentClasses(Request& request);

    /**
     * Creates a list of the ClassUC's of the classes that the given Student object is enrolled in
     * @param student Reference to the student we want to obtain information about
     * @return a list of the ClassUC's
     */

    list<ClassUC> listClassUCbyStudent(Student &student);

    /**
     * Creates a list of the ClassSchedules of the ClassUc's that the given Student object is enrolled in
     * @param student Reference to the student we want to obtain information about
     * @return a list of the ClassSchedule's
     */
    list<ClassSchedule> getStudentSchedule(Student &student);
};


#endif //PROJ1_SCHEDULEMANAGER_H
