//
// Created by Joao Ribeiro on 18/10/2022.
//

#include "Slot.h"

Slot::Slot(int wd, Time& s, Time& e, string t): weekDay(wd), start(s), end(e), type(t) {}

Slot::Slot(const Slot& s1) {
    this->weekDay = s1.weekDay;
    this->start = s1.start;
    this->end = s1.end;
    this->type = s1.type;
}

int Slot::getWeekDay() { return this->weekDay; }

void Slot::setWeekDay(int newWeekDay) { this->weekDay = newWeekDay; }

Time Slot::getStart() { return this->start; }

void Slot::setStart(const Time &newStart) { this->start = newStart; }

Time Slot::getEnd() { return this->end; }

void Slot::setEnd(const Time &newEnd) { this->end = newEnd; }

string Slot::getType() { return this->type; }

void Slot::setType(string newType) { this->type = newType; }

bool Slot::operator==(const Slot &s2) const {
    return (this->weekDay == s2.weekDay &&
            this->start == s2.start &&
            this->end == s2.end &&
            this->type == s2.type);
}

string Slot::write() const {
    stringstream oss;
    string dayOfTheWeek = "";
    switch (weekDay) {
        case 1:
            dayOfTheWeek = "Sun";
            break;
        case 2:
            dayOfTheWeek = "Mon";
            break;
        case 3:
            dayOfTheWeek = "Tue";
            break;
        case 4:
            dayOfTheWeek = "Wed";
            break;
        case 5:
            dayOfTheWeek = "Thu";
            break;
        case 6:
            dayOfTheWeek = "Fri";
            break;
        case 7:
            dayOfTheWeek = "Sat";
            break;
    }
    oss << dayOfTheWeek << "\n" << start.write() << "\n" << end.write() << "\n" << type;
    return oss.str();
}