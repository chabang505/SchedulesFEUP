//
// Created by Joao Ribeiro on 19/10/2022.
//

#include <iostream>

#include "src/ScheduleManager.h"
#include "src/Menu.h"

using namespace std;

int main(int argc, char* argv[]) {
    Menu m();
    ScheduleManager manager = ScheduleManager();
    manager.generateYears();
    manager.readClassesPerUC("classes_per_uc.csv");
    manager.readStudentsFile("students_classes.csv");
}

