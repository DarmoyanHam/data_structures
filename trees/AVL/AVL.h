#ifndef AVL_H
#define AVL_H

#include <iostream>

namespace AVL{

template <typename T>
struct TreeNode {
    TreeNode* left;
    TreeNode* right;
    T data;
    TreeNode() : data{0} , left{nullptr} , right{nullptr} {}
    TreeNode(T val) : data{val} , left{nullptr} , right{nullptr} {}
};

template <typename T>
class AVLTree {
public:
    using value_type = T;
    using reference = value_type&;
    using pointer = value_type*;
    using Node_pointer = TreeNode<value_type>*;
public:
    AVLTree(); //
    AVLTree(value_type data); //
    ~AVLTree(); //
public:
    value_type get_height(Node_pointer node) const; //
    int get_balance(Node_pointer node) const; //
    Node_pointer insert(value_type data); //
    void remove(value_type data); //
    bool isEmpty() const; //
    value_type findMin() const; //
    Node_pointer find(value_type data) const; //
    void inorder() const; //
    void preorder() const; //
    void postorder() const; //
    void levelOrder() const; //
    void clear(Node_pointer node); //
private:
    void inorderHelper(Node_pointer node) const; //
    void preorderHelper(Node_pointer node) const; //
    void postorderHelper(Node_pointer node) const; //
    Node_pointer findHelper(Node_pointer node, value_type data) const; //
    value_type findMinHelper(Node_pointer node) const; //
    Node_pointer right_rotation(Node_pointer node); //
    Node_pointer left_rotation(Node_pointer node); //
    Node_pointer insertHelper(Node_pointer node, value_type data); //
    Node_pointer removeHelper(Node_pointer node, value_type data); //
private:
    Node_pointer root;
};

}

#endif