//
// Created by johny on 20/10/2022.
//

#include "Menu.h"
#include <iostream>
using namespace std;

Menu::Menu() {
    manager.generateYears();
    manager.readClassesPerUC("CSV/classes_per_uc.csv");
    manager.readStudentsFile("CSV/students_classes.csv");
    manager.readClassesFile("CSV/classes.csv");
    show();

}

void Menu::show(){
    cout << "=================================\n";
    cout << "Welcome to your Schedule Manager!\n";
    cout << "=================================\n\n";
    string name;
    cout << "Insert your name:\t";
    cin >> name;
    bool tf = true;
    while(tf) {
        cout << "\nHello, " << name << "!\nWhat would do you like to do today?\n";
        cout << "1.Check Schedule information\n";
        cout << "2.Request changes to your Schedule\n";
        cout << "3.Quit\n";
        int n1;
        cin >> n1;
        switch (n1) {
            case 1:
                cout << "1.Check a student's Schedule" << "\n";
                cout << "2.Check the UCs and Classes that a student is enrolled in" << "\n";
                cout << "3.Check the UCs a student is enrolled in" << "\n";
                cout << "4.Check the Classes a student is enrolled in" << "\n";
                int n2;
                cin >> n2;
                switch (n2) {

                    case 1:
                        cout << "Insert Student id (e.g.: 202009987): ";
                        int id1; cin >> id1;
                        ShowStudentSchedule(manager, id1);
                        break;
                    case 2:
                        cout << "Insert Student id (e.g.: 202009987): ";
                        int id2; cin >> id2;
                        cout << "Choose Sorting Method:\n";
                        cout << "0.By UC Code\n";
                        cout << "1.By Class Code\n";
                        int sort; cin >> sort;
                        showClassUCbyStudent(manager, id2, sort);
                        break;
                    case 3:
                        cout << "Insert Student ID (e.g.: 202009987): ";
                        int id3; cin >> id3;
                        showUCbyStudent(manager, id3);
                        break;
                    case 4:
                        cout << "Insert Student ID (e.g.: 202009987): ";
                        int id4; cin >> id4;
                        showClassbyStudent(manager, id4);
                        break;
                }
                break;
            case 2:
                cout << "1.Removes a student from a UC or class" << "\n";
                cout << "2.Add a student to a UC or class" << "\n";
                cout << "3.Change a Student's Class" << "\n";
                cout << "4.Change Student's multiple Classes" << "\n";
                int n3;
                cin >> n3;
                switch (n3) {
                    case 1: {
                        cout << "Insert Student ID (e.g.: 202009987): ";
                        int id1;
                        cin >> id1;
                        cout << "Insert UC code (e.g.: L.EIC011): ";
                        string uc1;
                        cin >> uc1;
                        cout << "Insert Class Code (e.g.: 1LEIC13): ";
                        string c1;
                        cin >> c1;
                        ClassUC classuc = ClassUC(uc1, c1);
                        Request request = Request(1, id1, classuc);
                        addStudent(manager, request);
                        break;
                    }
                    case 2: {
                        cout << "Insert Student id(ex:202009987): ";
                        int id2;
                        cin >> id2;
                        cout << "Insert UC code(ex:L.EIC011): ";
                        string uc2;
                        cin >> uc2;
                        cout << "Insert Class Code(ex:1LEIC13): ";
                        string c2;
                        cin >> c2;
                        ClassUC classuc2 = ClassUC(uc2, c2);
                        Request request2 = Request(2, id2, classuc2);
                        removeStudent(manager, request2);
                        break;
                    }
                    case 3:{
                        cout << "Insert Student ID: ";
                        int id1;
                        cin >> id1;
                        cout << "Insert the 1st UC code(ex:L.EIC011): ";
                        string uc1;
                        cin >> uc1;
                        cout << "Insert the 1st corresponding Class Code: ";
                        string c1;
                        cin >> c1;
                        ClassUC classuc1 = ClassUC(uc1, c1);
                        list<ClassUC> l1;
                        l1.push_back(classuc1);
                        cout << "Insert the 2nd UC code (ex:L.EIC011): ";
                        string uc2;
                        cin >> uc2;
                        cout << "Insert the 1st corresponding Class Code(ex:1LEIC13): ";
                        string c2;
                        cin >> c2;
                        ClassUC classuc2 = ClassUC(uc2, c2);
                        list<ClassUC> l2;
                        l2.push_back(classuc2);
                        Request request = Request(3, id1, l1, l2);
                        changeStudentClass(manager, request);
                        break;
                    }
                    case 4:{
                        cout << "Insert Student Id: ";
                        int id1;
                        cin >> id1;
                        cout<< "Insert number of classes you would like to change: ";
                        int n; cin>>n;
                        list<ClassUC> l1;
                        list<ClassUC> l2;
                        for (size_t i = 0; i < n; n++) {
                            cout << "Insert the 1st UC code(ex:L.EIC011): ";
                            string uc1;
                            cin >> uc1;
                            cout << "Insert the 1st corresponding Class Code(ex:1LEIC13): ";
                            string c1;
                            cin >> c1;
                            ClassUC classuc1 = ClassUC(uc1, c1);

                            l1.push_back(classuc1);
                            cout << "Insert the 2nd UC code(ex:L.EIC011): ";
                            string uc2;
                            cin >> uc2;
                            cout << "Insert the 2nd corresponding Class Code(ex:1LEIC13): ";
                            string c2;
                            cin >> c2;
                            ClassUC classuc2 = ClassUC(uc2, c2);

                            l2.push_back(classuc2);
                            }
                        Request request = Request(4, id1, l1, l2);
                        changeStudentClasses(manager, request);
                        }
                        break;
                }
                break;
            case 3:
                tf = false;
                cout << "You have successfully exited your Schedule Manager!";
                break;
        }
        if (n1 == 3) break;
        cout << "Would you like continue using the Schedule Manager?" << '\n';
        cout << "If you do insert y, if not insert n: ";
        char s; cin >> s;
        if (s == 'n' || s == 'N') {
            tf = false;
            cout << "You have successfully exited your Schedule Manager!";
        }
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

void Menu::showClassUCbyStudent (ScheduleManager& manager, int studentid, int sort){
    list<ClassUC> res= manager.listClassUCbyStudent(studentid, sort);
    cout<<"UP"<<studentid<<" UCs and Classes are:"<<"\n";
    for (ClassUC x: res){
        cout<<" UC: "<<x.getCodeUC()<<" Class: "<<x.getCodeClass()<<"\n";
    }
}
void Menu::showUCbyStudent (ScheduleManager& manager, int studentid){
    int sort=0;
    list<ClassUC> l= manager.listClassUCbyStudent(studentid, sort);
    list<string> res;
    for(auto x: l){
        res.push_back(x.getCodeUC());
    }
    cout<<"UP"<<studentid<<" UCs are:"<<"\n";
    for(string s: res){
        cout << " -> " << s << '\n';
    }
}

void Menu::showClassbyStudent (ScheduleManager& manager, int studentid){
    int sort=1;
    list<ClassUC> l= manager.listClassUCbyStudent(studentid, sort);
    set<string> res;
    for(auto x: l){
        res.insert(x.getCodeClass());
    }
    cout << "UP" << studentid << " Classes are:" << '\n';
    for(string s: res){
        cout << " -> " << s << '\n';
    }
}

void Menu::ShowStudentSchedule (ScheduleManager& manager, int studentid) {
    list<ClassSchedule> l = manager.getStudentSchedule(studentid);
    cout << "UP" << studentid << " School Schedule:" << '\n';
    for (ClassSchedule cs: l) {
        cout << "UC: " << cs.getCodeUC() << " Class:" << cs.getCodeClass() << '\n';
        for (Slot h: cs.getSlots()){
            cout << h.getType() << "->" << h.getWeekDay() << ": " << h.getStart() << "-" << h.getDuration() << '\n';
        }
    }
}