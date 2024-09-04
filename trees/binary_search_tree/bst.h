#ifndef BST
#define BST

#include <iostream>

namespace BSTree {

template <typename T>
struct TreeNode {
    T data;
    TreeNode<T>* left;
    TreeNode<T>* right;
    TreeNode() : data{0} , left{nullptr} , right{nullptr} {}
    TreeNode(T val) : data{val} , left{nullptr} , right{nullptr} {}
};

template <typename T>
class BinaryTree {
public:
    BinaryTree(); //
    BinaryTree(T); //
    ~BinaryTree(); //
public:
    TreeNode<T>* find(T); //
    TreeNode<T>* findIterative(T); //
    T findMin(TreeNode<T>* node) const; //
    void insert(T); //
    TreeNode<T>* remove(T); //
    void inorder() const; //
    void inorderIterative() const; //
    void preorderIterative() const; //
    void postorderIterative() const; //
    void preorder() const; //
    void postorder() const; //
    void levelorder() const; //
    bool isEmpty() const; //
    void clear(TreeNode<T>*); //
private:
    void inorderHelper(TreeNode<T>*) const; //
    void preorderHelper(TreeNode<T>*) const; // 
    void postorderHelper(TreeNode<T>*) const; //
    TreeNode<T>* removeHelper(TreeNode<T>*, T); //
    TreeNode<T>* findHelper(TreeNode<T>*, T); //
    TreeNode<T>* insertHelper(TreeNode<T>*, T); //
    TreeNode<T>* insertHelperIterative(T); //
private:
    TreeNode<T>* root;
};

}

#include "bst.hpp"

#endif