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

    //information display methods
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
     *Prints the list of Students enrolled in a given Class(Turma) of a UC
     * @param manager Reference to a ScheduleManager object that will perform the operation
     * @param classid String representing Code of the Class(Turma), we want to find the information about
     * @param ucid String representing Code of the UC, we want to find the information about
     * @param sort Integer representing sort method
     */

    void showStudentsInClass(ScheduleManager &manager, string classid, string ucid, int sort);
    /**
     * Prints the list of Students enrolled in a given UC
     * @param manager Reference to a ScheduleManager object that will perform the operation
     * @param ucid String representing Code of the UC, we want to find the information about
     * @param sort Integer representing sort method
     */

    void showStudentsInUC(ScheduleManager &manager, string ucid, int sort);
    /**
     * Prints the list of UC's of a given Year
     * @param manager Reference to a ScheduleManager object that will perform the operation
     * @param year Integer representing the Year we want to find the information about
     * @param sort Integer representing sort method

     */

    void showUCbyYear(ScheduleManager &manager, int year, int sort);
    /**
     * Prints the list of Students enrolled in more than a certain number of UC's
     * @param manager Reference to a ScheduleManager object that will perform the operation
     * @param numuc Integer representing the number of uc's
     * @param sort Integer representing sort method
     */

    void showStudentsByNumUC(ScheduleManager &manager, int numuc, int sort);

    /**
     * Converts an int representing a day of the week into a presentable string
     * @param weekDay Day to be converted
     * @return String corresponding to the day of the week
     */
    string intToWD(int weekDay);

   /**
    * Prints Instructions to the user
    */
    void show();
    /**
     * Prints the Number of Students in a given UC
     * @param manager Reference to a ScheduleManager object that will perform the operation
     * @param ucid String representing Code of The UC, we want to find the information about
     * @param sort Integer representing sort method
     */
    void showNumStudentsByUC(ScheduleManager &manager, string ucid, int sort);
    /**
     *Prints the Number of Students in a given Class of a UC
     * @param manager Reference to a ScheduleManager object that will perform the operation
     * @param classid String representing Code of the Class(Turma), we want to find the information about
     * @param ucid String representing Code of the UC, we want to find the information about
     * @param sort Integer representing sort method
     */

    void showNumStudentsByClass(ScheduleManager &manager, string classid, string ucid, int sort);
};


#endif //PROJ1_MENU_H
