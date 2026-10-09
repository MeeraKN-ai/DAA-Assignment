#include <iostream>
using namespace std;
struct Node
{
    int data;
    Node *left, *right;
};
Node *root = NULL;
Node* createNode(int value)
{
    Node *newNode = new Node;
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}
void insertNode(int value)
{
    Node *newNode = createNode(value);
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
void displayLevelOrder()
{
    if (root == NULL)
    {
        cout << "Tree is empty!" << endl;
        return;
    }
    Node *queue[1000];
    int front = 0, rear = 0;
    queue[rear++] = root;
    cout << "Level-order traversal: ";
    while (front < rear)
    {
        Node *temp = queue[front++];
        cout << temp->data << " ";
        if (temp->left != NULL)
            queue[rear++] = temp->left;
        if (temp->right != NULL)
            queue[rear++] = temp->right;
    }
    cout << endl;
}
bool searchNode(int value)
{
    if (root == NULL)
        return false;
    Node *queue[1000];
    int front = 0, rear = 0;
    queue[rear++] = root;
    while (front < rear)
    {
        Node *temp = queue[front++];
        if (temp->data == value)
            return true;
        if (temp->left != NULL)
            queue[rear++] = temp->left;
        if (temp->right != NULL)
            queue[rear++] = temp->right;
    }
    return false;
}
int height(Node *temp)
{
    if (temp == NULL)
        return 0;
    int leftHeight = height(temp->left);
    int rightHeight = height(temp->right);
    if (leftHeight > rightHeight)
        return leftHeight + 1;
    else
        return rightHeight + 1;
}
int countNodes(Node *temp)
{
    if (temp == NULL)
        return 0;
    return 1 + countNodes(temp->left)
             + countNodes(temp->right);
}
int main()
{
    int choice, value;
    cout << "\n--- BINARY TREE MENU ---" << endl;
    cout << "1. Insert a node" << endl;
    cout << "2. Display tree (Level-order)" << endl;
    cout << "3. Search for a value" << endl;
    cout << "4. Find height of tree" << endl;
    cout << "5. Count number of nodes" << endl;
    cout << "6. Quit" << endl;
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
                displayLevelOrder();
                break;
            case 3:
                cout << "Enter value to search: ";
                cin >> value;
                if (searchNode(value))
                    cout << "Value found!" << endl;
                else
                    cout << "Value not found!" << endl;
                break;
            case 4:
                cout << "Height of tree: "
                     << height(root) << endl;
                break;
            case 5:
                cout << "Number of nodes: "
                     << countNodes(root) << endl;
                break;
            case 6:
                cout << "Exiting program." << endl;
                break;
            default:
                cout << "Invalid choice!" << endl;
        }
    } while (choice != 6);
    return 0;
}
