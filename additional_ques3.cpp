#include <iostream>
using namespace std;

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

    void display() {
        DoublyNode* temp = head;
        while (temp) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    DoublyNode* reverseKGroupRecursive(DoublyNode* start, int k) {
        if (!start) return NULL;

        DoublyNode* current = start;
        DoublyNode* prev = NULL;
        DoublyNode* nextNode = NULL;
        int count = 0;

        // Reverse first k nodes
        while (current && count < k) {
            nextNode = current->next;
            current->next = prev;
            current->prev = nextNode;
            prev = current;
            current = nextNode;
            count++;
        }

        // Now nextNode points to (k+1)th node
        if (nextNode) {
            start->next = reverseKGroupRecursive(nextNode, k);
            if (start->next) start->next->prev = start;
        }

        return prev; // new head of this group
    }

    void reverseKGroup(int k) {
        head = reverseKGroupRecursive(head, k);
    }
};

int main() {
    DoublyLinkedList dll;
    int n, val, k;

    cout << "Enter number of nodes: ";
    cin >> n;
    cout << "Enter " << n << " values:\n";
    for (int i = 0; i < n; i++) {
        cin >> val;
        dll.insert(val);
    }

    cout << "Enter value of k: ";
    cin >> k;

    cout << "Original list: ";
    dll.display();

    dll.reverseKGroup(k);

    cout << "Reversed in groups of " << k << ": ";
    dll.display();

    return 0;
}

