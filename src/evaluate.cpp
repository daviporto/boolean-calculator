//
// Created by daviaraujo on 21/09/23.
//

#include "../include/evaluate.h"
#include "../include/stack.h"
#include <iostream>

Evaluate::Evaluate(const char *operation, const  char *values) {
    this->operation = operation;
    this->values = values;
}

#include <stdexcept>

int Evaluate::priority(char op) {
    if (op == '&')
        return 2;
    if (op == '|')
        return 1;
    if (op == '~')
        return 3;

    return 0;
}

byte Evaluate::execute_operation(byte a, byte b, char _operator) {
    switch (_operator) {
        case '&':
            return a & b;
        case '|':
            return a | b;
        case '~':
            return a == '0' ? '1' : '0';
        default:
            return -1;
    }
}

byte Evaluate::evaluate() {
    auto operands = Stack<byte>(100);
    auto operators = Stack<char>(100);

    for (auto c: (std::string)this->operation) {
        if (c == ' ') {
            continue;
        } else if (c == '(') {
            operators.push(c);
        } else if (isdigit(c)) {
            operands.push((this->values)[c - '0']);
        } else if (c == ')') {
            while (!operators.is_empty() && operators.get_top_item() != '(') {
                operators.get_top_item() == ('~')
                ? operands.push(this->execute_operation(operands.pop(), -1, operators.pop()))
                : operands.push(this->execute_operation(operands.pop(), operands.pop(), operators.pop()));
            }

            if (!operators.is_empty()) operators.pop();
        } else {
            while (!operators.is_empty() && this->priority(operators.get_top_item()) >= this->priority(c)) {
                operators.get_top_item() == ('~')
                ? operands.push(this->execute_operation(operands.pop(), -1, operators.pop()))
                : operands.push(this->execute_operation(operands.pop(), operands.pop(), operators.pop()));
            }
            operators.push(c);
        }
    }

    while (!operators.is_empty()) {
        operators.get_top_item() == ('~')
        ? operands.push(this->execute_operation(operands.pop(), -1, operators.pop()))
        : operands.push(this->execute_operation(operands.pop(), operands.pop(), operators.pop()));
    }

    return operands.pop();
}
