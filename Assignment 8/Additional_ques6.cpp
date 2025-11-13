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
        left = right = NULL;
    }
};

int search(vector<int> &inorder, int value, int left, int right) {
    for (int i = left; i <= right; i++) {
        if (inorder[i] == value)
            return i;
    }
    return -1;
}

Node* buildTreeRecur(vector<int> &inorder, vector<int> &postorder,
                     int &postIndex, int left, int right) {

    if (left > right) return NULL;

    int rootVal = postorder[postIndex];
    postIndex--;
    Node* root = new Node(rootVal);

    int idx = search(inorder, rootVal, left, right);

    root->right = buildTreeRecur(inorder, postorder, postIndex, idx + 1, right);
    root->left  = buildTreeRecur(inorder, postorder, postIndex, left, idx - 1);

    return root;
}

Node* buildTree(vector<int> &inorder, vector<int> &postorder) {
    int postIndex = postorder.size() - 1;
    return buildTreeRecur(inorder, postorder, postIndex, 0, inorder.size() - 1);
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
                cout << "N ";
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

    vector<int> postorder;
    postorder.push_back(3);
    postorder.push_back(4);
    postorder.push_back(1);
    postorder.push_back(5);
    postorder.push_back(2);
    postorder.push_back(0);

    Node* root = buildTree(inorder, postorder);

    levelOrder(root);

    return 0;
}

