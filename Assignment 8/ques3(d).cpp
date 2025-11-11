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
    return root;
}

int minDepth(Node* root) {
    if (root == NULL)
        return 0;
    if (root->left == NULL)
        return 1 + minDepth(root->right);
    if (root->right == NULL)
        return 1 + minDepth(root->left);
    return 1 + min(minDepth(root->left), minDepth(root->right));
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
    int n, d;
    cout << "Enter number of elements to insert: ";
    cin >> n;
    for (int i = 0; i < n; i++) {
        cout << "Enter value " << i + 1 << ": ";
        cin >> d;
        root = insert(root, d);
    }
    cout << "\nInorder traversal of BST: ";
    inorder(root);
    cout << endl;
    int depthInNodes = minDepth(root);
    int depthInEdges = depthInNodes - 1;
    cout << "\nMinimum depth (in edges) of the BST is: " << depthInEdges << endl;
    return 0;
}

