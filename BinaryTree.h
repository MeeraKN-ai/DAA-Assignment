#ifndef BINARYTREE_H
#define BINARYTREE_H
struct Node
{
    int data;
    Node *left;
    Node *right;
};
Node* createNode(int value);
Node* insert(Node *root, int value);
Node* deleteNode(Node *root, int value);
#endif
