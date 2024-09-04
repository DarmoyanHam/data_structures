#ifndef BSTPP
#define BSTPP

#include <iostream>
#include <queue>
#include <stack>
#include "bst.h"


template <typename T>
BSTree::BinaryTree<T>::BinaryTree()
: root{nullptr}
{}

template <typename T>
BSTree::BinaryTree<T>::BinaryTree(T data)
: root{data}
{}

template <typename T>
BSTree::BinaryTree<T>::~BinaryTree()
{
    clear();
}

template <typename T>
void BSTree::BinaryTree<T>::insert(T data)
{
    if(!root)
    {
        root = new TreeNode<T>(data);
    }
    else
    {
        insertHelper(root, data);
    }
}

template <typename T>
BSTree::TreeNode<T>* BSTree::BinaryTree<T>::insertHelper(TreeNode<T>* node, T data)
{
    if(!node)
    {
        return new TreeNode<T>(data);
    }
    if(data < node->data)
    {
        node->left = insertHelper(node->left, data);
    }
    else if(data > node->data)
    {
        node->right = insertHelper(node->right, data);
    }

    return node;
}

template <typename T>
BSTree::TreeNode<T>* BSTree::BinaryTree<T>::insertHelperIterative(T data)
{
    TreeNode<T>* tmp = root;
    while(tmp)
    {
        if(data < tmp->data)
        {
            if(!tmp->left)
            {
                tmp->left = new TreeNode<T>(data);
                return;
            }
            tmp = tmp->left;
        }
        else if(data > tmp->data)
        {
            if(!tmp->right)
            {
                tmp->right = new TreeNode<T>(data);
                return;
            }
            tmp = tmp->right;
        }
    }
}

template <typename T>
BSTree::TreeNode<T>* BSTree::BinaryTree<T>::find(T data)
{
    if(!root)
    {
        return nullptr;
    }
    else
    {
        return findHelper(root, data);
    }
}

template <typename T>
BSTree::TreeNode<T>* BSTree::BinaryTree<T>::findHelper(TreeNode<T>* node, T data)
{
    if(!node)
    {
        return nullptr;
    }
    if(node->val == data)
    {
        return node;
    }
    if(data < node->data)
    {
        return findHelper(node->left, data);
    }
    else if(data > node->data)
    {
        return findHelper(node->right, data);
    }
}

template <typename T>
BSTree::TreeNode<T>* BSTree::BinaryTree<T>::findIterative(T data)
{
    if(!root)
    {
        return nullptr;
    }
    TreeNode<T>* curr = root;
    while(curr)
    {
        if(curr->data == data)
        {
            return curr;
        }
        if(data < curr->data)
        {
            if(!curr->left)
            {
                return nullptr;
            }
            curr = curr->left;
        }
        else if(data > curr->data)
        {
            if(!curr->right)
            {
                return nullptr;
            }
            curr = curr->right;
        }
    }
}

template <typename T>
T BSTree::BinaryTree<T>::findMin(TreeNode<T>* node) const
{
    if(!node)
    {
        return -1;
    }
    TreeNode<T>* tmp = node;
    while(tmp->left)
    {
        tmp = tmp->left;
    }
    return tmp->data;
}

template <typename T>
bool BSTree::BinaryTree<T>::isEmpty() const
{
    return root == nullptr;
}

template <typename T>
BSTree::TreeNode<T>* remove(T data)
{
    if(isEmpty())
    {
        return nullptr;
    }
    return removeHelper(root, data);
}

template <typename T>
BSTree::TreeNode<T>* BSTree::BinaryTree<T>::removeHelper(TreeNode<T>* node, T data)
{
    if(!node)
    {
        return nullptr;
    }
    if(data < node->data)
    {
        node->left = removeHelper(node->left, data);
    }
    else if(data > node->data)
    {
        node->right = removeHelper(node->right, data);
    }
    else
    {
        if(!node->left)
        {
            TreeNode<T>* tmp = node->right;
            delete node;
            return tmp;
        }
        else if(!node->right)
        {
            TreeNode<T>* tmp = node->left;
            delete node;
            return tmp;
        }
        else
        {
            T value = findMin(node->right);
            node->val = value;
            node->right = removeHelper(node->right, value);
        }
    }
    return node;
}

template <typename T>
void BSTree::BinaryTree<T>::inorder() const
{
    if(!isEmpty())
    {
        inorderHelper(root);
    }
}

template <typename T>
void BSTree::BinaryTree<T>::preorder() const
{
    if(!isEmpty())
    {
        preorderHelper(root);
    }
}

template <typename T>
void BSTree::BinaryTree<T>::postorder() const
{
    if(!isEmpty())
    {
        postorder(root);
    }
}

template <typename T>
void BSTree::BinaryTree<T>::inorderHelper(TreeNode<T>* node) const
{
    inorderHelper(node->left);
    std::cout << node->data " ";
    inorderHelper(node->right);
}

template <typename T>
void BSTree::BinaryTree<T>::preorderHelper(TreeNode<T>* node) const
{
    std::cout << node->data << " ";
    preorderHelper(node->left);
    preorderHelper(node->right);
}

template <typename T>
void BSTree::BinaryTree<T>::postorderHelper(TreeNode<T>* node) const
{
    postorderHelper(node->left);
    postorderHelper(node->right);
    std::cout << node->data << " ";
}

template <typename T>
void BSTree::BinaryTree<T>::levelorder() const
{
    if(isEmpty())
    {
        return;
    }
    std::queue<Treenode<T>*> q;
    q.push(root);
    while(!q.empty())
    {
        TreeNode<T>* tmp = q.front();
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
void BSTree::BinaryTree<T>::inorderIterative() const
{
    if(isEmpty())
    {
        return;
    }
    std::stack<TreeNode<T>*> st;
    TreeNode<T>* curr = root;
    while(curr || !st.empty())
    {
        while(curr)
        {
            st.push(curr);
            curr = curr->left;
        }
        curr = st.top();
        st.pop();
        std::cout << curr->data << " ";
        curr = curr->right;
    }
}

template <typename T>
void BSTree::BinaryTree<T>::preorderIterative() const
{
    if(isEmpty())
    {
        return;
    }
    std::stack<TreeNode<T>*> st;
    TreeNode<T>* curr = root;
    while(!st.empty() || curr)
    {
        while (curr)
        {
            std::cout << curr->data << " ";
            if(curr->right)
            {
                st.push(curr->right);
            }
            curr = curr->left;
        }
        if(!st.empty())
        {
            curr = st.top();
            st.pop();
        }
    }
}

template <typename T>
void BSTree::BinaryTree<T>::postorderIterative() const
{
    if(isEmpty())
    {
        return;
    }
    
    std::stack<TreeNode<T>*> st1, st2;
    st1.push(root);
    TreeNode<T>* tmp;

    while(!st1.empty())
    {
        tmp = st1.top();
        st1.pop();
        st2.push(tmp);
        if(tmp->left)
        {
            st1.push(tmp->left);
        }
        if(tmp->right)
        {
            st1.push(tmp->right);
        }
    }
    while(!st2.empty())
    {
        tmp = st2.top();
        st2.pop();
        std::cout << tmp->data " ";
    }
}

template <typename T>
void BSTree::BinaryTree<T>::clear(TreeNode<T>* node)
{
    if(!node)
    {
        return;
    }
    clear(node->left);
    clear(node->right);
    delete node;
}

#endif