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

using namespace std;

class ScheduleManager {
    set<Student> students;
    queue<Request> requests;
    vector<ClassSchedule> classSchedules; //mudei pra vector, pra facilitar o sort
    set<ClassUC> classUCs;


public:
    /**
     * Creates a new ScheduleManager object
     */
    ScheduleManager();

    /**
     * Reads the CSV file containing information on the classes
     * @param file Name of the file to be read
     */
    void readClassesFile(const string& file);

    /**
     * Reads the CSV file containing information on the classes for each UC
     * @param file Name of the file to be read
     */
    void readClassesPerUC(string file);

    /**
     * Reads the CSV file containing information on the students
     * @param file
     */
    void readStudentsFile(const string& file);


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

};


#endif //PROJ1_SCHEDULEMANAGER_H
