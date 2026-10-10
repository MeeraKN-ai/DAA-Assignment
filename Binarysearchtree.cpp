#include <iostream>
using namespace std;
struct Node{
    int data;
    Node *left, *right;
};
Node* root = NULL;
Node* insert(Node* root, int value){
    if (root == NULL){
        Node* newNode = new Node;
        newNode->data = value;
        newNode->left = NULL;
        newNode->right = NULL;
        return newNode;
    }
    if (value < root->data)
        root->left = insert(root->left, value);
    else if (value > root->data)
        root->right = insert(root->right, value);
    else
        cout << "Duplicate value not allowed" << endl;
    return root;
}
Node* findMin(Node* root){
    while (root != NULL && root->left != NULL)
        root = root->left;
    return root;
}
Node* findMax(Node* root){
    while (root != NULL && root->right != NULL)
        root = root->right;
    return root;
}
Node* deleteNode(Node* root, int value){
    if (root == NULL){
        cout << "Value not found!" << endl;
        return NULL;
    }
    if (value < root->data)
        root->left = deleteNode(root->left, value);
    else if (value > root->data)
        root->right = deleteNode(root->right, value);
    else{
        if (root->left == NULL){
            Node* temp = root->right;
            delete root;
            return temp;
        }
        else if (root->right == NULL){
            Node* temp = root->left;
            delete root;
            return temp;
        }
        Node* temp = findMin(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}
bool search(Node* root, int value){
    if (root == NULL)
        return false;
    if (root->data == value)
        return true;
    if (value < root->data)
        return search(root->left, value);
    return search(root->right, value);
}
void inorder(Node* root){
    if (root != NULL){
        inorder(root->left);
        cout << root->data << " ";
        inorder(root->right);
    }
}
int main(){
    int choice, value;
    Node* temp;
    cout << "\n--- BINARY SEARCH TREE MENU ---" << endl;
    cout << "1. Insertion" << endl;
    cout << "2. Deletion" << endl;
    cout << "3. Searching" << endl;
    cout << "4. Display (In-order)" << endl;
    cout << "5. Find minimum and maximum" << endl;
    cout << "6. Quit" << endl;
    do{
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice){
            case 1:
                cout << "Enter value to insert: ";
                cin >> value;
                root = insert(root, value);
      		  break;
            case 2:
                cout << "Enter value to delete: ";
                cin >> value;
                if (search(root, value)){
                    root = deleteNode(root, value);
                    cout << "Node deleted successfully" << endl;
                }
                else{
                    cout << "Value not found" << endl;
                }
                break;
            case 3:
                cout << "Enter value to search: ";
                cin >> value;
                if (search(root, value))
                    cout << "Value found" << endl;
                else
                    cout << "Value not found" << endl;
                break;
            case 4:
                if (root == NULL)
                    cout << "Tree is empty" << endl;
                else{
                    cout << "In-order traversal: ";
                    inorder(root);
                    cout << endl;
                }
                break;
            case 5:
                if (root == NULL)
                    cout << "Tree is empty" << endl;
                else{
                    temp = findMin(root);
                    cout << "Minimum value: "
                         << temp->data << endl;
                    temp = findMax(root);
                    cout << "Maximum value: "
                         << temp->data << endl;
                }
                break;
            case 6:
                cout << "Exiting program" << endl;
                break;
            default:
                cout << "Invalid choice" << endl;
        }
    } while (choice != 6);
    return 0;
}
