//
// Created by Joao Ribeiro on 18/10/2022.
//

#ifndef PROJ1_SLOT_H
#define PROJ1_SLOT_H

#include <string>
#include <sstream>

using namespace std;

class Slot {

    int weekDay;
    float start;
    float end;
    string type;

public:
    Slot(int wd, float s, float e, string t);
    Slot(const Slot& s1);
    int getWeekDay();
    void setWeekDay(int newWeekDay);
    float getStart();
    void setStart(float newStart);
    float getEnd();
    void setEnd(float newEnd);
    string getType();
    void setType(string newType);
    bool operator==(const Slot& s2) const;
    string write() const;

};

#endif //PROJ1_SLOT_H
