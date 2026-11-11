#include <iostream>
#include <queue>
#include <stack>
using namespace std;
struct Node{
    int data;
    Node *left;
    Node *right;
};
Node *root = NULL;
void insertNode(int value) {
    Node *newNode = new Node;
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
    if (root == NULL) {
        root = newNode;
        return;
    }
    queue<Node*> q;
    q.push(root);
    while (!q.empty()) {
        Node *temp = q.front();
        q.pop();
        if (temp->left == NULL) {
            temp->left = newNode;
            return;
        }
        else {
            q.push(temp->left);
        }
        if (temp->right == NULL) {
            temp->right = newNode;
            return;
        }
        else {
            q.push(temp->right);
        }
    }
}
void postorderIterative() {
    if (root == NULL) {
        cout << "Tree is empty";
        return;
    }
    stack<Node*> stack1;
    stack<Node*> stack2;
    stack1.push(root);
    while (!stack1.empty()) {
        Node *temp = stack1.top();
        stack1.pop();
        stack2.push(temp);
        if (temp->left != NULL)
            stack1.push(temp->left);
        if (temp->right != NULL)
            stack1.push(temp->right);
    }
    while (!stack2.empty()) {
        cout << stack2.top()->data << " ";
        stack2.pop();
    }
}
void postorderRecursive(Node *temp){
    if (temp == NULL)
        return;
    postorderRecursive(temp->left);
    postorderRecursive(temp->right);
    cout << temp->data << " ";
}
int main(){
    int choice, value;
    cout << "\n\n1. Insert a node";
    cout << "\n2. Post-order traversal using recursion";
    cout << "\n3. Post-order traversal without recursion";
    cout << "\n4. Quit";
    do{
        cout << "\nEnter your choice: ";
        cin >> choice;
        switch (choice){
        case 1:
            cout << "Enter value: ";
            cin >> value;
            insertNode(value);break;
        case 2:
            if (root == NULL)
                cout << "Tree is empty";
            else{
                cout << "Post-order traversal (recursive): ";
                postorderRecursive(root);
            }break;
        case 3:cout << "Post-order traversal (iterative): ";postorderIterative();break;
        case 4:cout << "Exiting program";break;
        default:cout << "Invalid choice";
        }
    } while (choice != 4);
    return 0;
}
