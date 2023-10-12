#include "../include/evaluate.h"
#include "../include/stack.h"
#include <iostream>

#define PERFORM_RIGHT_OPERATION \
    operators.get_top_item() == ('~') \
    ? operands.push(this->execute_operation(operands.pop(), -1, operators.pop())) \
  : operands.push(this->execute_operation(operands.pop(), operands.pop(), operators.pop()))

Evaluate::Evaluate(const char *operation, const char *values) {
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

    std::string operation_str = operation; // convert to std::string
    std::string::size_type i = 0;
    while (i < operation_str.length()) {
        char c = operation_str[i];
        switch (c) {
            case ' ':
                break;
            case '(':
                operators.push(c);
                break;
            case ')':
                while (!operators.is_empty() && operators.get_top_item() != '(') PERFORM_RIGHT_OPERATION;
                if (!operators.is_empty()) operators.pop();
                break;
            default:
                if (isdigit(c)) {
                    std::string::size_type j = i;
                    while (j < operation_str.length() && isdigit(operation_str[j])) {
                        j++;
                    }
                    std::string number_str = operation_str.substr(i, j - i);
                    operands.push((this->values)[std::stoi(number_str)]);
                    i = j;
                    continue;  // Skip the increment at the end of the loop
                } else {
                    while (!operators.is_empty() && !operands.is_empty() && this->priority(operators.get_top_item()) > this->priority(c)) PERFORM_RIGHT_OPERATION;
                    operators.push(c);
                }
                break;
        }
        i++;
    }

    while (!operators.is_empty()) PERFORM_RIGHT_OPERATION;

    return operands.pop();
}
