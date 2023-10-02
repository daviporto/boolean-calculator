//
// Created by daviaraujo on 24/09/23.
//

#include "../include/satisfiability.h"
#include <iostream>

Satisfiability::Satisfiability(char *operation, char *values) {
    this->tree = new BinaryTree(*operation, *values);
    this->operation = operation;
    this->values = values;
}

Satisfiability::~Satisfiability() {
    delete this->tree;
}

std::string Satisfiability::evaluate() {
    if (this->tree->is_build()) {
        this->tree->evaluate(this->tree->get_root(), 0);
        std::cout << "Expression: " << this->tree->get_root()->get_expression_result() << std::endl;
        return this->tree->get_root()->get_values();
    }
    return " ";
}


