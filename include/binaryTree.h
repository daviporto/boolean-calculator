#ifndef TP1_BINARYTREE_H
#define TP1_BINARYTREE_H

#include "node.h"
#include <string.h>


/**
 * @class BinaryTree
 * @brief A class that represents a binary tree for certain operations and values.
 *
 * This class provides the necessary methods to build, evaluate, and destroy the binary tree.
 * It also provides a method to check if the tree is built and a method to get the root of the tree.
 */
class BinaryTree {
    std::string operation, values; ///< The operation and values to be used in the binary tree.
    Node *root; ///< The root node of the binary tree.

public:
    /**
     * @brief Construct a new Binary Tree object.
     *
     * This constructor builds the solution tree using the provided operation and values.
     *
     * @param operation The operation to be used in the binary tree.
     * @param values The values to be used in the binary tree.
     */
    BinaryTree(const char &operation, const char &values);

    /**
     * @brief Destroy the Binary Tree object.
     *
     * This destructor destroys the binary tree starting from the root.
     */
    ~BinaryTree();

    /**
     * @brief Build the solution tree using the provided values.
     *
     * This method builds the solution tree using the provided
     * and generating leaves for each quantifier values and returns the root of the tree.
     *
     * @param values The values to be used in the binary tree.
     * @param char_index The starting index for the provided values.
     * @return The root of the solution tree.
     */
    Node* build_solution_tree(std::string values, unsigned int char_index);

    /**
     * @brief Check if the binary tree is built.
     *
     * This method checks if the root of the binary tree is not null.
     *
     * @return True if the binary tree is built, false otherwise.
     */
    bool is_build();

    /**
     * @brief Destroy the binary tree starting from the provided node.
     *
     * This method destroys the binary tree starting from the provided node.
     *
     * @param node The starting node for destroying the binary tree.
     */
    void destroy(Node *node);

    /**
     * @brief Evaluate the binary tree starting from the provided node.
     *
     * This method evaluates the binary from the leaves, going up evaluating each partial expression.
     *
     * @param node The starting node for evaluating the binary tree.
     * @param level The level of the node in the binary tree.
     */
    void evaluate(Node *node, unsigned int level);

    /**
     * @brief Get the root of the binary tree.
     *
     * This method returns the root of the binary tree.
     *
     * @return The root of the binary tree.
     */
    Node* get_root() const;
};


#endif //TP1_BINARYTREE_H
