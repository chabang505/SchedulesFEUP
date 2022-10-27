//
// Created by Joao Ribeiro on 19/10/2022.
//

#include "ScheduleManager.h"
#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>

ScheduleManager::ScheduleManager() = default;

void ScheduleManager::readClassesFile(const string& fname){
    //the string fname is the name of the file
    ifstream in(fname, ios::in); //opens the file
    string line;
    getline(in, line);
    while (line != "") {
        getline(in, line);
        stringstream s(line);
    }
}

void ScheduleManager::readClassesPerUC(const string fname){
    //the string fname is the name of the file
    vector<string> row;
    string line, word;
    ifstream file(fname);
    if (file.is_open()) {
        while (getline(file, line)) {
            row.clear();
            stringstream str(line);
            while (getline(str, word, ',')) {
                row.push_back(word);
            }
        }
    }
    else
        cout << "Could not open the file" << endl;
}

void ScheduleManager::readStudentsFile(const string& fname){
    //the string fname is the name of the file
    ifstream in(fname); //opens the file
    for (string line; getline(in, line);){


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
bool sortUCCode(ClassSchedule a, ClassSchedule b) {
    return(a.getCodeUC()<b.getCodeUC());
}

void ScheduleManager::orderByUCCode(){
    sort(classes.begin(), classes.end(), sortUCCode);
}

bool sortName(Student a, Student b) {
    return(a.getName()<b.getName());
}

void ScheduleManager::orderByName(){
    vector<Student> stemp;
    for (Student s: students){
        stemp.push_back(s);
    }
    sort(stemp.begin(), stemp.end(), sortName);
}
