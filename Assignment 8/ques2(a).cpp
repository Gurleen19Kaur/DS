#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int d) {
        data = d;
        left = right = NULL;
    }
};

Node* insert(Node* root, int d) {
    if (root == NULL)
        return new Node(d);

    if (d < root->data)
        root->left = insert(root->left, d);
    else if (d > root->data)
        root->right = insert(root->right, d);
    else
        cout << "Duplicate value " << d << " not allowed!" << endl;

    return root;
}

Node* searchRecursive(Node* root, int key) {
    if (root == NULL || root->data == key)
        return root;
    if (key < root->data)
        return searchRecursive(root->left, key);
    else
        return searchRecursive(root->right, key);
}

Node* searchIterative(Node* root, int key) {
    while (root != NULL) {
        if (key == root->data)
            return root;
        else if (key < root->data)
            root = root->left;
        else
            root = root->right;
    }
    return NULL;
}

void inorder(Node* root) {
    if (root != NULL) {
        inorder(root->left);
        cout << root->data << " ";
        inorder(root->right);
    }
}

int main() {
    Node* root = NULL;
    int n, d, key;

    cout << "Enter number of elements to insert: ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        cout << "Enter value " << i + 1 << ": ";
        cin >> d;
        root = insert(root, d);
    }

    cout << "\nInorder traversal: ";
    inorder(root);
    cout << endl;

    cout << "\nEnter the element to search: ";
    cin >> key;

    Node* res1 = searchRecursive(root, key);
    if (res1)
        cout << "Recursive Search: " << key << " found in BST." << endl;
    else
        cout << "Recursive Search: " << key << " not found in BST." << endl;

    Node* res2 = searchIterative(root, key);
    if (res2)
        cout << "Non-Recursive Search: " << key << " found in BST." << endl;
    else
        cout << "Non-Recursive Search: " << key << " not found in BST." << endl;

    return 0;
}
