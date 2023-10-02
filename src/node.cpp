#include "../include/node.h"

Node::Node(std::string values) {
    this->values = values;
    this->left = this->right = nullptr;
}

void Node::update_index(char new_value, unsigned int index) {
    this->values[index] = new_value;
}

byte Node::get_expression_result() const { return this->expression_result; }

void Node::set_expression_result(byte expression_result) { this->expression_result = expression_result; }

char Node::get_quantifier() {
    for (auto c: this->values) {
        if (c == 'a' || c == 'e') return c;
    }
    return ' ';
}

std::string Node::get_values() const { return this->values; }

void Node::set_values(std::string values) { this->values = values; }

void Node::set_value(char value, unsigned int index) {
    this->values[index] = value;
}
