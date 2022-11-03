//
// Created by Joao Ribeiro on 19/10/2022.
//

#include "ScheduleManager.h"
#include <iostream>
#include <fstream>
#include <string>

ScheduleManager::ScheduleManager() = default;

void ScheduleManager::readClassesFile(const string& fname){
    
}

void ScheduleManager::readClassesPerUC(const string& fname){
    string line;
    ifstream file(fname);
    if (file.is_open()) {
        getline(file, line);
        string codeUC, codeClass;
        while (getline(file, line)) {
            stringstream inputString(line);
            getline(inputString, codeUC, ',');
            getline(inputString, codeClass, ',');
            ClassUC c1 = ClassUC(codeUC, codeClass);
            classUCs.insert(c1);
        }
    } else
        cout << "Could not open the file" << endl;
}

void ScheduleManager::readStudentsFile(const string& fname){
    string line;
    ifstream file(fname);
    if (file.is_open()) {
        getline(file, line);
        string name, temp_string, codeUC, codeClass;
        int current_id = 0;
        int previous_id = current_id;
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
                Student s1 = Student(previous_id, name, classes);
                students.insert(s1);
                classes.clear();
                getline(inputString, name, ',');
            }
            previous_id = current_id;
            getline(inputString, codeUC, ',');
            getline(inputString, codeClass, ',');
            ClassUC c1 = ClassUC(codeUC, codeClass);
            classes.push_back(c1);
        }
    } else {
        cout << "Could not open the file" << endl;
    }
}

int hasClass(vector<ClassStudents> classes, string& codeUC, string& codeClass) {
    int index = 0;
    for (auto & classe : classes) {
        if (classe.getCodeUC() == codeUC && classe.getCodeClass() == codeClass )
            return index;
        else {
            index++;
            continue;
        }
    }
    return -1;
}

void ScheduleManager::createClassStudents(const string& fname) {
    string line;
    ifstream file(fname);
    getline(file, line);
    if (file.is_open()) {
        string temp_string;
        int id;
        string codeUC;
        string codeClass;
        vector<int> students;
        while (getline(file, line)) {
            stringstream inputString(line);
            getline(inputString, temp_string, ',');
            id = stoi(temp_string);
            getline(inputString, temp_string, ',');
            getline(inputString, codeUC, ',');
            getline(inputString, codeClass, ',');
            int index = hasClass(classStudents, codeUC, codeClass);
            if (index != -1) {
                classStudents[index].addStudent(id);
            } else {
                students.push_back(id);
                ClassStudents c1 = ClassStudents(codeUC, codeClass, students);
                classStudents.push_back(c1);
            }
        }
    } else
        cout << "Could not open the file" << endl;
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

list<ClassUC> ScheduleManager::listClassUCbyStudent(Student &student) {
    list<ClassUC> l1=student.getClasses();
    return l1;

}

list<ClassSchedule> ScheduleManager::getStudentSchedule(Student &student) {
    list<ClassUC> l = student.getClasses();
    list<ClassSchedule> res;
    for (ClassUC uc: l) {
        for (ClassSchedule cs: classSchedules) {
            if (uc.getCodeClass()==cs.getCodeClass() && uc.getCodeUC()==cs.getCodeUC()) res.push_back(cs);
        }
    }
    return res;
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