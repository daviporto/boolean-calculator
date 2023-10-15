#ifndef TP1_SATISFIABILITY_H
#define TP1_SATISFIABILITY_H

#include "binaryTree.h"
#include <string>

/**
 * @class Satisfiability
 * @brief A class that checks the satisfiability of a given operation on given values.
 *
 * This class provides the necessary methods to evaluate the operation and print the result.
 */
class Satisfiability {
    char *operation; ///< The operation to be evaluated.
    char *values; ///< The values on which the operation is to be evaluated.
    BinaryTree *tree; ///< The binary tree representing the operation and values.

public:
    /**
     * @brief Construct a new Satisfiability object.
     *
     * This constructor initializes the operation and values to be evaluated and creates a new binary tree.
     *
     * @param operation The operation to be evaluated.
     * @param values The values on which the operation is to be evaluated.
     */
    Satisfiability(char *operation, char *values);

    /**
     * @brief Destroy the Satisfiability object.
     *
     * This destructor deletes the binary tree.
     */
    ~Satisfiability();

    /**
     * @brief Evaluate the operation on the values and print the result.
     *
     * This method evaluates the operation on the values and prints the result.
     * If the binary tree is built, it evaluates the operation at the root of the tree and prints the result.
     * If the result is 1, it also prints the values at the root of the tree.
     */
    void evaluate();
};

#endif //TP1_SATISFIABILITY_H
