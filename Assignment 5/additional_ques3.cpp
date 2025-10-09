#include<iostream>
using namespace std;

class Node {
public:
    int data;
    Node *next;

    Node(int data) {
        this->data = data;
        this->next = NULL;
    }
};

// Detects if loop exists using Floyd’s Algorithm
Node* floydDetectLoop(Node* head) {
    if(head == NULL)
        return NULL;

    Node* slow = head;
    Node* fast = head;

    while(slow != NULL && fast != NULL) {
        fast = fast->next;
        if(fast != NULL) {
            fast = fast->next;
        }
        slow = slow->next;

        if(slow == fast) {
            return slow; 
        }
    }
    return NULL;
}


Node* getStartingNode(Node* head) {
    if(head == NULL)
        return NULL;

    Node* intersection = floydDetectLoop(head);
    if(intersection == NULL)
        return NULL;

    Node* slow = head;
    while(slow != intersection) {
        slow = slow->next;
        intersection = intersection->next;
    }

    return slow;
}

Node* removeLoop(Node* head) {
    if(head == NULL)
        return NULL;

    Node* startOfLoop = getStartingNode(head);
    if(startOfLoop == NULL)
        return head; 

    Node* temp = startOfLoop;
    while(temp->next != startOfLoop) {
        temp = temp->next;
    }

    temp->next = NULL; 
    return head;
}

void printList(Node* head) {
    Node* temp = head;
    int count = 0;

    cout << "List: ";
    while(temp != NULL && count < 20) { 
        cout << temp->data << " ";
        temp = temp->next;
        count++;
    }
    if(temp != NULL)
        cout << "...(loop continues)";
    cout << endl;
}

int main() {
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);

    head->next->next->next->next->next = head->next->next;

    cout << "Before loop removal:" << endl;
    printList(head);

    head = removeLoop(head);

    cout << "\nAfter loop removal:" << endl;
    printList(head);

    return 0;
}
