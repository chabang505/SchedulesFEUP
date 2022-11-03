//
// Created by Joao Ribeiro on 19/10/2022.
//

#include "src/ScheduleManager.h"
#include "src/Menu.h"

int main(int argc, char* argv[]) {
    Menu m();
    ScheduleManager manager = ScheduleManager();
    manager.createClassStudents("students_classes.csv");
}