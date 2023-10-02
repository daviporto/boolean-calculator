//
// Created by daviaraujo on 01/10/23.
//

#ifndef TP1_NODE_H
#define TP1_NODE_H

#include <string>
#include "evaluate.h"

class Node {
    std::string values;
    byte expression_result;
public:
    Node *left, *right;
    Node(std::string values);
    void update_index(char new_value, unsigned int index);
    byte get_expression_result() const;
    void set_expression_result(byte expression_result);
    char get_quantifier();
    std::string get_values() const;
};


#endif //TP1_NODE_H
