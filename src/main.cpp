#include <memory>
#include "../include/evaluate.h"
#include "../include/satisfiability.h"
#include <iostream>
#include "string.h"

int main(int argc, char *argv[]) {
    if (argc != 4) {
        return 0;
        throw std::runtime_error("argc must be 3");
    }

    if (argv[1][1] == 'a') {
        auto e = Evaluate(argv[2], argv[3]);
        std::cout << e.evaluate();
    } else if (argv[1][1] == 's') {
        auto s = Satisfiability(argv[2], argv[3]);
        s.evaluate();
    } else {
        throw std::runtime_error("Invalid argument");
    }
}

