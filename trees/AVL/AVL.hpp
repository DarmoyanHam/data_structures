#ifndef AVL_HPP
#define AVL_HPP

#include <iostream>
#include <queue>
#include "AVL.h"

template <typename T>
AVL::AVLTree<T>::AVLTree()
: root{nullptr} {}

template <typename T>
AVL::AVLTree<T>::AVLTree(value_type data)
: root{new TreeNode<T>{data}}
{}

template <typename T>
AVL::AVLTree<T>::~AVLTree()
{
    clear(root);
}

template <typename T>
typename AVL::AVLTree<T>::value_type AVL::AVLTree<T>::get_height(Node_pointer node) const
{
    if(!node)
    {
        return 0;
    }
    return std::max(get_height(node->left), get_height(node->right)) + 1;
}

template <typename T>
int AVL::AVLTree<T>::get_balance(Node_pointer node) const
{
    return node == nullptr ? 0 : get_height(node->left) - get_height(node->right);
}

template <typename T>
typename AVL::AVLTree<T>::Node_pointer AVL::AVLTree<T>::right_rotation(Node_pointer node)
{
    Node_pointer x = node->left;
    Node_pointer tmp = x->right;

    x->right = node;
    node->left = tmp;

    return x;
}

template <typename T>
typename AVL::AVLTree<T>::Node_pointer AVL::AVLTree<T>::left_rotation(Node_pointer node)
{
    Node_pointer x = node->right;
    Node_pointer tmp = x->left;

    x->left = node;
    node->right = tmp;

    return x;
}

template <typename T>
bool AVL::AVLTree<T>::isEmpty() const
{
    return root == nullptr;
}

template <typename T>
void AVL::AVLTree<T>::insert(value_type data)
{
    root = insertHelper(root, data);
}

template <typename T>
typename AVL::AVLTree<T>::Node_pointer AVL::AVLTree<T>::insertHelper(Node_pointer node, value_type data)
{
    if(!node)
    {
        return new TreeNode<value_type>(data);
    }
    if(data < node->data)
    {
        node->left = insertHelper(node->left, data);
    }
    else if(data > node->right->data)
    {
        node->right = insertHelper(node->right, data);
    }
    else
    {
        return node;
    }

    int balance = get_balance(node);

    if(balance > 1 && data < node->left->data)
    {
        return right_rotation(node);
    }
    if(balance < -1 && data > node->right->data)
    {
        return left_rotation(node);
    } 
    if(balance > 1 && data > node->left->data)
    {
        node->left = left_rotation(node->left);
        return right_rotation(node);
    }
    if(balance < -1 && data < node->right->data)
    {
        node->right = right_rotation(node->right);
        return left_rotation(node);
    }

    return node;
}

template <typename T>
void AVL::AVLTree<T>::remove(value_type data)
{
    if(!root)
    {
        return;
    }
    root = removeHelper(root, data);
}

template <typename T>
typename AVL::AVLTree<T>::Node_pointer AVL::AVLTree<T>::removeHelper(Node_pointer node, value_type data)
{
    if(!node)
    {
        return nullptr;
    }
    if(node->data > data)
    {
        node->left = removeHelper(node->left, data);
    }
    else if(node->data < data)
    {
        node->right = removeHelper(node->right, data);
    }
    else
    {
        if(!node->left)
        {
            return node->right;
        }
        else if(!node->right)
        {
            return node->left;
        }
        else
        {
            value_type min = findMinHelper(node->right);
            node->data = min;
            node->right = removeHelper(node->right, min);
        }
    }

    if(!node)
    {
        return nullptr;
    }

    int balance = get_balance(node);

    if(balance > 1 && get_balance(node->left) >= 0)
    {
        return right_rotation(node);
    }
    if(balance > 1 && get_balance(node->left) < 0)
    {
        node->left = left_rotation(node->left);
        return right_rotation(node);
    }
    if(balance < -1 && get_balance(node->right) < 0)
    {
        return left_rotation(node);
    }
    if(balance < -1 && get_balance(node->right) >= 0)
    {
        node->right = right_rotation(node->right);
        return left_rotation(node);
    }

    return node;
}

template <typename T>
typename AVL::AVLTree<T>::Node_pointer AVL::AVLTree<T>::find(value_type data) const
{
    if(!root)
    {
        return nullptr;
    }
    return findHelper(root, data);
}

template <typename T>
typename AVL::AVLTree<T>::Node_pointer AVL::AVLTree<T>::findHelper(Node_pointer node, value_type data) const
{
    if(!node)
    {
        return nullptr;
    }
    if(data < node->data)
    {
        return findHelper(node->left, data);
    }
    if(data > node->data)
    {
        return findHelper(node->right, data);
    }
    if(data == node->data)
    {
        return node;
    }
}

template <typename T>
typename AVL::AVLTree<T>::value_type AVL::AVLTree<T>::findMin() const
{
    if(!root)
    {
        return -1;
    }
    return findMinHelper(root);
}

template <typename T>
typename AVL::AVLTree<T>::value_type AVL::AVLTree<T>::findMinHelper(Node_pointer node) const
{
    if(!node->left)
    {
        return node->data;
    }
    return findMinHelper(node->left);
}

template <typename T>
void AVL::AVLTree<T>::inorder() const
{
    if(!root)
    {
        return;
    }
    inorderHelper(root);
}

template <typename T>
void AVL::AVLTree<T>::preorder() const
{
    if(!root)
    {
        return;
    }
    preorderHelper(root);
}

template <typename T>
void AVL::AVLTree<T>::postorder() const
{
    if(!root)
    {
        return;
    }
    postorderHelper(root);
}

template <typename T>
void AVL::AVLTree<T>::levelOrder() const
{
    if(!root)
    {
        return;
    }
    std::queue<Node_pointer> q;
    q.push(root);
    while(!q.empty())
    {
        Node_pointer tmp = q.front();
        q.pop();
        std::cout << tmp->data << " ";
        if(tmp->left)
        {
            q.push(tmp->left);
        }
        if(tmp->right)
        {
            q.push(tmp->right);
        }
    }
}

template <typename T>
void AVL::AVLTree<T>::inorderHelper(Node_pointer node) const
{
    if(node)
    {
        inorderHelper(node->left);
        std::cout << node->data << " ";
        inorderHelper(node->right);
    }
}

template <typename T>
void AVL::AVLTree<T>::preorderHelper(Node_pointer node) const
{
    if(node)
    {
        std::cout << node->data << " ";
        preorderHelper(node->left);
        preorderHelper(node->right);
    }
}

template <typename T>
void AVL::AVLTree<T>::postorderHelper(Node_pointer node) const
{
    if(node)
    {
        postorderHelper(node->left);
        postorderHelper(node->right);
        std::cout << node->data << " ";
    }
}

template <typename T>
void AVL::AVLTree<T>::clear(Node_pointer node)
{
    clear(node->left);
    clear(node->right);
    delete node;
}

#endif
