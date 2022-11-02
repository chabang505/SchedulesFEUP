//
// Created by johny on 20/10/2022.
//

#include "Menu.h"

Menu::Menu() = default;

string Menu::removeStudent(ScheduleManager& manager, Request& request) {
    string reply = manager.removeStudent(request);
    return reply;
}

string Menu::addStudent(ScheduleManager& manager, Request& request) {
    string reply = manager.addStudent(request);
    return reply;
}

string Menu::changeStudentClass(ScheduleManager& manager, Request& request) {
    string reply = manager.changeStudentClass(request);
    return reply;
}

string Menu::changeStudentClasses(ScheduleManager& manager, Request& request) {
    string reply = manager.changeStudentClasses(request);
    return reply;
}
