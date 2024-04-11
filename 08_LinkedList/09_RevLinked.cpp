#include <iostream>
using namespace std;
//THe Chatgpt is literally killing your brain :: Reintialise your brain ...
// Define a structure for a Node
struct Node {
    int data;
    Node* next;
};

// Function to display the linked list
void Display(Node* p) {
    while (p != NULL) {
        cout << p->data << " ";
        p = p->next;
    }
}

// Function to create a linked list from an array
Node* create(int A[], int n) {
    Node *first = NULL, *last = NULL;

    first = new Node;
    first->data = A[0];
    first->next = NULL;
    last = first;

    for (int i = 1; i < n; i++) {
        Node* t = new Node;
        t->data = A[i];
        t->next = NULL;
        last->next = t;
        last = t;
    }

    return first;
}

// Function to reverse a linked list
void Reverse(Node* &p) {
    Node *q = NULL, *r = NULL;

    while (p != NULL) {
        r = q;
        q = p;
        p = p->next;
        q->next = r;
    }

    p = q; // Update the head of the list
}

int main() {
    // Create an array
    int A[] = {10, 20, 40, 50, 60};
    int n = sizeof(A) / sizeof(A[0]);

    // Create a linked list from the array
    Node* first = create(A, n);

    // Display the original linked list
    cout << "Original list: ";
    Display(first);

    // Reverse the linked list
    Reverse(first);

    // Display the reversed linked list
    cout << "\nReversed list: ";
    Display(first);

    return 0;
}
 

