//
// Created by johny on 19/10/2022.
//

#include "Time.h"

Time::Time(): hour(0), minute(0) {}
Time::Time(int h, int m): hour(h), minute(m) {}
Time::Time(const Time& t1) {
    this->hour = t1.hour;
    this->minute = t1.minute;
}

int Time::getHour() { return this->hour; }

void Time::setHour(int newHour) { this->hour = newHour; }

int Time::getMinute() { return this->minute; }

void Time::setMinute(int newMinute) { this->minute = newMinute; }

bool Time::operator==(const Time &t2) const {
    return (this->hour == t2.hour && this->minute == t2.minute);
}

string Time::write() const {
    stringstream oss;
    oss << hour << ":" << minute;
    return oss.str();
}