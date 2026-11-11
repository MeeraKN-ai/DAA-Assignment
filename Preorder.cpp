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
void preorderRecursive(Node *temp){
    if (temp == NULL)
        return;
    cout << temp->data << " ";
    preorderRecursive(temp->left);
    preorderRecursive(temp->right);
}
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
void preorderIterative() {
    if (root == NULL) {
        cout << "Tree is empty";
        return;
    }
    stack<Node*> s;
    s.push(root);
    while (!s.empty()) {
        Node *temp = s.top();
        s.pop();
        cout << temp->data << " ";
        if (temp->right != NULL)
            s.push(temp->right);
        if (temp->left != NULL)
            s.push(temp->left);
    }
}
int main(){
    int choice, value;
    cout << "\n\n1. Insert a node";
    cout << "\n2. Pre-order traversal using recursion";
    cout << "\n3. Pre-order traversal without recursion";
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
                cout << "Pre-order traversal (recursive): ";
                preorderRecursive(root);
            }break;
        case 3:cout << "Pre-order traversal (iterative): ";preorderIterative();break;
        case 4:cout << "Exiting program";break;
        default:cout << "Invalid choice";
        }
    } while (choice != 4);
   return 0;
}
