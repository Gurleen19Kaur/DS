#include <iostream>
using namespace std;


// Doubly Linked List

class DoublyLinkedList {
    struct Node {
        int data;
        Node *prev, *next;
        Node(int val) : data(val), prev(NULL), next(NULL) {}
    };
    Node *head;

public:
    DoublyLinkedList() : head(NULL) {}

    void insertAtBeginning(int val) {
        Node *newNode = new Node(val);
        if (!head) head = newNode;
        else {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
    }

    void insertAtEnd(int val) {
        Node *newNode = new Node(val);
        if (!head) { head = newNode; return; }
        Node *temp = head;
        while (temp->next) temp = temp->next;
        temp->next = newNode;
        newNode->prev = temp;
    }

    void insertAfter(int key, int val) {
        Node *temp = head;
        while (temp && temp->data != key) temp = temp->next;
        if (!temp) { cout << "Node " << key << " not found.\n"; return; }
        Node *newNode = new Node(val);
        newNode->next = temp->next;
        newNode->prev = temp;
        if (temp->next) temp->next->prev = newNode;
        temp->next = newNode;
    }

    void insertBefore(int key, int val) {
        Node *temp = head;
        if (!head) { cout << "List is empty.\n"; return; }
        if (head->data == key) {
            insertAtBeginning(val);
            return;
        }
        while (temp && temp->data != key) temp = temp->next;
        if (!temp) { cout << "Node " << key << " not found.\n"; return; }
        Node *newNode = new Node(val);
        newNode->next = temp;
        newNode->prev = temp->prev;
        temp->prev->next = newNode;
        temp->prev = newNode;
    }

    void deleteNode(int key) {
        Node *temp = head;
        while (temp && temp->data != key) temp = temp->next;
        if (!temp) { cout << "Node " << key << " not found.\n"; return; }

        if (temp->prev) temp->prev->next = temp->next;
        else head = temp->next;  // Deleting head

        if (temp->next) temp->next->prev = temp->prev;

        delete temp;
        cout << "Node " << key << " deleted.\n";
    }

    void search(int key) {
        Node *temp = head;
        int pos = 1;
        while (temp) {
            if (temp->data == key) {
                cout << "Node " << key << " found at position " << pos << ".\n";
                return;
            }
            temp = temp->next;
            pos++;
        }
        cout << "Node " << key << " not found.\n";
    }

    void display() {
        Node *temp = head;
        if (!temp) { cout << "List is empty.\n"; return; }
        cout << "Doubly Linked List: ";
        while (temp) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};


// Circular Linked List

class CircularLinkedList {
    struct Node {
        int data;
        Node *next;
        Node(int val) : data(val), next(NULL) {}
    };
    Node *last;

public:
    CircularLinkedList() : last(NULL) {}

    void insertAtBeginning(int val) {
        Node *newNode = new Node(val);
        if (!last) {
            last = newNode;
            last->next = last;
        } else {
            newNode->next = last->next;
            last->next = newNode;
        }
    }

    void insertAtEnd(int val) {
        Node *newNode = new Node(val);
        if (!last) {
            last = newNode;
            last->next = last;
        } else {
            newNode->next = last->next;
            last->next = newNode;
            last = newNode;
        }
    }

    void insertAfter(int key, int val) {
        if (!last) { cout << "List is empty.\n"; return; }
        Node *temp = last->next;
        do {
            if (temp->data == key) {
                Node *newNode = new Node(val);
                newNode->next = temp->next;
                temp->next = newNode;
                if (temp == last) last = newNode;
                return;
            }
            temp = temp->next;
        } while (temp != last->next);
        cout << "Node " << key << " not found.\n";
    }

    void insertBefore(int key, int val) {
        if (!last) { cout << "List is empty.\n"; return; }
        Node *temp = last->next, *prev = last;
        do {
            if (temp->data == key) {
                Node *newNode = new Node(val);
                newNode->next = temp;
                prev->next = newNode;
                if (temp == last->next) last->next = newNode;
                return;
            }
            prev = temp;
            temp = temp->next;
        } while (temp != last->next);
        cout << "Node " << key << " not found.\n";
    }

    void deleteNode(int key) {
        if (!last) { cout << "List is empty.\n"; return; }
        Node *temp = last->next, *prev = last;
        do {
            if (temp->data == key) {
                if (temp == last && temp->next == last) {
                    delete temp;
                    last = NULL;
                } else {
                    prev->next = temp->next;
                    if (temp == last) last = prev;
                    if (temp == last->next) last->next = temp->next;
                    delete temp;
                }
                cout << "Node " << key << " deleted.\n";
                return;
            }
            prev = temp;
            temp = temp->next;
        } while (temp != last->next);
        cout << "Node " << key << " not found.\n";
    }

    void search(int key) {
        if (!last) { cout << "List is empty.\n"; return; }
        Node *temp = last->next;
        int pos = 1;
        do {
            if (temp->data == key) {
                cout << "Node " << key << " found at position " << pos << ".\n";
                return;
            }
            temp = temp->next;
            pos++;
        } while (temp != last->next);
        cout << "Node " << key << " not found.\n";
    }

    void display() {
        if (!last) { cout << "List is empty.\n"; return; }
        Node *temp = last->next;
        cout << "Circular Linked List: ";
        do {
            cout << temp->data << " ";
            temp = temp->next;
        } while (temp != last->next);
        cout << endl;
    }
};

// -------------------------------
// Main Menu
// -------------------------------
int main() {
    DoublyLinkedList dll;
    CircularLinkedList cll;
    int choice, listType;

    do {
        cout << "\n--- Linked List Menu ---\n";
        cout << "1. Doubly Linked List\n";
        cout << "2. Circular Linked List\n";
        cout << "3. Exit\n";
        cout << "Enter your choice: ";
        cin >> listType;

        if (listType == 3) break;

        cout << "Operations:\n";
        cout << "1. Insert at beginning\n2. Insert at end\n3. Insert after a node\n";
        cout << "4. Insert before a node\n5. Delete a node\n6. Search a node\n7. Display\n8. Back to main menu\n";

        while (true) {
            cout << "\nEnter operation: ";
            cin >> choice;
            if (choice == 8) break;

            int val, key;
            switch (choice) {
                case 1:
                    cout << "Enter value: "; cin >> val;
                    (listType == 1) ? dll.insertAtBeginning(val) : cll.insertAtBeginning(val);
                    break;
                case 2:
                    cout << "Enter value: "; cin >> val;
                    (listType == 1) ? dll.insertAtEnd(val) : cll.insertAtEnd(val);
                    break;
                case 3:
                    cout << "Enter key and value: "; cin >> key >> val;
                    (listType == 1) ? dll.insertAfter(key, val) : cll.insertAfter(key, val);
                    break;
                case 4:
                    cout << "Enter key and value: "; cin >> key >> val;
                    (listType == 1) ? dll.insertBefore(key, val) : cll.insertBefore(key, val);
                    break;
                case 5:
                    cout << "Enter value to delete: "; cin >> val;
                    (listType == 1) ? dll.deleteNode(val) : cll.deleteNode(val);
                    break;
                case 6:
                    cout << "Enter value to search: "; cin >> val;
                    (listType == 1) ? dll.search(val) : cll.search(val);
                    break;
                case 7:
                    (listType == 1) ? dll.display() : cll.display();
                    break;
                default:
                    cout << "Invalid operation.\n";
            }
        }
    } while (listType != 3);

    cout << "Program terminated.\n";
    return 0;
}

