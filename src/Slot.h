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
    float duration;
    string type;

public:
    /**
     * Creates a new Slot object
     * @param wd The day of the week
     * @param s The start time of the slot, as a float
     * @param d The duration of the slot, as a float
     * @param t The type of the slot
     */
    Slot(int wd, float s, float d, string t);

    /**
     * Creates a new Slot object
     * @param s1 Reference to an existing Slot object
     */
    Slot(const Slot& s1);

    /**
     * Returns the weekday of the Slot
     * @return The weekday of the Slot
     */
    int getWeekDay() const;

    /**
     * Assigns a new weekday to the Slot object
     * @param newWeekDay The new weekday to assign
     */
    void setWeekDay(int newWeekDay);

    /**
     * Returns the start time of the Slot
     * @return The start time of the Slot
     */
    float getStart() const;

    /**
     * Assigns a new start hour to the Slot object
     * @param newStart New start hour to be assigned
     */
    void setStart(float newStart);

    /**
     * Returns the duration of the slot
     * @return Duration of the slot
     */
    float getDuration() const;

    /**
     * Assigns a new duration to the Slot object
     * @param newDuration New duration to be assigned
     */
    void setDuration(float newDuration);

    /**
     * Returns the type of the Slot object
     * @return Type of the Slot object
     */
    string getType() const;

    /**
     * Assigns a new type to the Slot object
     * @param newType New type to be assigned
     */
    void setType(const string& newType);

    /**
     * Equality operator for Slot objects
     * @param s2 Reference to another Slot object
     * @return True if Slot objects are equal, false otherwise
     */
    bool operator==(const Slot& s2) const;

    /**
     * Converts Slot object into string to display it in the terminal
     * @return Slot object as a string
     */
    string write() const;

};

#endif //PROJ1_SLOT_H
