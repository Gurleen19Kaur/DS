#include<iostream>
using namespace std;

class Node {
public:
    int data;
    Node *next;
    Node(int data) {
        this->data = data;
        this->next = NULL;
    }
};

Node* kReverse(Node* head, int k) {
    if (head == NULL)
        return NULL;

    Node* next = NULL;
    Node* curr = head;
    Node* prev = NULL;
    int count = 0;

    while (curr != NULL && count < k) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
        count++;
    }

    if (next != NULL) {
        head->next = kReverse(next, k);
    }

    return prev;
}

void printList(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

void insertAtTail(Node* &head, int data) {
    Node* newNode = new Node(data);
    if (head == NULL) {
        head = newNode;
        return;
    }
    Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}

int main() {
    Node* head = NULL;

    for (int i = 1; i <= 9; i++) {
        insertAtTail(head, i);
    }

    cout << "Original List: ";
    printList(head);

    int k;
    cout << "Enter value of k: ";
    cin >> k;

    head = kReverse(head, k);

    cout << "Reversed List in groups of " << k << ": ";
    printList(head);

    return 0;
}
