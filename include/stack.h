// stack.h

#ifndef TP1_STACK_H
#define TP1_STACK_H

#define DEFAULT_INITIAL_SIZE

#include <memory>

#include "../include/stack.h"
#include <stdexcept>

template<class T>

class Stack {
    int top, capacity;
    T *arr;
public:
    Stack(int initial_size) {
        capacity = initial_size;
        top = -1;
        arr = (T *) malloc(sizeof(T) * capacity);
    }

    Stack() : Stack(DEFAULT_INITIAL_SIZE) {}

    ~Stack() {
        free(arr);
    }

    void push(const T &e) {
        if ((top +1) == capacity) {
            capacity *= 2;
            arr = (T *) realloc(arr, sizeof(T) * capacity);
        }
        arr[++top] = e;
    }

    T pop() {
        if (top == -1) {
            throw std::runtime_error("Stack is empty");
        }
        return arr[top--];
    }

    T get_top_item() {
        if (top == -1) {
            throw std::runtime_error("Stack is empty");
        }
        return arr[top];
    }

    int getSize() {
        return top;
    }

    bool is_empty() {
        return top == -1;
    }
};

#endif // TP1_STACK_H
