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
        cout << "1. Check Schedule information\n";
        cout << "2. Request changes to your Schedule\n";
        cout << "3. End the day (process all requests)\n";
        cout << "4. Quit\n";
        int n1;
        cin >> n1;

        switch (n1) {
            case 1:
                cout << "Choose the type of information you would like to see!\n";
                cout << "1. Check a students Schedule" << "\n";
                cout << "2. Check the UCss and Classes that a student is enrolled in" << "\n";
                cout << "3. Check the UCss a student is enrolled in" << "\n";
                cout << "4. Check the Classes a student is enrolled in" << "\n";
                cout << "5. Check the Students enrolled in a Class of a UC" << "\n";
                cout << "6. Check the Students enrolled in a UC" << "\n";
                cout << "7. Check the UCs by Year" << "\n";
                cout << "8. Check the Students enrolled in more than n UCS" << "\n";
                cout << "9. Check the number of Students enrolled in a UC" << "\n";
                cout << "10. Check the number of Students enrolled in a Class of a UC" << "\n";
                int n2;
                cin >> n2;
                switch (n2) {

                    case 1:
                        cout<<"Insert Student id(ex:202040617):";
                        int id1; cin>>id1;
                        ShowStudentSchedule(manager, id1);
                        break;
                    case 2:
                        cout<<"Insert Student id(ex:202040617):";
                        int id2; cin>>id2;
                        cout<<"Choose Sorting Method:\n";
                        cout<<"0.By UC Code\n";
                        cout<<"1.By Class Code\n";
                        int sort; cin>>sort;
                        showClassUCbyStudent(manager, id2, sort);
                        break;
                    case 3:
                        cout<<"Insert Student id(ex:202040617):";
                        int id3; cin>>id3;
                        showUCbyStudent(manager, id3);
                        break;
                    case 4:
                        cout<<"Insert Student id(ex:202040617):";
                        int id4; cin>>id4;
                        showClassbyStudent(manager, id4);
                        break;
                    case 5: {
                        cout << "Insert Class Code(ex:3LEIC07):";
                        string classid;
                        cin >> classid;
                        cout << "Insert UC Code(ex:L.EIC021):";
                        string ucid;
                        cin >> ucid;
                        cout << "Choose Sorting Method:\n";
                        cout << "0.By Student Name\n";
                        cout << "1.By Student Id\n";
                        int sort5;
                        cin >> sort5;
                        showStudentsInClass(manager, classid, ucid, sort5);
                        break;
                    }
                    case 6: {
                        cout << "Insert UC Code(ex:L.EIC021):";
                        string ucid;
                        cin >> ucid;
                        cout << "Choose Sorting Method:\n";
                        cout << "0.By Student Name\n";
                        cout << "1.By Student Id\n";
                        int sort6;
                        cin >> sort6;
                        showStudentsInUC(manager,  ucid, sort6);
                        break;
                    }
                    case 7: {
                        cout << "Insert Year Number(Ex:1):";
                        int year;
                        cin >> year;
                        showUCbyYear(manager,  year);
                        break;
                    }
                    case 8: {
                        cout << "Insert Num of UC's(Ex:2):";
                        int num;
                        cin >> num;
                        cout << "Choose Sorting Method:\n";
                        cout << "0.By Student Name\n";
                        cout << "1.By Student Id\n";
                        int sort8;
                        cin >> sort8;
                        showStudentsByNumUC(manager,  num, sort8);
                        break;
                    }
                    case 9: {
                        cout << "Insert UC Code(ex:L.EIC021):";
                        string ucid;
                        cin >> ucid;
                        showNumStudentsByUC(manager,  ucid, 0);
                        break;
                    }
                    case 10: {
                        cout << "Insert Class Code(ex:3LEIC07):";
                        string classid;
                        cin >> classid;
                        cout << "Insert UC Code(ex:L.EIC021):";
                        string ucid;
                        cin >> ucid;
                        showNumStudentsByClass(manager, classid, ucid, 0);
                        break;
                    }
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
                        receiveRequest(manager, request);
                        cout << "Request received. All requests are processed at the end of the day." << endl;
                        break;
                    }
                    case 2: {
                        cout << "Insert Student id(ex:202040617):";
                        int id2;
                        cin >> id2;
                        cout << "Insert UC code(ex:L.EIC011):";
                        string uc2;
                        cin >> uc2;
                        cout << "Insert Class Code(ex:1LEIC13):";
                        string c2;
                        cin >> c2;
                        ClassUC classuc2 = ClassUC(uc2, c2);
                        Request request2 = Request(2, id2, classuc2);
                        receiveRequest(manager, request2);
                        cout << "Request received. All requests are processed at the end of the day." << endl;
                        break;
                    }
                    case 3:{
                        cout << "Insert Student ID: ";
                        int id1;
                        cin >> id1;
                        cout << "Insert the 1st UC code(ex:L.EIC011):";
                        string uc1;
                        cin >> uc1;
                        cout << "Insert the 1st corresponding Class Code:";
                        string c1;
                        cin >> c1;
                        ClassUC classuc1 = ClassUC(uc1, c1);
                        list<ClassUC> l1;
                        l1.push_back(classuc1);
                        cout << "Insert the 2nd UC code (ex:L.EIC011): ";
                        string uc2;
                        cin >> uc2;
                        cout << "Insert the 1st corresponding Class Code(ex:1LEIC13):";
                        string c2;
                        cin >> c2;
                        ClassUC classuc2 = ClassUC(uc2, c2);
                        list<ClassUC> l2;
                        l2.push_back(classuc2);
                        Request request = Request(3, id1, l1, l2);
                        receiveRequest(manager, request);
                        cout << "Request received. All requests are processed at the end of the day." << endl;
                        break;
                    }
                    case 4:{
                        cout << "Insert Student Id:";
                        int id1;
                        cin >> id1;
                        cout<< "Insert number of classes you would like to change:";
                        int n; cin>>n;
                        list<ClassUC> l1;
                        list<ClassUC> l2;
                        for (size_t i = 0; i < n; n++) {
                            cout << "Insert the 1st UC code (e.g.: L.EIC011): ";
                            string uc1;
                            cin >> uc1;
                            cout << "Insert the 1st corresponding Class Code(ex:1LEIC13):";
                            string c1;
                            cin >> c1;
                            ClassUC classuc1 = ClassUC(uc1, c1);

                            l1.push_back(classuc1);
                            cout << "Insert the 2nd UC code(ex:L.EIC011):";
                            string uc2;
                            cin >> uc2;
                            cout << "Insert the 2nd corresponding Class Code(ex:1LEIC13):";
                            string c2;
                            cin >> c2;
                            ClassUC classuc2 = ClassUC(uc2, c2);

                            l2.push_back(classuc2);
                            }
                        Request request = Request(4, id1, l1, l2);
                        cout << "Request received. All requests are processed at the end of the day." << endl;
                        receiveRequest(manager, request);
                        }
                        break;
                }
                break;
            case 3: {
                queue<string> replies = processRequests(manager);
                while (!replies.empty()) {
                    cout << replies.front() << endl;
                    replies.pop();
                }
            }
                break;
            case 4:
                tf = false;
                cout << "You have successfully exited your Schedule Manager!";
                break;
        }
        if (n1 == 4) break;
        cout << "Would you like continue using the Schedule Manager?" << '\n';
        cout << "If you do insert y, if not insert n: ";
        char s; cin >> s;
        if (s == 'n' || s == 'N') {
            tf = false;
            cout << "You have successfully exited your Schedule Manager!";
        }
    }
}

void Menu::receiveRequest(ScheduleManager& manager, Request& request) {
    manager.receiveRequest(request);
}

queue<string> Menu::processRequests(ScheduleManager& manager) {
    queue<string> replies = manager.processRequests();
    while (!replies.empty()) {
        cout << replies.front() << endl;
        replies.pop();
    }
    return replies;
}


void Menu::showClassUCbyStudent (ScheduleManager& manager, int studentid, int sort){
    list<ClassUC> res= manager.listClassUCbyStudent(studentid, sort);
    cout << "========================================\n";

    cout << "UP" << studentid << " UC'S and Classes are: " << "\n";
    cout << "========================================\n";
 
    for (ClassUC x: res){
        cout<<" UC: "<<x.getCodeUC()<<" Class: "<<x.getCodeClass()<<"\n";
    }
    cout << "========================================\n";

}
void Menu::showUCbyStudent (ScheduleManager& manager, int studentid){
    int sort=0;
    list<ClassUC> l= manager.listClassUCbyStudent(studentid, sort);
    list<string> res;
    for(auto x: l){
        res.push_back(x.getCodeUC());
    }

    cout << "========================================\n";

    cout<<"UP"<<studentid<<" UCs are:"<<"\n";
    cout << "========================================\n";
    for(string s: res){
        cout << " -> " << s << '\n';
    }
    cout << "========================================\n";

}

void Menu::showClassbyStudent (ScheduleManager& manager, int studentid){
    int sort=1;
    list<ClassUC> l= manager.listClassUCbyStudent(studentid, sort);
    set<string> res;
    for(auto x: l){
        res.insert(x.getCodeClass());
    }
    cout << "========================================\n";

    cout<<"UP"<<studentid<<" Classes are:"<<"\n";
    cout << "========================================\n";
    for(string s: res){
        cout << " -> " << s << '\n';
    }
    cout << "========================================\n";

}

void Menu::ShowStudentSchedule (ScheduleManager& manager, int studentid) {
    list<ClassSchedule> l = manager.getStudentSchedule(studentid);
    cout << "========================================\n";

    cout<<"UP"<<studentid<<" School Schedule:"<<"\n";
    cout << "========================================\n";

    vector<string> wk = {"Monday", "Tuesday","Wednesday", "Thursday", "Friday", "Saturday" };
    for (ClassSchedule cs: l) {
        cout<<"     UC:"<<cs.getCodeUC()<<" Class:"<<cs.getCodeClass()<<"\n";
        for (Slot h: cs.getSlots()){
            cout<<"     "<<h.getType()<<"->"<<wk[h.getWeekDay()]<<": "<<h.getStart()<<"h"<<"-"<<h.getStart()+h.getDuration()<<"h"<<"\n";
        }
    }
    cout << "========================================\n";

}

void Menu::showStudentsInClass(ScheduleManager &manager, string classid, string ucid, int sort){
    list<StudentCard> l= manager.listStudentsInClass(classid, ucid, sort);
    cout << "=============================================================\n";
    cout<<"The list of Students enrolled in UC: "<<ucid<<", Class: "<<classid<<"\n";
    cout << "=============================================================\n";

    for (StudentCard s: l){
        cout<<"Student Name: "<<s.getName()<<"; Id: "<<s.getID()<<"\n";
    }
    cout << "=============================================================\n";
}
void Menu::showStudentsInUC(ScheduleManager &manager, string ucid, int sort){
    list<StudentCard> l= manager.listStudentsInUC(ucid, sort);
    cout << "=============================================================\n";
    cout<<"The list of Students enrolled in UC: "<<ucid<<"\n";
    cout << "=============================================================\n";

    for (StudentCard s: l){
        cout<<"Student Name: "<<s.getName()<<"; Id: "<<s.getID()<<"\n";
    }
    cout << "=============================================================\n";
}

void Menu::showUCbyYear(ScheduleManager &manager, int year){
    list<UC> ucs = manager.listUCbyYear(year);
    cout << "==================================\n";

    cout<<"Year "<<year<<" has the following UC's:"<<"\n";
    cout << "==================================\n";
    for (UC uc: ucs){
        cout<<"UC Code: "<<uc.getCode()<<"\n";
    }
    cout << "==================================\n";
}
void Menu::showStudentsByNumUC(ScheduleManager &manager, int numuc, int sort){
    list<Student> l= manager.listStudentsByNumUC( numuc, sort);
    cout << "======================================================================\n";
    cout<<"List of Students that are enrolled in more than "<<numuc<<" UC's:"<<"\n";
    cout << "======================================================================\n";
    for (Student s: l){
        cout<<"Student Name: "<<s.getName()<<"; Id: "<<s.getId()<<"\n";
    }
    cout << "======================================================================\n";
}

void Menu::showNumStudentsByUC(ScheduleManager &manager, string ucid, int sort){
    list<StudentCard> l= manager.listStudentsInUC(ucid, sort);
    cout << "=============================================================\n";
    cout<<"The Num of Students enrolled in UC "<<ucid<<": "<<l.size()<<"\n";
    cout << "=============================================================\n";
}
void Menu::showNumStudentsByClass(ScheduleManager &manager, string classid, string ucid, int sort){
    list<StudentCard> l= manager.listStudentsInClass(classid, ucid, sort);
    cout << "===================================================================\n";
    cout<<"The Num of Students enrolled in UC "<<ucid<<"-> Class "<<classid<<": "<<l.size()<<"\n";
    cout << "===================================================================\n";
}


}
