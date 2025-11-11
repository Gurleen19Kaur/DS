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

int maxDepth(Node* root) {
    if (root == NULL)
        return 0;
    int leftDepth = maxDepth(root->left);
    int rightDepth = maxDepth(root->right);
    return 1 + max(leftDepth, rightDepth);
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
    int depthInNodes = maxDepth(root);
    int depthInEdges = depthInNodes - 1;
    cout << "\nMaximum depth (in edges): " << depthInEdges << endl;
    return 0;
}

