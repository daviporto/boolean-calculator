//
// Created by daviaraujo on 24/09/23.
//

#ifndef TP1_SATISFIABILITY_H
#define TP1_SATISFIABILITY_H

#include "binaryTree.h"
#include <string>

class Satisfiability {
    char *operation, *values;
    BinaryTree *tree;
public:
    Satisfiability(char *operation, char *values);

    ~Satisfiability();

    void evaluate();
};


#endif //TP1_SATISFIABILITY_H
