//
// Created by Joao Ribeiro on 02/11/2022.
//

#ifndef PROJ1_YEAR_H
#define PROJ1_YEAR_H

#include <list>

#include "UC.h"

using namespace std;

class Year {
    int number;
    list<UC> ucs;

public:
    /**
     * Creates a new Year object
     * @param n Number of the Year object
     */
    Year(int n);

    /**
     * Creates a new Year object
     * @param n Number of the Year object
     * @param ucs List of the UCs that belong to that Year
     */
    Year(int n, list<UC> ucs);

    /**
     * Creates a new Year object
     * @param y1 Reference to existing Year object
     */
    Year(const Year& y1);

    /**
     * Returns number of the Year object
     * @return Number of the Year object
     */
    int getNumber();

    /**
     * Returns list of the UCs belonging to the Year object
     * @return List of the UCs belonging to the Year object
     */
    list<UC> getUCs();

    /**
     * Returns an iterator to the end of the UC list
     * @return Iterator to the end of the UC list
     */
    list<UC>::iterator end();

    /**
     * Gives an iterator to a UC within the Year object
     * @param codeUC String corresponding to the code of the UC to find
     * @return Iterator to the required UC, if exists, end() iterator otherwise
     */
    list<UC>::iterator findUC(const string& codeUC);

    /**
     * Adds a UC to the Year
     * @param uc Reference to the UC object to add
     */
    void addUC(const UC& uc);

    /**
     * Removes a UC from the Year
     * @param uc Reference to the UC object to remove
     */
    void removeUC(const UC& uc);
};


#endif //PROJ1_YEAR_H
