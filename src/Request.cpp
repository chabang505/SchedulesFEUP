//
// Created by Joao Ribeiro on 19/10/2022.
//

#include "Request.h"

Request::Request(string t, string s, list<ClassUC> cc, list<ClassUC> rc): type(t), student(s),
    currentClasses(cc), requestedClasses(rc) {}

Request::Request(const Request& r1) {
    this->type = r1.type;
    this->student = r1.student;
    this->currentClasses = r1.currentClasses;
    this->requestedClasses = r1.requestedClasses;
}

string Request::getType() {
    return this->type;
}

string Request::getStudent() {
    return this->student;
}

list<ClassUC> Request::getCurrentClasses() {
    return this->currentClasses;
}

list<ClassUC> Request::getRequestedClasses() {
    return this->requestedClasses;
}