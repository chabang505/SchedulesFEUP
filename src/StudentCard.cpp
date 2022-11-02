//
// Created by Joao Ribeiro on 02/11/2022.
//

#include "StudentCard.h"

StudentCard::StudentCard(int id, std::string n): id(id), name(n) {}

StudentCard::StudentCard(const StudentCard &s1) {
    this->id = s1.id;
    this->name = s1.name;
}

int StudentCard::getID() {
    return this->id;
}

void StudentCard::setID(int newID) {
    this->id = newID;
}

string StudentCard::getName() {
    return this->name;
}

void StudentCard::setName(std::string newName) {
    this->name = newName;
}

bool StudentCard::operator==(const StudentCard &c2) const {
    return (this->id == c2.id && this->name == c2.name);
}