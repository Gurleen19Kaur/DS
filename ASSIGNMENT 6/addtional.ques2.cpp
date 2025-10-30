#include <iostream>
using namespace std;

int countOnes(int n) {
    int count = 0;
    while (n) {
        count += (n & 1);
        n >>= 1;
    }
    return count;
}

bool hasEvenParity(int n) {
    return countOnes(n) % 2 == 0;
}

class DoublyNode {
public:
    int data;
    DoublyNode* prev;
    DoublyNode* next;
    DoublyNode(int val) { data = val; prev = next = NULL; }
};

class DoublyLinkedList {
private:
    DoublyNode* head;
public:
    DoublyLinkedList() { head = NULL; }

    void insert(int val) {
        DoublyNode* newNode = new DoublyNode(val);
        if (!head) { head = newNode; return; }
        DoublyNode* temp = head;
        while (temp->next) temp = temp->next;
        temp->next = newNode;
        newNode->prev = temp;
    }

    void removeEvenParity() {
        DoublyNode* temp = head;
        while (temp) {
            DoublyNode* nextNode = temp->next;
            if (hasEvenParity(temp->data)) {
                if (temp->prev) temp->prev->next = temp->next;
                else head = temp->next;
                if (temp->next) temp->next->prev = temp->prev;
                delete temp;
            }
            temp = nextNode;
        }
    }

    void display() {
        DoublyNode* temp = head;
        cout << "Doubly Linked List: ";
        while (temp) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

class CSNode {
public:
    int data;
    CSNode* next;
    CSNode(int val) { data = val; next = NULL; }
};

class CircularSinglyLinkedList {
private:
    CSNode* last;
public:
    CircularSinglyLinkedList() { last = NULL; }

    void insert(int val) {
        CSNode* newNode = new CSNode(val);
        if (!last) { last = newNode; last->next = last; return; }
        newNode->next = last->next;
        last->next = newNode;
        last = newNode;
    }

    void removeEvenParity() {
        if (!last) return;

        CSNode* curr = last->next;
        CSNode* prev = last;
        CSNode* head = last->next;
        bool firstPass = true;

        while (curr != head || firstPass) {
            firstPass = false;
            if (hasEvenParity(curr->data)) {
                if (curr == last) last = prev;
                if (curr == head) head = head->next;

                prev->next = curr->next;
                CSNode* temp = curr;
                curr = curr->next;
                delete temp;

                if (!last) return;
            } else {
                prev = curr;
                curr = curr->next;
            }
        }

        if (last == last->next && hasEvenParity(last->data)) {
            delete last;
            last = NULL;
        }
    }

    void display() {
        if (!last) { cout << "Circular List is empty.\n"; return; }
        CSNode* temp = last->next;
        cout << "Circular List: ";
        do {
            cout << temp->data << " ";
            temp = temp->next;
        } while (temp != last->next);
        cout << endl;
    }
};

int main() {
    DoublyLinkedList dll;
    CircularSinglyLinkedList cll;

    int n1, n2, val;

    cout << "Enter the number of nodes in Doubly Linked List: ";
    cin >> n1;
    cout << "Enter " << n1 << " integers for Doubly Linked List:\n";
    for (int i = 0; i < n1; i++) { cin >> val; dll.insert(val); }

    cout << "Enter the number of nodes in Circular Singly Linked List: ";
    cin >> n2;
    cout << "Enter " << n2 << " integers for Circular Singly Linked List:\n";
    for (int i = 0; i < n2; i++) { cin >> val; cll.insert(val); }

    cout << "\nOriginal Lists:\n";
    dll.display();
    cll.display();

    dll.removeEvenParity();
    cll.removeEvenParity();

    cout << "\nAfter removing nodes with even parity:\n";
    dll.display();
    cll.display();

    return 0;
}



