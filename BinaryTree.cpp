#include <iostream>
#include "BinaryTree.h"
using namespace std;
Node* createNode(int value)
{
    Node *newNode = new Node;
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}
Node* insert(Node *root, int value)
{
    if (root == NULL)
    {
        return createNode(value);
    }
    if (root->left == NULL)
    {
        root->left = createNode(value);
    }
    else if (root->right == NULL)
    {
        root->right = createNode(value);
    }
    else
    {
        insert(root->left, value);
    }
    return root;
}
Node* deleteNode(Node *root, int value)
{
    if (root == NULL)
    {
        return NULL;
    }
    if (root->data == value)
    {
        Node *deepest = findDeepest(root);
        if (root == deepest)
        {
            delete root;
            return NULL;
        }
        root->data = deepest->data;
        deleteDeepest(root, deepest);
        return root;
    }
    root->left = deleteNode(root->left, value);
    root->right = deleteNode(root->right, value);
    return root;
}
