//
// Created by Joao Ribeiro on 19/10/2022.
//

#ifndef PROJ1_SCHEDULEMANAGER_H
#define PROJ1_SCHEDULEMANAGER_H

#include <queue>
#include <set>

#include "Request.h"
#include "Student.h"

using namespace std;

class ScheduleManager {
    set<Student> students;
    queue<Request> requests;

};


#endif //PROJ1_SCHEDULEMANAGER_H
