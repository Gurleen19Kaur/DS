#include <iostream>
#include <queue>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;
    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

class Solution {
public:
    Node* buildTree(int arr[], int n) {
        if (n == 0 || arr[0] == -1)
            return NULL;

        Node* root = new Node(arr[0]);
        queue<Node*> q;
        q.push(root);
        int i = 1;

        while (!q.empty() && i < n) {
            Node* curr = q.front();
            q.pop();

            // left child
            if (i < n && arr[i] != -1) {
                curr->left = new Node(arr[i]);
                q.push(curr->left);
            }
            i++;

            // right child
            if (i < n && arr[i] != -1) {
                curr->right = new Node(arr[i]);
                q.push(curr->right);
            }
            i++;
        }
        return root;
    }

    void rightView(Node* root) {
        if (root == NULL)
            return;

        queue<Node*> q;
        q.push(root);

        while (!q.empty()) {
            int size = q.size();
            for (int i = 0; i < size; i++) {
                Node* curr = q.front();
                q.pop();

                if (curr->left)
                    q.push(curr->left);
                if (curr->right)
                    q.push(curr->right);

                // print last node of each level
                if (i == size - 1)
                    cout << curr->data << " ";
            }
        }
    }
};

int main() {
    int T;
    cin >> T;

    while (T--) {
        int n;
        cin >> n;
        int arr[1000]; // assuming max 1000 nodes per test
        for (int i = 0; i < n; i++)
            cin >> arr[i];

        Solution s;
        Node* root = s.buildTree(arr, n);
        s.rightView(root);
        cout << endl;
    }
    return 0;
}

