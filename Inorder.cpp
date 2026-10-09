#include <iostream>
using namespace std;
struct Node
{
    int data;
    Node *left, *right;
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
void inorderRecursive(Node *temp)
{
    if (temp != NULL)
    {
        inorderRecursive(temp->left);
        cout << temp->data << " ";
        inorderRecursive(temp->right);
    }
}
void inorderIterative()
{
    Node *stack[1000];
    int top = -1;
    Node *current = root;
    while (current != NULL || top != -1)
    {
        while (current != NULL)
        {
            stack[++top] = current;
            current = current->left;
        }
        current = stack[top--];
        cout << current->data << " ";
        current = current->right;
    }
}
int main()
{
    int choice, value;
    cout << "\n--- BINARY TREE TRAVERSAL MENU ---" << endl;
    cout << "1. Insert a node" << endl;
    cout << "2. In-order traversal (Recursive)" << endl;
    cout << "3. In-order traversal (Iterative)" << endl;
    cout << "4. Quit" << endl;
    do
    {
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice)
        {
            case 1:
                cout << "Enter value: ";
                cin >> value;
                insertNode(value);
                cout << "Node inserted successfully!" << endl;
                break;
            case 2:
                if (root == NULL)
                    cout << "Tree is empty!" << endl;
                else
                {
                    cout << "In-order traversal: ";
                    inorderRecursive(root);
                    cout << endl;
                }
                break;
            case 3:
                if (root == NULL)
                    cout << "Tree is empty!" << endl;
                else
                {
                    cout << "In-order traversal: ";
                    inorderIterative();
                    cout << endl;
                }
                break;
            case 4:
                cout << "Exiting program." << endl;
                break;
            default:
                cout << "Invalid choice!" << endl;
        }
    } while (choice != 4);
    return 0;
}
