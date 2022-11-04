//
// Created by johny on 20/10/2022.
//

#include "Menu.h"
#include <iostream>
using namespace std;

Menu::Menu() {
    show();

}
void Menu::show(){
    cout << "=================================\n";
    cout << "Welcome to your Schedule Manager!\n";
    cout << "=================================\n\n";
    string name;
    cout << "Insert your name: ";
    cin >> name;
    bool tf=true;
    while(tf) {
        cout << "\nHello, " << name << "!\nWhat would do you like to do today?\n";
        cout << "1.Check Schedule information\n";
        cout << "2.Request changes to your Schedule\n";
        cout << "3.Quit\n";
        int n1;
        cin >> n1;
        switch (n1) {
            case 1:
                cout << "1.Check a students Schedule" << "\n";
                cout << "2.Check the UC's and Classes that a student is enrolled in" << "\n";
                cout << "3.Check the UC's a student is enrolled in" << "\n";
                cout << "4.Check the Classes and UC's that a student is enrolled in" << "\n";
                int n2;
                cin >> n2;
                switch (n2) {
                    case 1:
                        break;
                    case 2:
                        break;
                    case 3:
                        break;
                    case 4:
                        break;
                }
                break;
            case 2:
                cout << "1.Removes a student from a UC or class" << "\n";
                cout << "2.Add a student from a UC or class" << "\n";
                cout << "3.Change Students Class" << "\n";
                cout << "4.Change Students Classes" << "\n";
                int n3;
                cin >> n3;
                switch (n3) {
                    case 1:
                        break;
                    case 2:
                        break;
                    case 3:
                        break;
                    case 4:
                        break;
                }
                break;
            case 3:
                tf=false;
                cout << "You have successfully exited your Schedule Manager!";
                break;
        }
        cout<<"Would you like to exit the Schedule Manager?"<<"\n";
        cout<<"If you do insert y, if not insert any letter: ";
        char s; cin>>s;
        if (s=='y' || s=='Y') tf=false;
    }
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

void Menu::showClassUCbyStudent (ScheduleManager& manager, Student& s){
    list<ClassUC> res= manager.listClassUCbyStudent(s);
    cout<<s.getName()<<":"<<"\n";
    for (ClassUC x: res){
        cout<<"UC:"<<x.getCodeUC()<<" Class:"<<x.getCodeClass()<<"\n";
    }
}
void Menu::showUCbyStudent (ScheduleManager& manager, Student& s){
    list<ClassUC> l= manager.listClassUCbyStudent(s);
    list<string> res;
    for(auto x: l){
        res.push_back(x.getCodeUC());
    }
    cout<<s.getName()<<":"<<"\n";
    for(string s: res){
        cout<<s<<"\n";
    }
}

void Menu::showClassbyStudent (ScheduleManager& manager, Student& s){
    list<ClassUC> l= manager.listClassUCbyStudent(s);
    list<string> res;
    for(auto x: l){
        res.push_back(x.getCodeClass());
    }
    cout<<s.getName()<<":"<<"\n";
    for(string s: res){
        cout<<s<<"\n";
    }
}

void Menu::ShowStudentSchedule (ScheduleManager& manager, Student& s){
    list<ClassSchedule> l = manager.getStudentSchedule(s);
    for (ClassSchedule cs: l) {
        cout<<"UC:"<<cs.getCodeUC()<<" Turma:"<<cs.getCodeClass()<<"\n";
        for (Slot h: cs.getSlots()){
            cout<<h.getType()<<"->"<<h.getWeekDay()<<": "<<h.getStart()<<"-"<<h.getDuration()<<"\n";
        }
    }

}