//
// Created by Joao Ribeiro on 19/10/2022.
//

#include "ScheduleManager.h"
#include <iostream>
#include <fstream>
#include <string>

ScheduleManager::ScheduleManager() = default;

int wdtoi(const string& weekDay) {
    vector<string> wds{"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};
    for (int i = 0; i < wds.size(); i++) {
        if (weekDay == wds[i]) {
            return i;
        }
    }
}

int ScheduleManager::classScheduleExists(const string &codeClass, const string &codeUC) {
    int index = 0;
    for (ClassSchedule c: ScheduleManager::classSchedules) {
        if (c.getCodeClass() == codeClass && c.getCodeUC() == codeUC)
            return index;
        index++;
    }
    return -1;
}

int ScheduleManager::findYear(const string& codeClass) {
    int year = codeClass[0] - '0';
    return year;
}

void ScheduleManager::generateYears() {
    Year y1 = Year(1);
    Year y2 = Year(2);
    Year y3 = Year(3);
    years.push_back(y1);
    years.push_back(y2);
    years.push_back(y3);
}


void ScheduleManager::fillYearsList(const string& codeUC, const string& codeClass) {
    int yearNumber = findYear(codeClass);
    for (auto & year : years) {
        if (year.getNumber() == yearNumber) {
            auto it = year.findUC(codeUC);
            if (it != year.end()){
                Turma t1 = Turma(codeClass);
                it->addTurma(t1);
            } else {
                Turma t1 = Turma(codeClass);
                UC uc1 = UC(codeUC);
                uc1.addTurma(t1);
                year.addUC(uc1);
            }
        }
    }
}

void ScheduleManager::placeStudentInYears(int id, const string& name, const list<ClassUC> & classes) {
    StudentCard student = StudentCard(id, name);
    for (ClassUC classUC: classes) {
        int yearNumber = findYear(classUC.getCodeClass());
        for (auto & year: years) {
            if (year.getNumber() == yearNumber) {
               auto uc = year.findUC(classUC.getCodeUC());
               auto turma = uc->findTurma(classUC.getCodeClass());
               turma->addStudent(student);
            }
        }
    }
}

void ScheduleManager::removeStudentFromYears(int studentID, const ClassUC& classUC) {
    StudentCard student = StudentCard(studentID);
    int yearNumber = findYear(classUC.getCodeClass());
    for (auto & year: years) {
        if (year.getNumber() == yearNumber) {
            auto uc = year.findUC(classUC.getCodeUC());
            auto turma = uc->findTurma(classUC.getCodeClass());
            turma->removeStudent(student);
        }
    }
}

void ScheduleManager::readClassesFile(const string& fname){
    string line;
    ifstream file(fname);
    if (file.is_open()) {
        getline(file, line);
        string codeClass, codeUC, previousClass, previousUC, type, temp_string;
        int weekDay;
        float startHour, duration;
        list<Slot> slots;
        while (getline(file, line)) {
            stringstream inputString(line);
            getline(inputString, codeClass, ',');
            getline(inputString, codeUC, ',');
            getline(inputString, temp_string, ',');
            weekDay = wdtoi(temp_string);
            getline(inputString, temp_string, ',');
            startHour = stof(temp_string);
            getline(inputString, temp_string, ',');
            duration = stof(temp_string);
            getline(inputString, type, ',');
            Slot slot = Slot(weekDay, startHour, duration, type);
            int index = classScheduleExists(codeClass, codeUC);
            if (index != -1) {
                classSchedules[index].addSlot(slot);
            } else {
                slots.push_back(slot);
                ClassSchedule cs = ClassSchedule(codeUC, codeClass, slots);
                slots.clear();
                classSchedules.push_back(cs);
            }
        }
    } else
        cout << "Could not open the file" << endl;
}

void ScheduleManager::readClassesPerUC(const string& fname){
    string line;
    ifstream file(fname);
    if (file.is_open()) {
        getline(file, line);
        string codeUC, codeClass;
        while (getline(file, line)) {
            stringstream inputString(line);
            getline(inputString, codeUC, ',');
            getline(inputString, codeClass, ',');
            ClassUC c1 = ClassUC(codeUC, codeClass);
            classUCs.insert(c1);
            fillYearsList(codeUC, codeClass);
        }
    } else
        cout << "Could not open the file" << endl;
}

void ScheduleManager::readStudentsFile(const string& fname){
    string line;
    ifstream file(fname);
    if (file.is_open()) {
        getline(file, line);
        string name, temp_string, codeUC, codeClass;
        int current_id = 0;
        int previous_id = current_id;
        list<ClassUC> classes;
        classes.clear();
        while (getline(file, line)) {
            stringstream inputString(line);
            getline(inputString, temp_string, ',');
            current_id = stoi(temp_string);
            if (previous_id == 0) {
                getline(inputString, name, ',');
            } else if (previous_id == current_id) {
                getline(inputString, temp_string, ',');
            } else if (previous_id != current_id) {
                Student s1 = Student(previous_id, name, classes);
                students.insert(s1);
                placeStudentInYears(previous_id, name, classes);
                classes.clear();
                getline(inputString, name, ',');
            }
            previous_id = current_id;
            getline(inputString, codeUC, ',');
            getline(inputString, codeClass, ',');
            ClassUC c1 = ClassUC(codeUC, codeClass);
            classes.push_back(c1);
        }
    } else {
        cout << "Could not open the file" << endl;
    }
}

int ScheduleManager::hasClass(vector<ClassStudents> classes, const string& codeUC, const string& codeClass) {
    int index = 0;
    for (auto & classe : classes) {
        if (classe.getCodeUC() == codeUC && classe.getCodeClass() == codeClass )
            return index;
        else {
            index++;
            continue;
        }
    }
    return -1;
}

void ScheduleManager::createClassStudents(const string& fname) {
    string line;
    ifstream file(fname);
    getline(file, line);
    if (file.is_open()) {
        string temp_string;
        int id;
        string codeUC;
        string codeClass;
        vector<int> students;
        while (getline(file, line)) {
            stringstream inputString(line);
            getline(inputString, temp_string, ',');
            id = stoi(temp_string);
            getline(inputString, temp_string, ',');
            getline(inputString, codeUC, ',');
            getline(inputString, codeClass, ',');
            int index = hasClass(classStudents, codeUC, codeClass);
            if (index != -1) {
                classStudents[index].addStudent(id);
            } else {
                students.push_back(id);
                ClassStudents c1 = ClassStudents(codeUC, codeClass, students);
                classStudents.push_back(c1);
            }
        }
    } else
        cout << "Could not open the file" << endl;
}

set<Student>::iterator ScheduleManager::findStudent(const int id) {
    Student s = Student(id);
    return students.find(s);
}

void ScheduleManager::receiveRequest(Request& request) {
    this->requests.push(request);
}

void ScheduleManager::processRequests() {
    while (!requests.empty()) {
        directRequest(requests.front());
        requests.pop();
    }
}

void ScheduleManager::directRequest(const Request & request) {
    switch (request.getType()) {
        case 0:
            removeStudent(request);
            break;
        case 1:
            addStudent(request);
            break;
        case 2:
            changeStudentClass(request);
            break;
        case 3:
            changeStudentClasses(request);
            break;
    }
}

string ScheduleManager::removeStudent(const Request& request) {
    // find the student
    int studentID = request.getStudentID();
    ClassUC classUC = request.getFirstClassUC();
    auto it = findStudent(studentID);
        if (it == students.end())
            return "Error: Student not found in the system";
        else {
            // remove his entry in classes of the requested class/UC
            Student student = (*it);
            students.erase(it);
            student.removeClassUC(classUC);
            students.insert(student);
            removeStudentFromYears(studentID, classUC);
            return "Student successfully removed from the system";
        }
}

string ScheduleManager::addStudent(const Request& request) {
    // find the student
    // check for constraints of class capacity and schedule conflicts
    // if possible add student to class
}

string ScheduleManager::changeStudentClass(const Request& request) {
    // find the student
    // check for constraints of class capacity and schedule conflicts
    // if possible make change requested
}

string ScheduleManager::changeStudentClasses(const Request& request) {
    // find the student
    // while there are changes he requested:
        // check for constraints of class capacity and schedule conflicts
        // if possible make change requested

}

list<ClassUC> ScheduleManager::listClassUCbyStudent(Student &student) {
    list<ClassUC> l1=student.getClasses();
    return l1;

}

list<ClassSchedule> ScheduleManager::getStudentSchedule(Student &student) {
    list<ClassUC> l = student.getClasses();
    list<ClassSchedule> res;
    for (ClassUC uc: l) {
        for (ClassSchedule cs: classSchedules) {
            if (uc.getCodeClass()==cs.getCodeClass() && uc.getCodeUC()==cs.getCodeUC()) res.push_back(cs);
        }
    }
    return res;
}

/*
bool ScheduleManager::sortUCCode(ClassSchedule a, ClassSchedule b) {
    return(a.getCodeUC()<b.getCodeUC());
}

void ScheduleManager::orderByUCCode(){
    sort(classSchedules.begin(), classSchedules.end(), sortUCCode);
}

bool sortName(Student a, Student b) {
    return(a.getName()<b.getName());
}

void ScheduleManager::orderByName(){
    vector<Student> stemp;
    for (Student s: students){
        stemp.push_back(s);
    }
    sort(stemp.begin(), stemp.end(), sortName);
}
*/