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
    cout << "All files have been read" << endl;
    /*
    list<ClassUC> classes;
    ClassUC c1 = ClassUC("L.EIC005", "1LEIC03");
    ClassUC c2 = ClassUC("L.EIC003", "1LEIC04");
    classes.push_back(c1);
    classes.push_back(c2);
    Student s = Student(20201345, "Abilio", classes);
    s.removeClassUC(c2);

    Request request = Request(0, 202025487, classes);
    manager.receiveRequest(request);
    manager.processRequests();*/
}