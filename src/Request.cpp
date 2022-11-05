//
// Created by Joao Ribeiro on 19/10/2022.
//

#include "Request.h"

Request::Request(int t, int id, list<ClassUC> &cc):
        type(t), studentID(id), currentClasses(cc) {}

Request::Request(int t, int id, ClassUC cuc):
        type(t), studentID(id), classUC(cuc) {}

Request::Request(int t, int id, list<ClassUC> & cc, list<ClassUC> & rc):
        type(t), studentID(id), currentClasses(cc), requestedClasses(rc) {}

Request::Request(const Request& r1) {
    this->type = r1.type;
    this->studentID = r1.studentID;
    this->currentClasses = r1.currentClasses;
    this->requestedClasses = r1.requestedClasses;
}

int Request::getType() const{
    return this->type;
}

int Request::getStudentID() const{
    return this->studentID;
}

ClassUC Request::getClassUC() const {
    return this->classUC;
}

list<ClassUC> Request::getCurrentClasses() const{
    return this->currentClasses;
}

list<ClassUC> Request::getRequestedClasses() const{
    return this->requestedClasses;
}

ClassUC Request::getFirstClassUC() const{
    return this->currentClasses.front();
}