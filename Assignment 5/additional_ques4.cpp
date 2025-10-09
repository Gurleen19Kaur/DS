#include<iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node(int data) {
        this->data = data;
        this->next = NULL;
    }
};

Node* rotateLeft(Node* head, int k) {
    if (head == NULL || head->next == NULL || k == 0)
        return head;

    int length = 1;
    Node* tail = head;
    while (tail->next != NULL) {
        tail = tail->next;
        length++;
    }

    k = k % length;
    if (k == 0)
        return head;

    Node* temp = head;
    int count = 1;
    while (count < k && temp != NULL) {
        temp = temp->next;
        count++;
    }

    Node* newHead = temp->next;
    temp->next = NULL;
    tail->next = head;

    return newHead;
}

void insertAtTail(Node*& head, int data) {
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

void printList(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    Node* head = NULL;

    for (int i = 1; i <= 6; i++) {
        insertAtTail(head, i);
    }

    cout << "Original List: ";
    printList(head);

    int k;
    cout << "Enter k: ";
    cin >> k;

    head = rotateLeft(head, k);

    cout << "List after left rotation by " << k << ": ";
    printList(head);

    if (head != NULL)
        cout << "New head after rotation: " << head->data << endl;

    return 0;
}
