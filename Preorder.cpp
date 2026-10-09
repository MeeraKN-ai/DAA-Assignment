#include <iostream>
using namespace std;
struct Node
{
    int data;
    Node *left;
    Node *right;
};
Node *root = NULL;
void insertNode(int value)
{
    Node *newNode = new Node;
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
    if (root == NULL)
    {
        root = newNode;
        return;
    }
    Node *queue[1000];
    int front = 0, rear = 0;
    queue[rear++] = root;


    while (front < rear)
    {
        Node *temp = queue[front++];


        if (temp->left == NULL)
        {
            temp->left = newNode;
            return;
        }
        else
        {
            queue[rear++] = temp->left;
        }


        if (temp->right == NULL)
        {
            temp->right = newNode;
            return;
        }
        else
        {
            queue[rear++] = temp->right;
        }
    }
}
void preorderRecursive(Node *temp)
{
    if (temp == NULL)
        return;


    cout << temp->data << " ";
    preorderRecursive(temp->left);
    preorderRecursive(temp->right);
}
void preorderIterative()
{
    if (root == NULL)
    {
        cout << "Tree is empty";
        return;
    }
    Node *stack[1000];
    int top = -1;
    stack[++top] = root;
    while (top != -1)
    {
        Node *temp = stack[top--];
        cout << temp->data << " ";
        if (temp->right != NULL)
            stack[++top] = temp->right;
        if (temp->left != NULL)
            stack[++top] = temp->left;
    }
}
int main()
{
    int choice, value;
    cout << "\n\n1. Insert a node";
    cout << "\n2. Pre-order traversal using recursion";
    cout << "\n3. Pre-order traversal without recursion";
    cout << "\n4. Quit";
    do
    {
        cout << "\nEnter your choice: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            cout << "Enter value: ";
            cin >> value;
            insertNode(value);
            break;
        case 2:
            if (root == NULL)
                cout << "Tree is empty";
            else
            {
                cout << "Pre-order traversal: ";
                preorderRecursive(root);
            }
            break;
        case 3:
            cout << "Pre-order traversal: ";
            preorderIterative();
            break;
        case 4:
            cout << "Exiting program";
            break;
        default:
            cout << "Invalid choice";
        }
    } while (choice != 4);
    return 0;
}
