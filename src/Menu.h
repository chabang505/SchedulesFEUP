//
// Created by johny on 20/10/2022.
//

#ifndef PROJ1_MENU_H
#define PROJ1_MENU_H

#include "ScheduleManager.h"


class Menu {
    ScheduleManager manager= ScheduleManager();

public:
    /**
     * Default constructor for a Menu object
     */
    Menu();


    // student request methods
    /**
     * Receives a request from the user and passes it to the Schedule Manager
     * @param manager The system's Schedule Manager
     * @param request The request to be fulfilled
     */
    void receiveRequest(ScheduleManager& manager, Request& request);

    /**
     * Processes the requests currently in the system
     * @param manager The system's Schedule Manager
     * @return Queue containing the result of each request
     */
    queue<string> processRequests(ScheduleManager& manager);

    /**
     * Prints the ClassUCS that the student s is enrolled in
     * @param manager Reference to a ScheduleManager object that will perform the operation
     * @param studentid Id of the student we obtained information about
     */

    void showClassUCbyStudent (ScheduleManager& manager, int studentid, int sort);
    /**
     * Prints the uc codes of the classes student s is enrolled in
     * @param manager Reference to a ScheduleManager object that will perform the operation
     * @param s Reference to the Student object we want to obtain the information about
     */
    void showUCbyStudent(ScheduleManager &manager, int studentid);

    /**
     * Prints the class codes of the classes student s is enrolled in
     * @param manager Reference to a ScheduleManager object that will perform the operation
     * @param studentid Id of the student we obtained information about
     */
    void showClassbyStudent(ScheduleManager &manager, int studentid);

    /**
     * Prints the class and uc codes of the classes student s is enrolled in, along with the respective slots
     * @param manager Reference to a ScheduleManager object that will perform the operation
     * @param studentid Id of the student we obtained information about
     */

    void ShowStudentSchedule(ScheduleManager &manager, int studentid);

    /**
     *
     */
    void show();
};


#endif //PROJ1_MENU_H
