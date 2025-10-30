#include <iostream>
using namespace std;

class Node {
public:
    char data;
    Node* prev;
    Node* next;

    Node(char ch) {
        data = ch;
        prev = NULL;
        next = NULL;
    }
};

class DoublyLinkedList {
private:
    Node* head;
    Node* tail;

public:
    DoublyLinkedList() {
        head = NULL;
        tail = NULL;
    }

    // Insert character at the end
    void insert(char ch) {
        Node* newNode = new Node(ch);
        if (head == NULL) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }

    // Display the linked list
    void display() {
        Node* temp = head;
        cout << "Doubly Linked List: ";
        while (temp != NULL) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    // Check if list is palindrome
    bool isPalindrome() {
        if (head == NULL) return true;

        Node* left = head;
        Node* right = tail;

        while (left != right && right->next != left) {
            if (left->data != right->data)
                return false;
            left = left->next;
            right = right->prev;
        }

        return true;
    }
};

int main() {
    DoublyLinkedList dll;
    int n;
    char ch;

    cout << "Enter number of characters: ";
    cin >> n;

    cout << "Enter characters one by one:\n";
    for (int i = 0; i < n; i++) {
        cin >> ch;
        dll.insert(ch);
    }

    dll.display();

    if (dll.isPalindrome())
        cout << "The Doubly Linked List is a Palindrome.\n";
    else
        cout << "The Doubly Linked List is NOT a Palindrome.\n";

    return 0;
}

