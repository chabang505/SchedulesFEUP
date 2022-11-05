//
// Created by Joao Ribeiro on 19/10/2022.
//

#include <iostream>

#include "src/ScheduleManager.h"
#include "src/Menu.h"

using namespace std;

int main(int argc, char* argv[]) {
    ScheduleManager manager = ScheduleManager();
    manager.generateYears();
    manager.readClassesPerUC("CSV/classes_per_uc.csv");
    manager.readStudentsFile("CSV/students_classes.csv");
    manager.readClassesFile("CSV/classes.csv");
    list<ClassUC> classes;
    ClassUC c1 = ClassUC("L.EIC001", "1LEIC02");
    classes.push_back(c1);
    Request request = Request(1, 202025487, classes);
    manager.receiveRequest(request);
    manager.processRequests();
}