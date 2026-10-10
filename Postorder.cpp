#include <iostream>
using namespace std;
struct Node{
    int data;
    Node *left;
    Node *right;
};
Node *root = NULL;
void insertNode(int value){
    Node *newNode = new Node;
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
    if (root == NULL){
        root = newNode;
        return;
    }
    Node *queue[1000];
    int front = 0, rear = 0;
    queue[rear++] = root;
    while (front < rear){
        Node *temp = queue[front++];
        if (temp->left == NULL){
            temp->left = newNode;
            return;
        }
        else{
            queue[rear++] = temp->left;
        }
        if (temp->right == NULL){
            temp->right = newNode;
            return;
        }
        else{
            queue[rear++] = temp->right;
        }
    }
}
void postorderRecursive(Node *temp){
    if (temp == NULL)
        return;
    postorderRecursive(temp->left);
    postorderRecursive(temp->right);
    cout << temp->data << " ";
}
void postorderIterative(){
    if (root == NULL){
        cout << "Tree is empty";
        return;
    }
    Node *stack1[1000];
    Node *stack2[1000];
    int top1 = -1, top2 = -1;
    stack1[++top1] = root;
    while (top1 != -1){
        Node *temp = stack1[top1--];
        stack2[++top2] = temp;
        if (temp->left != NULL)
            stack1[++top1] = temp->left;
        if (temp->right != NULL)
            stack1[++top1] = temp->right;
    }
    while (top2 != -1){
        cout << stack2[top2--]->data << " ";
    }
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
