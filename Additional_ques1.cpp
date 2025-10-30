// Split circular linked list into two halves
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

    void display() {
        if (!last) {
            cout << "List is empty.\n";
            return;
        }

        Node* temp = last->next;
        do {
            cout << temp->data << " ";
            temp = temp->next;
        } while (temp != last->next);
        cout << endl;
    }


    void split(CircularLinkedList &firstHalf, CircularLinkedList &secondHalf) {
        if (!last) return;

        Node* slow = last->next;
        Node* fast = last->next;

    
        while (fast->next != last->next && fast->next->next != last->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        
        Node* head1 = last->next;
        Node* head2 = slow->next;

        // First half circular
        slow->next = head1;
        Node* temp = head2;
        while (temp->next != last->next)
            temp = temp->next;
        // Second half circular
        temp->next = head2;

       
        firstHalf.last = slow;      
        secondHalf.last = temp;    
    }
};

int main() {
    CircularLinkedList cll;
    CircularLinkedList firstHalf, secondHalf;
    int n, val;

    cout << "Enter number of nodes: ";
    cin >> n;

    cout << "Enter " << n << " node values:\n";
    for (int i = 0; i < n; i++) {
        cin >> val;
        cll.insert(val);
    }

    cout << "\nOriginal Circular Linked List: ";
    cll.display();

    cll.split(firstHalf, secondHalf);

    cout << "\nFirst Half: ";
    firstHalf.display();

    cout << "Second Half: ";
    secondHalf.display();

    return 0;
}

