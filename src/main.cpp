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

    if (strcmp(argv[1], "-a") == 0) {
        auto e = Evaluate(argv[2], argv[3]);
        std::cout << e.evaluate();
    } else if (strcmp(argv[1], "−s") == 0) {
        auto s = Satisfiability(argv[2], argv[3]);
        std::cout << "done " << s.evaluate() << std::endl;
    } else {
        throw std::runtime_error("Invalid argument");
    }
}

