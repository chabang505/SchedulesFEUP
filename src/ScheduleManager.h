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
    list<ClassSchedule> classes;

public:
    void readClassesFile(File file);
    void readClassesPerUC(File file);
    void readStudentsFile(File file);

    void receiveRequest(Request request);

    void orderByUCCode();
    void orderByName();
    // mais funcoes de ordenaçao

    // funcoes de consulta:
    // - recolha de todos os dados necessarios para uma lista temporaria
    // - ordenar essa lista de acordo com o criterio do utilizador



};


#endif //PROJ1_SCHEDULEMANAGER_H
