//
// Created by johny on 02/11/2022.
//

#ifndef PROJ1_CLASSSTUDENTS_H
#define PROJ1_CLASSSTUDENTS_H

#include <string>
#include <list>

using namespace std;

class ClassStudents {
    string codeUC;
    string codeClass;
    list<int> students;

public:
    string getCodeUC();
    void setCodeUC(const string newCodeUC);
    string getCodeClass();
    void setCodeClass(const string newCodeClass);
    void addStudent(int student);
};


#endif //PROJ1_CLASSSTUDENTS_H
