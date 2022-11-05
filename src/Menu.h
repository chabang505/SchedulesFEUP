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
/*
    void consultaMenu() {
        recebePedido;
        listPronta = enviaPedidoParaScheduleManager;
        display(listPronta);
    }

- apresentar mensagem inicial
- apresentar opçoes iniciais:
  1. consulta
  2. fazer pedido
  3. sair

  Menu 1.
  1. listar alunos de uma turma ou UC - metodo_X()
  2.
  3.
  4.
  ...

  Codigo UC Codigo Turma
  Slot (dia da semana, hora de inicio, duracao, tipo)
  Slot

 Dia da semana
 Cod UC Cod turma
 hora, duracao, tipo


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

    void showStudentsInClass(ScheduleManager &manager, string classid, string ucid);

    void show();
};


#endif //PROJ1_MENU_H
