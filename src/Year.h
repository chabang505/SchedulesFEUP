//
// Created by Joao Ribeiro on 02/11/2022.
//

#ifndef PROJ1_YEAR_H
#define PROJ1_YEAR_H

#include <list>

#include "UC.h"

class Year {
    int number;
    list<UC> ucs;

public:
    Year(int n, list<UC> ucs);
    Year(const Year& y1);
    int getNumber();
    list<UC> getUCs();
    void addUC(const UC& uc);
    void removeUC(const UC& uc);
};


#endif //PROJ1_YEAR_H
