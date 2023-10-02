#include "../include/binaryTree.h"
#include "../include/node.h"

BinaryTree::BinaryTree(const char &operation, const char &values) {
    this->values = &values;
    this->operation = &operation;
    this->root = build_solution_tree(&values, 0);
}

BinaryTree::~BinaryTree() {
    destroy(this->root);
}

Node *BinaryTree::build_solution_tree(std::string values, unsigned int char_index) {
    Node *node = new Node(values);

    for (auto i = char_index; i < values.length(); i++) {
        if (values[i] == 'e' || values[i] == 'a') {
            std::string left_values = values;
            left_values[i] = '0';
            node->left = build_solution_tree(left_values, i + 1);

            std::string right_values = values;
            right_values[i] = '1';
            node->right = build_solution_tree(right_values, i + 1);

            break;
        }
    }

    return node;
}

bool BinaryTree::is_build() {
    return this->root != nullptr;
}

void BinaryTree::destroy(Node *node) {
    if (node) {
        destroy(node->left);
        destroy(node->right);
        delete node;
    }
}

void BinaryTree::evaluate(Node *node, unsigned int level) {
    if (node) {
        evaluate(node->left, level + 1);
        evaluate(node->right, level + 1);

        if (node->left == nullptr && node->right == nullptr) {
            //leaves
            node->set_expression_result((Evaluate(this->operation.c_str(), node->get_values().c_str())).evaluate());
        } else if (node->left->get_expression_result() == '1' && node->right->get_expression_result() == '1') {
            //both true
            node->set_expression_result('1');
            for (unsigned int i = 0; i < node->get_values().length(); i++)
                node->set_value(
                        node->left->get_values()[i] == node->right->get_values()[i] ? node->left->get_values()[i] : 'a', i);
        } else if (node->left->get_expression_result() == '0' && node->right->get_expression_result() == '0') {
            //both false
            node->set_expression_result('0');
        } else {
            //one true, one false
            auto quantifier = node->get_quantifier();
            if (quantifier == 'a')
                node->set_expression_result('0');
            else {
                node->set_expression_result('1');
                node->left->get_expression_result() == '1'
                ? node->set_values(node->left->get_values())
                : node->set_values(node->right->get_values());
            }
        }
    }
}

Node *BinaryTree::get_root() const { return this->root; }
