#include<iostream>
using namespace std;

class Node {
public:
    int coeff;
    int pow;
    Node* next;
    Node(int c, int p) {
        coeff = c;
        pow = p;
        next = NULL;
    }
};

void insertAtTail(Node*& head, int coeff, int pow) {
    Node* newNode = new Node(coeff, pow);
    if (head == NULL) {
        head = newNode;
        return;
    }
    Node* temp = head;
    while (temp->next != NULL)
        temp = temp->next;
    temp->next = newNode;
}

Node* addPolynomials(Node* poly1, Node* poly2) {
    Node* head = NULL;
    Node* tail = NULL;

    while (poly1 != NULL && poly2 != NULL) {
        Node* newNode = NULL;
        if (poly1->pow > poly2->pow) {
            newNode = new Node(poly1->coeff, poly1->pow);
            poly1 = poly1->next;
        } else if (poly1->pow < poly2->pow) {
            newNode = new Node(poly2->coeff, poly2->pow);
            poly2 = poly2->next;
        } else {
            newNode = new Node(poly1->coeff + poly2->coeff, poly1->pow);
            poly1 = poly1->next;
            poly2 = poly2->next;
        }

        if (head == NULL) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    while (poly1 != NULL) {
        Node* newNode = new Node(poly1->coeff, poly1->pow);
        tail->next = newNode;
        tail = newNode;
        poly1 = poly1->next;
    }

    while (poly2 != NULL) {
        Node* newNode = new Node(poly2->coeff, poly2->pow);
        tail->next = newNode;
        tail = newNode;
        poly2 = poly2->next;
    }

    return head;
}

void printPolynomial(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->coeff << "x^" << temp->pow;
        if (temp->next != NULL)
            cout << " + ";
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    Node* poly1 = NULL;
    Node* poly2 = NULL;

    // Example: 5x^3 + 4x^2 + 2x^1
    insertAtTail(poly1, 5, 3);
    insertAtTail(poly1, 4, 2);
    insertAtTail(poly1, 2, 1);

    // Example: 3x^3 + 2x^2 + 1x^0
    insertAtTail(poly2, 3, 3);
    insertAtTail(poly2, 2, 2);
    insertAtTail(poly2, 1, 0);

    cout << "First Polynomial: ";
    printPolynomial(poly1);

    cout << "Second Polynomial: ";
    printPolynomial(poly2);

    Node* sum = addPolynomials(poly1, poly2);

    cout << "Sum Polynomial: ";
    printPolynomial(sum);

    return 0;
}
