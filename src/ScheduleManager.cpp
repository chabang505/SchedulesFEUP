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
    ifstream in(fname); //opens the file
    for (string line; getline(in, line);){


    }
}


void ScheduleManager::readClassesPerUC(const string& fname){
    //the string fname is the name of the file
    ifstream in(fname); //opens the file
    for (string line; getline(in, line);){


    }
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

list<string> ScheduleManager::getUCCodeByYear(int year) {
    list<string> listuc;
    if(year<=0 || year>3){
        return listuc; //empty list or print a statement saying not valid input
    }
    for (ClassSchedule x: classes) {
        if (x.getCodeClass()[0]==year){
            listuc.push_back(x.getCodeUC());

        }
    }
    listuc.sort();
    listuc.unique();
    return listuc;

}
int ScheduleManager::getNumStudentsByYear(int year) {
    int num=0; //numstudents;
   for(Student s: students){
       int cont=0;
       auto l=s.getClasses();
       for(ClassUC c: l){
           if ((c.getCodeUC())[0]==year){
               cont++;
           }
       }
       if(cont>0) num++;
   }
   return num;
}

