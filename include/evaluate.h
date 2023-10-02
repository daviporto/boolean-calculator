//
// Created by daviaraujo on 21/09/23.
//

#ifndef TP1_EVALUATE_H
#define TP1_EVALUATE_H

#include "string"
#include <cstdint>

typedef uint8_t byte;

class Evaluate {
    const char *operation, *values;
public:
    Evaluate(const char *operation, const char *values);

    byte execute_operation(byte a, byte b, char op);

    int priority(char op);

    byte evaluate();
};


#endif //TP1_EVALUATE_H
