//
// Created by Joao Ribeiro on 19/10/2022.
//

#ifndef PROJ1_CLASSSCHEDULE_H
#define PROJ1_CLASSSCHEDULE_H

#include <string>
#include <list>

#include "Slot.h"

using namespace std;

/**
 *  Represents a class from a certain UC, containing its corresponding Slots in the schedule
 */
class ClassSchedule {
    string codeUC;
    string codeClass;
    list<Slot> slots;

public:

    /**
     * Creates a new ClassSchedule object
     * @param cuc The internal code of the UC
     * @param cc The internal code of the class
     * @param s A list of the slots belonging to the class
     */
    ClassSchedule(string cuc, string cc, list<Slot> & s);

    /**
     * Creates a new ClassSchedule object
     * @param cs1 A reference to an existing ClassSchedule object
     */
    ClassSchedule(const ClassSchedule& cs1);

    /**
     * Returns the code of the UC
     * @return The code of the UC
     */
    string getCodeUC() const;

    /**
     * Assigns a new UC code to this ClassSchedule
     * @param newCodeUC The new UC code to assign
     */
    void setCodeUC(string newCodeUC);

    /**
     * Returns the code of the class
     * @return The code of the class
     */
    string getCodeClass() const;

    /**
     * Assigns a new class code to this ClassSchedule
     * @param newCodeClass The new class code to assign
     */
    void setCodeClass(string newCodeClass);

    /**
     * Returns the list of slots belonging to the class
     * @return The list of slots belonging to the class
     */
    list<Slot> getSlots() const;

    /**
     * Assigns a new list of slots to this ClassSchedule
     * @param newSlots The new list of slots to assign
     */
    void setSlots(const list<Slot> &newSlots);

    /**
     * Adds a new slot to the internal list of slots
     * @param s1 The new slot to add to the list
     */
    void addSlot(Slot& s1);

    /**
     * Returns the number of slots of this ClassSchedule
     * @return The number of slots of this ClassSchedule
     */
    int numOfSlots() const;

};


#endif //PROJ1_CLASSSCHEDULE_H
