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
#include "Year.h"

using namespace std;

class ScheduleManager {
    set<Student> students;
    queue<Request> requests;
    vector<ClassSchedule> classSchedules;
    set<ClassUC> classUCs;
    list<Year> years;

public:
    /**
     * Creates a new ScheduleManager object
     */
    ScheduleManager();

    /**
     * Checks if the schedule of a class already exists in the system
     * @param codeClass Code of the class
     * @param codeUC Code of the UC
     * @return Index of the ClassSchedule object in the system, if it exists, -1 otherwise
     */
    int classScheduleExists(const string& codeClass, const string& codeUC);

    /**
     * Finds what year a certain class belongs to
     * @param codeClass Code of the class
     * @return Integer corresponding to the year of the class
     */
    int findYear(const string& codeClass);

    /**
     * Initializes the list of UCs by year
     */
    void generateYears();

    /**
     * Enters the information from a certain class and UC into the list of UCs by year
     * @param codeUC Code of the UC
     * @param codeClass Code of the class
     */
    void fillYearsList(const string& codeUC, const string& codeClass);

    /**
     * Places a student in all the classes he is enrolled in at the start of the system
     * @param id ID of the student
     * @param name Name of the student
     * @param classes List of ClassUCs corresponding to the students information
     */
    void placeStudentInYears(int id, const string& name, const list<ClassUC> & classes);

    /**
     * Removes the student from the list of Years on the system
     * @param studentID ID of the student
     * @param classUC Class where the student is to be removed from
     */
    void removeStudentFromYears(int studentID, const ClassUC& classUC);

    /**
    * Finds a student in the internal Student BST
    * @param id ID of the student
    * @return Iterator to the student if found, end() iterator otherwise
    */
    set<Student>::iterator findStudent(int id);

    /**
     * Finds a ClassUC in the internal ClassUC BST
     * @param codeUC Code of the UC
     * @param codeClass Code of the class
     * @return Iterator to the ClassUC if it exists, end() iterator otherwise
     */
    set<ClassUC>::iterator findClassUC(const string& codeUC, const string& codeClass);

    /**
     * Increments the number of students in a ClassUC by one
     * @param codeUC Code of the UC
     * @param codeClass Code of the class
     */
    void addOneToClass(const string& codeUC, const string& codeClass);

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

    void orderByUCCode();
    void orderByName();

    // mais funcoes de ordenaçao

    // funcoes de consulta:
    // - recolha de todos os dados necessarios para uma lista temporaria
    // - ordenar essa lista de acordo com o criterio do utilizador

    /**
     * Receives the request and places it on a queue, to guarantee they are ordered and handled by time of arrival
     * @param request The request to be handled in the system
     */
    void receiveRequest(Request& request);

    /**
     * Processes the requests currently in the system
     */
    void processRequests();

    /**
     * Treats the request according to its type
     * @param request Request to be directed
     */
    void directRequest(const Request& request);

    /**
     * Removes a student from a class or UC
     * @param request Reference to a request containing the information needed
     * @return A string that reflects the success of the operation
     */
    string removeStudent(const Request& request);

    /**
     * Adds a student to a class or UC
     * @param request Reference to a request containing the information needed
     * @return A string that reflects the success of the operation
     */
    string addStudent(const Request& request);

    /**
     * Performs a switch in a student's schedule, either between UCs or between classes
     * @param request Reference to a request containing the information needed
     * @return A string that reflects the success of the operation
     */
    string changeStudentClass(const Request& request);

    /**
     * Performs multiple changes in a student's schedule, either between UCs or between classes
     * @param request Reference to a request containing the information needed
     * @return A string that reflects the success of the operation
     */
    string changeStudentClasses(const Request& request);

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
