//
// Created by Joao Ribeiro on 19/10/2022.
//

#include "ScheduleManager.h"
#include <iostream>
#include <fstream>
#include <string>

ScheduleManager::ScheduleManager() = default;


void ScheduleManager::readClassesFile(const string& file){
    ifstream in(fname);
    for (string line; getline(in, line)){

    }
}


void ScheduleManager::readClassesPerUC(const string& file){
    ifstream in(fname);
    for (string line; getline(in, line)) {

    }
}

void ScheduleManager::readStudentsFile(const string& file){
    ifstream in(fname);
    for (string line; getline(in, line)) {

    }
}

void ScheduleManager::receiveRequest(Request request) {
    this->requests.push(request);
}

string ScheduleManager::removeStudent(Request request) {
    // find the student
    // remove his entry in classes of the requested class/UC
}

string ScheduleManager::addStudent(Request request) {
    // find the student
    // check for constraints of class capacity and schedule conflicts
    // if possible add student to class
}

string ScheduleManager::changeStudentClass(Request request) {
    // find the student
    // check for constraints of class capacity and schedule conflicts
    // if possible make change requested
}

string ScheduleManager::changeStudentClasses(Request request) {
    // find the student
    // while there are changes he requested:
        // check for constraints of class capacity and schedule conflicts
        // if possible make change requested
}
