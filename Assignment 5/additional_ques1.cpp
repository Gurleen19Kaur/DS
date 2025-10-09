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

    ~Node() {
        if (this->next != NULL) {
            delete next;
            this->next = NULL;
        }
    }
};

int intersection(Node* head1, Node* head2) {
    if (head1 == NULL || head2 == NULL)
        return -1;

    Node* ptrA = head1;
    Node* ptrB = head2;

    while (ptrA != ptrB) {
        ptrA = (ptrA == NULL) ? head2 : ptrA->next;
        ptrB = (ptrB == NULL) ? head1 : ptrB->next;
    }

    if (ptrA == NULL)
        return -1; // no intersection

    return ptrA->data;
}

void print(Node* head1, Node* head2) {
    Node *temp1 = head1;
    Node *temp2 = head2;

    cout << "List 1: ";
    while (temp1 != NULL) {
        cout << temp1->data << " ";
        temp1 = temp1->next;
    }

    cout << "\nList 2: ";
    while (temp2 != NULL) {
        cout << temp2->data << " ";
        temp2 = temp2->next;
    }
    cout << endl;
}

int main() {
    Node *head1 = new Node(4);
    head1->next = new Node(1);

    Node *head2 = new Node(5);
    head2->next = new Node(6);
    head2->next->next = new Node(1);

    Node *temp = new Node(8);
    head1->next->next = temp;
    head2->next->next->next = temp;

    temp->next = new Node(5);
    temp->next->next = new Node(7);

    print(head1, head2);

    int output = intersection(head1, head2);
    if (output == -1)
        cout << "No intersection found.";
    else
        cout << "Intersection node data = " << output << endl;

    return 0;
}

