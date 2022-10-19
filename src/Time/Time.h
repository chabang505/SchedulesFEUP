//
// Created by Joao Ribeiro on 19/10/2022.
//

#ifndef PROJ1_TIME_H
#define PROJ1_TIME_H

#include <string>
#include <sstream>
using namespace std;

class Time {

    int hour;
    int minute;

public:
    Time();
    Time(int h, int m);
    Time(const Time& t1);
    int getHour();
    void setHour(int newHour);
    int getMinute();
    void setMinute(int newMinute);
    bool operator==(const Time& t2) const;
    string write() const;

};


#endif //PROJ1_TIME_H
