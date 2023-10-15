#ifndef TP1_EVALUATE_H
#define TP1_EVALUATE_H

#include "string"
#include <cstdint>

typedef uint8_t byte; ///< Define byte as an alias for uint8_t.

/**
 * @class Evaluate
 * @brief A class that evaluates a given operation on given values.
 *
 * This class provides the necessary methods to execute an operation and evaluate the result.
 * It also provides a method to get the priority of an operation.
 */
class Evaluate {
    const char *operation; ///< The operation to be executed.
    const char *values; ///< The values on which the operation is to be executed.

public:
    /**
     * @brief Construct a new Evaluate object.
     *
     * This constructor initializes the operation and values to be used.
     *
     * @param operation The operation to be executed.
     * @param values The values on which the operation is to be executed.
     */
    Evaluate(const char *operation, const char *values);

    /**
     * @brief Execute the operation on the given values.
     *
     * This method executes the operation on the given values and returns the result.
     * The operations can be bitwise AND (&), bitwise OR (|), or bitwise NOT (~).
     * When the operation is NOT, the second value is ignored.
     *
     * @param a The first value.
     * @param b The second value.
     * @param op The operation to be executed.
     * @return The result of the operation.
     */
    byte execute_operation(byte a, byte b, char op);

    /**
     * @brief Get the priority of the operation.
     *
     * This method returns the priority of the operation.
     * The priority is 3 for the NOT operation (~), 2 for the AND operation (&), and 1 for the OR operation (|).
     *
     * @param op The operation whose priority is to be returned.
     * @return The priority of the operation.
     */
    int priority(char op);

    /**
     * @brief Evaluate the operation on the values.
     *
     * This method evaluates the operation on the values and returns the result.
     * It uses a stack-based algorithm to process the operation and the values.
     *
     * @return The result of the operation.
     */
    byte evaluate();
};

#endif //TP1_EVALUATE_H
