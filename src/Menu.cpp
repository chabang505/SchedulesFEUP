//
// Created by johny on 20/10/2022.
//

#include "Menu.h"
#include <iostream>
using namespace std;

Menu::Menu() {
    cout<<"=================================\n";
    cout<<"Welcome to your Schedule Manager!\n";
    cout<<"=================================\n\n";
    string name;
    cout<<"Insert your name: "; cin>>name;
    cout<<"\nHello,"<<name<<"What would do you like to do today?\n";
    cout<<"1.Check Schedule information\n";
    cout<<"2.Request changes to your Schedule\n";
    cout<<"3.Quit\n";
    int n;
    cin>>n;



}

string Menu::removeStudent(ScheduleManager& manager, Request& request) {
    string reply = manager.removeStudent(request);
    return reply;
}

string Menu::addStudent(ScheduleManager& manager, Request& request) {
    string reply = manager.addStudent(request);
    return reply;
}

string Menu::changeStudentClass(ScheduleManager& manager, Request& request) {
    string reply = manager.changeStudentClass(request);
    return reply;
}

string Menu::changeStudentClasses(ScheduleManager& manager, Request& request) {
    string reply = manager.changeStudentClasses(request);
    return reply;
}
