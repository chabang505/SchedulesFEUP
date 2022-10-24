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
    string removeStudent(ScheduleManager manager, Request request);
    string addStudent(ScheduleManager manager, Request request);
    string changeStudentClass(ScheduleManager manager, Request request);
    string changeStudentClasses(ScheduleManager manager, Request request);

};


#endif //PROJ1_MENU_H
