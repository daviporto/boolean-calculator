#ifndef TP1_STACK_H
#define TP1_STACK_H

#define DEFAULT_INITIAL_SIZE

#include <memory>

#include "../include/stack.h"
#include <stdexcept>

template<class T>
/**
 * @class Stack
 * @brief A class that represents a stack data structure.
 *
 * This class provides the necessary methods to manage a stack, including push, pop, get the top item, get the size, and check if the stack is empty.
 */
class Stack {
    int top; ///< The index of the top item in the stack.
    int capacity; ///< The capacity of the stack.
    T *arr; ///< The array that stores the items in the stack.

public:
    /**
     * @brief Construct a new Stack object with a specified initial size.
     *
     * This constructor initializes the top index, capacity, and array of the stack.
     *
     * @param initial_size The initial size of the stack.
     */
    Stack(int initial_size) {
        capacity = initial_size;
        top = -1;
        arr = (T *) malloc(sizeof(T) * capacity);
    }

    /**
     * @brief Construct a new Stack object with the default initial size.
     */
    Stack() : Stack(DEFAULT_INITIAL_SIZE) {}

    /**
     * @brief Destroy the Stack object.
     *
     * This destructor frees the memory allocated for the array of the stack.
     */
    ~Stack() {
        free(arr);
    }

    /**
     * @brief Push an item onto the stack.
     *
     * This method pushes an item onto the stack. If the stack is full, it doubles the capacity of the stack.
     *
     * @param e The item to be pushed onto the stack.
     */
    void push(const T &e) {
        if ((top +1) == capacity) {
            capacity *= 2;
            arr = (T *) realloc(arr, sizeof(T) * capacity);
        }
        arr[++top] = e;
    }

    /**
     * @brief Pop an item from the stack.
     *
     * This method pops an item from the stack. If the stack is empty, it throws a runtime error.
     *
     * @return The item popped from the stack.
     */
    T pop() {
        if (top == -1) {
            throw std::runtime_error("Stack is empty");
        }
        return arr[top--];
    }

    /**
     * @brief Get the top item of the stack.
     *
     * This method returns the top item of the stack. If the stack is empty, it throws a runtime error.
     *
     * @return The top item of the stack.
     */
    T get_top_item() {
        if (top == -1) {
            throw std::runtime_error("Stack is empty");
        }
        return arr[top];
    }

    /**
     * @brief Get the size of the stack.
     *
     * This method returns the size of the stack, which is the index of the top item.
     *
     * @return The size of the stack.
     */
    int getSize() {
        return top;
    }

    /**
     * @brief Check if the stack is empty.
     *
     * This method checks if the stack is empty.
     *
     * @return True if the stack is empty, false otherwise.
     */
    bool is_empty() {
        return top == -1;
    }
};

#endif // TP1_STACK_H
