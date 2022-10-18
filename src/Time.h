//
// Created by johny on 19/10/2022.
//

#ifndef PROJ1_TIME_H
#define PROJ1_TIME_H

#include <string>
#include <sstream>

class Time {

    int const hour;
    int const minute;

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
