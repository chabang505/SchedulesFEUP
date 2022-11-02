//
// Created by Joao Ribeiro on 18/10/2022.
//

#ifndef PROJ1_SLOT_H
#define PROJ1_SLOT_H

#include <string>
#include <sstream>

using namespace std;

/**
 * Represents a Slot in the schedule
 */
class Slot {

    int weekDay;
    float start;
    float end;
    string type;

public:
    /**
     * Creates a new Slot object
     * @param wd The day of the week
     * @param s The start time of the slot, as a float
     * @param e The end time of the slot, as a float
     * @param t The type of the slot
     */
    Slot(int wd, float s, float e, string t);

    /**
     * Creates a new Slot object
     * @param s1 Reference to an existing Slot object
     */
    Slot(const Slot& s1);

    /**
     * Returns the weekday of the Slot
     * @return The weekday of the Slot
     */
    int getWeekDay();

    /**
     * Assigns a new weekday to the Slot object
     * @param newWeekDay The new weekday to assign
     */
    void setWeekDay(int newWeekDay);

    /**
     * Returns the start time of the Slot
     * @return The start time of the Slot
     */
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
