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

class CircularLinkedList {
private:
    Node* last;

public:
    CircularLinkedList() {
        last = NULL;
    }

    // Insert at end
    void insert(int val) {
        Node* newNode = new Node(val);
        if (last == NULL) {
            last = newNode;
            last->next = last;
        } else {
            newNode->next = last->next;
            last->next = newNode;
            last = newNode;
        }
    }

    // Function to find the size of the circular linked list
    int getSize() {
        if (last == NULL)
            return 0;

        int count = 0;
        Node* temp = last->next; // Head node
        do {
            count++;
            temp = temp->next;
        } while (temp != last->next);

        return count;
    }

    void display() {
        if (last == NULL) {
            cout << "List is empty.\n";
            return;
        }

        Node* temp = last->next;
        cout << "Circular Linked List: ";
        do {
            cout << temp->data << " ";
            temp = temp->next;
        } while (temp != last->next);
        cout << endl;
    }
};

int main() {
    CircularLinkedList cll;
    int n, val;

    cout << "Enter number of nodes: ";
    cin >> n;

    cout << "Enter " << n << " values:\n";
    for (int i = 0; i < n; i++) {
        cin >> val;
        cll.insert(val);
    }

    cll.display();
    cout << "Size of Circular Linked List: " << cll.getSize() << endl;

    return 0;
}

