#ifndef TP1_BINARYTREE_H
#define TP1_BINARYTREE_H

#include "node.h"
#include <string.h>

class BinaryTree {
    std::string operation, values;
    Node *root;

public:
    BinaryTree(const char &operation, const char &values);
    ~BinaryTree();
    Node* build_solution_tree(std::string values, unsigned int char_index);
    bool is_build();
    void destroy(Node *node);
    void evaluate(Node *node, unsigned int level);
    Node* get_root() const;
};


#endif //TP1_BINARYTREE_H
