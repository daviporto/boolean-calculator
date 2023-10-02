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

void Satisfiability::evaluate() {
    if (this->tree->is_build()) {
        this->tree->evaluate(this->tree->get_root(), 0);
        this->tree->get_root()->get_expression_result() == '1'
        ? std::cout << "1 " << this->tree->get_root()->get_values() << std::endl
        : std::cout << "0 " << std::endl;
    }
}


