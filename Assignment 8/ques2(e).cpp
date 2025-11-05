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

Node* maximum(Node* root) {
    while (root && root->right != NULL)
        root = root->right;
    return root;
}

Node* inorderPredecessor(Node* root, Node* target) {
    if (target->left != NULL)
        return maximum(target->left);

    Node* predecessor = NULL;
    Node* ancestor = root;

    while (ancestor != target) {
        if (target->data > ancestor->data) {
            predecessor = ancestor;
            ancestor = ancestor->right;
        } else {
            ancestor = ancestor->left;
        }
    }
    return predecessor;
}

Node* search(Node* root, int key) {
    if (root == NULL || root->data == key)
        return root;
    if (key < root->data)
        return search(root->left, key);
    else
        return search(root->right, key);
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

    cout << "\nEnter the node value to find its in-order predecessor: ";
    cin >> key;

    Node* target = search(root, key);
    if (target == NULL) {
        cout << "Node not found in the BST." << endl;
    } else {
        Node* pred = inorderPredecessor(root, target);
        if (pred)
            cout << "In-order predecessor of " << key << " is: " << pred->data << endl;
        else
            cout << "In-order predecessor of " << key << " does not exist." << endl;
    }

    return 0;
}

