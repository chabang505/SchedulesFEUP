//
// Created by johny on 20/10/2022.
//

#ifndef PROJ1_MENU_H
#define PROJ1_MENU_H

#include "ScheduleManager.h"


class Menu {
    ScheduleManager manager = ScheduleManager();

public:
/*
    void consultaMenu() {
        recebePedido;
        listPronta = enviaPedidoParaScheduleManager;
        display(listPronta);
    }
*/
    // student request methods
    /**
     * Removes a student from a UC or class
     * @param manager Reference to a ScheduleManager object that will perform the operation
     * @param request Reference to a Request object that contains the student's request
     * @return A string that reflects the success of the operation
     */
    string removeStudent(ScheduleManager& manager, Request& request);

    /**
     * Adds a student to a UC or class
     * @param manager Reference to a ScheduleManager object that will perform the operation
     * @param request Reference to a Request object that contains the student's request
     * @return A string that reflects the success of the operation
     */
    string addStudent(ScheduleManager& manager, Request& request);

    /**
     * Performs a switch in a student's schedule, either between UCs or between classes
     * @param manager Reference to a ScheduleManager object that will perform the operation
     * @param request Reference to a Request object that contains the student's request
     * @return A string that reflects the success of the operation
     */
    string changeStudentClass(ScheduleManager& manager, Request& request);

    /**
     * Performs multiple switches in a student's schedule, either between UCs or between classes
     * @param manager Reference to a ScheduleManager object that will perform the operation
     * @param request Reference to a Request object that contains the student's request
     * @return A string that reflects the success of the operation
     */
    string changeStudentClasses(ScheduleManager& manager, Request& request);

};


#endif //PROJ1_MENU_H
