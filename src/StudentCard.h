//
// Created by Joao Ribeiro on 02/11/2022.
//

#ifndef PROJ1_STUDENTCARD_H
#define PROJ1_STUDENTCARD_H

#include <string>

using namespace std;

class StudentCard {
    int id;
    string name;

public:
    StudentCard(int id, string n);
    StudentCard(const StudentCard& s1);
    int getID();
    void setID(int newID);
    string getName();
    void setName(string newName);
    bool operator==(const StudentCard& c2) const;
};


#endif //PROJ1_STUDENTCARD_H
