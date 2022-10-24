//
// Created by Joao Ribeiro on 19/10/2022.
//

#include "src/ScheduleManager.h"

int main(int argc, char* argv[]) {
    ScheduleManager manager = ScheduleManager();
    manager.readClassesPerUC("classes_per_uc.csv");
}
