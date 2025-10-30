#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = NULL;
    }
};

class LinkedList {
private:
    Node* head;

public:
    LinkedList() {
        head = NULL;
    }

    // Insert node at end
    void insert(int val) {
        Node* newNode = new Node(val);
        if (head == NULL) {
            head = newNode;
            return;
        }

        Node* temp = head;
        while (temp->next != NULL)
            temp = temp->next;

        temp->next = newNode;
    }

    // Make the list circular manually (for testing)
    void makeCircular() {
        if (head == NULL) return;
        Node* temp = head;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = head; // last node points to head
    }

    // Function to check if the linked list is circular
    bool isCircular() {
        if (head == NULL)
            return false;

        Node* temp = head->next;
        while (temp != NULL && temp != head) {
            temp = temp->next;
        }

        if (temp == head)
            return true;
        else
            return false;
    }

    void display() {
        Node* temp = head;
        int count = 0;
        cout << "Linked List (limited view): ";
        while (temp != NULL && count < 10) { // print up to 10 nodes to avoid infinite loop
            cout << temp->data << " ";
            temp = temp->next;
            count++;
        }
        cout << endl;
    }
};

int main() {
    LinkedList list;
    int n, val;
    char choice;

    cout << "Enter number of nodes: ";
    cin >> n;

    cout << "Enter " << n << " node values:\n";
    for (int i = 0; i < n; i++) {
        cin >> val;
        list.insert(val);
    }

    cout << "Make the list circular? (y/n): ";
    cin >> choice;

    if (choice == 'y' || choice == 'Y')
        list.makeCircular();

    cout << endl;
    list.display();

    if (list.isCircular())
        cout << "The linked list is CIRCULAR.\n";
    else
        cout << "The linked list is NOT circular.\n";

    return 0;
}


