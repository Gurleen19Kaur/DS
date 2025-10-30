#include <iostream>
using namespace std;

class DoublyNode {
public:
    int data;
    DoublyNode* prev;
    DoublyNode* next;
    DoublyNode* random;
    DoublyNode(int val) { data = val; prev = next = random = NULL; }
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

    void setRandom(DoublyNode* fromNode, DoublyNode* toNode) {
        if (fromNode) fromNode->random = toNode;
    }

    void display() {
        DoublyNode* temp = head;
        cout << "List (data, random->data): ";
        while (temp) {
            cout << "(" << temp->data << ", ";
            if (temp->random) cout << temp->random->data;
            else cout << "NULL";
            cout << ") ";
            temp = temp->next;
        }
        cout << endl;
    }

    bool isValidNode(DoublyNode* node) {
        DoublyNode* temp = head;
        while (temp) {
            if (temp == node) return true;
            temp = temp->next;
        }
        return false;
    }

    void fixRandomPointer() {
        if (!head) return;
        DoublyNode* temp = head;
        while (temp) {
            if (temp->random && !isValidNode(temp->random)) {
                temp->random = temp->next;
                break;
            }
            temp = temp->next;
        }
    }

    DoublyNode* getHead() { return head; }
};

int main() {
    DoublyLinkedList dll;

    dll.insert(10);
    dll.insert(20);
    dll.insert(30);
    dll.insert(40);

    DoublyNode* wrongNode = new DoublyNode(999);

    dll.setRandom(dll.getHead(), dll.getHead()->next);
    dll.setRandom(dll.getHead()->next, dll.getHead()->next->next);
    dll.setRandom(dll.getHead()->next->next, wrongNode);
    dll.setRandom(dll.getHead()->next->next->next, NULL);

    cout << "Before fixing random pointers:\n";
    dll.display();

    dll.fixRandomPointer();

    cout << "After fixing random pointers:\n";
    dll.display();

    delete wrongNode;

    return 0;
}





