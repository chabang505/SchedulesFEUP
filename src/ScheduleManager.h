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

using namespace std;

class ScheduleManager {
    set<Student> students;
    list<ClassStudents> classStudents;
    queue<Request> requests;
    vector<ClassSchedule> classes; //mudei pra vector, pra facilitar o sort


public:
    ScheduleManager();
    void readClassesFile(const string& file);
    void readClassesPerUC(const string& file);
    void readStudentsFile(const string& file);

    void receiveRequest(Request request);


    void orderByUCCode();
    void orderByName();

    // mais funcoes de ordenaçao

    // funcoes de consulta:
    // - recolha de todos os dados necessarios para uma lista temporaria
    // - ordenar essa lista de acordo com o criterio do utilizador

    string removeStudent(Request request);
    string addStudent(Request request);
    string changeStudentClass(Request request);
    string changeStudentClasses(Request request);




};


#endif //PROJ1_SCHEDULEMANAGER_H
