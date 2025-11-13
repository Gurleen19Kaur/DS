#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Node {
public:
    int data;
    Node *left, *right;
    Node(int x) {
        data = x;
        left = NULL;
        right = NULL;
    }
};

int search(vector<int> &inorder, int value, int left, int right) {
    for (int i = left; i <= right; i++) {
        if (inorder[i] == value)
            return i;
    }
    return -1;
}

Node* buildTreeRecur(vector<int> &inorder, vector<int> &preorder,
                     int &preIndex, int left, int right) {
    if (left > right) return NULL;

    int rootVal = preorder[preIndex++];
    Node* root = new Node(rootVal);

    int idx = search(inorder, rootVal, left, right);

    root->left = buildTreeRecur(inorder, preorder, preIndex, left, idx - 1);
    root->right = buildTreeRecur(inorder, preorder, preIndex, idx + 1, right);

    return root;
}

Node* buildTree(vector<int> &inorder, vector<int> &preorder) {
    int preIndex = 0;
    return buildTreeRecur(inorder, preorder, preIndex, 0, inorder.size() - 1);
}

void levelOrder(Node* root) {
    if (root == NULL) return;

    queue<Node*> q;
    q.push(root);

    while (!q.empty()) {
        int size = q.size();

        while (size--) {
            Node* node = q.front();
            q.pop();

            if (node == NULL) {
                cout << "X ";
                continue;
            }

            cout << node->data << " ";
            q.push(node->left);
            q.push(node->right);
        }

        cout << "\n";
    }
}

int main() {
    vector<int> inorder;
    inorder.push_back(3);
    inorder.push_back(1);
    inorder.push_back(4);
    inorder.push_back(0);
    inorder.push_back(5);
    inorder.push_back(2);

    vector<int> preorder;
    preorder.push_back(0);
    preorder.push_back(1);
    preorder.push_back(3);
    preorder.push_back(4);
    preorder.push_back(2);
    preorder.push_back(5);

    Node* root = buildTree(inorder, preorder);
    levelOrder(root);

    return 0;
}


