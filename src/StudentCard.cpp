//
// Created by Joao Ribeiro on 02/11/2022.
//

#include "StudentCard.h"

StudentCard::StudentCard(int id, string n): id(id), name(std::move(n)) {}

StudentCard::StudentCard(int id): id(id) {}

StudentCard::StudentCard(const StudentCard &s1) {
    this->id = s1.id;
    this->name = s1.name;
}

int StudentCard::getID() const {
    return this->id;
}

void StudentCard::setID(int newID) {
    this->id = newID;
}

string StudentCard::getName() const {
    return this->name;
}

void StudentCard::setName(const string& newName) {
    this->name = newName;
}

bool StudentCard::operator==(const StudentCard &c2) const {
    return (this->id == c2.id);
}