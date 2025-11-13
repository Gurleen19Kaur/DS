#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;
    Node(int v) : data(v), left(NULL), right(NULL) {}
};

Node* insertBST(Node* root, int val) {
    if (root == NULL) return new Node(val);
    if (val < root->data)
        root->left = insertBST(root->left, val);
    else
        root->right = insertBST(root->right, val);
    return root;
}

void bstToDllInorder(Node* root, Node*& head, Node*& prev) {
    if (!root) return;
    bstToDllInorder(root->left, head, prev);
    if (prev == NULL) {
        head = root;
    } else {
        prev->right = root;
        root->left = prev;
    }
    prev = root;
    bstToDllInorder(root->right, head, prev);
}

Node* bstToDll(Node* root) {
    Node* head = NULL;
    Node* prev = NULL;
    bstToDllInorder(root, head, prev);
    return head;
}

Node* mergeTwoDlls(Node* a, Node* b) {
    if (!a) return b;
    if (!b) return a;

    Node* head = NULL;
    Node* tail = NULL;

    while (a != NULL && b != NULL) {
        Node* chosen = NULL;
        if (a->data <= b->data) {
            chosen = a;
            a = a->right;
        } else {
            chosen = b;
            b = b->right;
        }

        chosen->left = chosen->right = NULL;

        if (!head) {
            head = tail = chosen;
        } else {
            tail->right = chosen;
            chosen->left = tail;
            tail = chosen;
        }
    }

    Node* rem = (a != NULL) ? a : b;
    while (rem != NULL) {
        Node* next = rem->right;
        rem->left = rem->right = NULL;
        tail->right = rem;
        rem->left = tail;
        tail = rem;
        rem = next;
    }

    return head;
}

void printDll(Node* head) {
    Node* cur = head;
    while (cur) {
        cout << cur->data;
        if (cur->right) cout << " ";
        cur = cur->right;
    }
    cout << "\n";
}


int main() {
    Node* root1 = NULL;
    root1 = insertBST(root1, 20);
    root1 = insertBST(root1, 10);
    root1 = insertBST(root1, 30);

    Node* root2 = NULL;
    root2 = insertBST(root2, 50);
    root2 = insertBST(root2, 5);
    root2 = insertBST(root2, 70);

    Node* dll1 = bstToDll(root1);
    Node* dll2 = bstToDll(root2);

    Node* merged = mergeTwoDlls(dll1, dll2);

    cout << "Merged DLL : ";
    printDll(merged);


    return 0;
}

