//
// Created by Joao Ribeiro on 02/11/2022.
//

#ifndef PROJ1_CLASSSTUDENTS_H
#define PROJ1_CLASSSTUDENTS_H

#include <string>
#include <list>
#include <vector>

using namespace std;

class ClassStudents {
    string codeUC;
    string codeClass;
    vector<int> students;

public:
    ClassStudents(string cuc, string cc, vector<int> students);
    ClassStudents(const ClassStudents& c1);
    string getCodeUC();
    void setCodeUC(const string newCodeUC);
    string getCodeClass();
    void setCodeClass(const string newCodeClass);
    void addStudent(int student);
};


#endif //PROJ1_CLASSSTUDENTS_H
