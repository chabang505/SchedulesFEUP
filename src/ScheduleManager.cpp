//
// Created by Joao Ribeiro on 19/10/2022.
//

#include "ScheduleManager.h"
#include <iostream>
#include <fstream>
#include <string>

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
    string line;
    ifstream file(fname);
    getline(file, line);
    if (file.is_open()) {
        string codeUC;
        string codeClass;
        while (getline(file, line)) {
            stringstream inputString(line);
            getline(inputString, codeUC, ',');
            getline(inputString, codeClass, ',');
            ClassUC c1 = *new ClassUC(codeUC, codeClass);
            classUCs.insert(c1);
        }
    }
    else
        cout << "Could not open the file" << endl;
}

void ScheduleManager::readStudentsFile(const string& fname){
    //the string fname is the name of the file
    string line;
    ifstream file(fname);
    getline(file, line);
    if (file.is_open()) {
        string name;
        string temp_string;
        int current_id = 0;
        int previous_id = current_id;
        string codeUC;
        string codeClass;
        list<ClassUC> classes;
        classes.clear();
        while (getline(file, line)) {
            stringstream inputString(line);
            getline(inputString, temp_string, ',');
            current_id = stoi(temp_string);
            if (previous_id == 0) {
                getline(inputString, name, ',');
            } else if (previous_id == current_id) {
                getline(inputString, temp_string, ',');
            } else if (previous_id != current_id) {
                Student s1 = *new Student(previous_id, name, classes);
                students.insert(s1);
                classes.clear();
                getline(inputString, name, ',');
            }
            previous_id = current_id;
            getline(inputString, codeUC, ',');
            getline(inputString, codeClass, ',');
            ClassUC c1 = *new ClassUC(codeUC, codeClass);
            classes.push_back(c1);
        }
    } else {
        cout << "Could not open the file" << endl;
    }
}

void ScheduleManager::receiveRequest(Request& request) {
    this->requests.push(request);
}

string ScheduleManager::removeStudent(Request& request) {
    // find the student
    // remove his entry in classes of the requested class/UC
}

string ScheduleManager::addStudent(Request& request) {
    // find the student
    // check for constraints of class capacity and schedule conflicts
    // if possible add student to class
}

string ScheduleManager::changeStudentClass(Request& request) {
    // find the student
    // check for constraints of class capacity and schedule conflicts
    // if possible make change requested
}

string ScheduleManager::changeStudentClasses(Request& request) {
    // find the student
    // while there are changes he requested:
        // check for constraints of class capacity and schedule conflicts
        // if possible make change requested

}
/*
bool ScheduleManager::sortUCCode(ClassSchedule a, ClassSchedule b) {
    return(a.getCodeUC()<b.getCodeUC());
}

void ScheduleManager::orderByUCCode(){
    sort(classSchedules.begin(), classSchedules.end(), sortUCCode);
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
*/