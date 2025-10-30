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

   
    void displayWithHeadRepeated() {
        if (last == NULL) {
            cout << "List is empty.\n";
            return;
        }

        Node* head = last->next;
        Node* temp = head;

        cout << "Circular Linked List: ";
        do {
            cout << temp->data << " ";
            temp = temp->next;
        } while (temp != head);

        // Repeat head node value at end
        cout << head->data << endl;
    }
};

int main() {
    CircularLinkedList cll;
    int n, val;

    cout << "Enter number of nodes: ";
    cin >> n;

    cout << "Enter " << n << " node values:\n";
    for (int i = 0; i < n; i++) {
        cin >> val;
        cll.insert(val);
    }

    cout << "\nOutput:\n";
    cll.displayWithHeadRepeated();

    return 0;
}

