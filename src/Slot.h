//
// Created by Joao Ribeiro on 18/10/2022.
//

#ifndef PROJ1_SLOT_H
#define PROJ1_SLOT_H

#include <string>
#include <sstream>

#include "Time/Time.h"

using namespace std;

class Slot {

    int weekDay;
    Time start;
    Time end;
    string type;

public:
    Slot(int wd, Time& s, Time& e, string t);
    Slot(const Slot& s1);
    int getWeekDay();
    void setWeekDay(int newWeekDay);
    Time getStart();
    void setStart(const Time& newStart);
    Time getEnd();
    void setEnd(const Time& newEnd);
    string getType();
    void setType(string newType);
    bool operator==(const Slot& s2) const;
    string write() const;

};

#endif //PROJ1_SLOT_H
