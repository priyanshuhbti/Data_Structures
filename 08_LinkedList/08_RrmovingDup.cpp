#include <iostream>
using namespace std;

// Define a structure for the linked list node
struct Node {
    int data;         // Data part of the node
    Node *next;       // Pointer to the next node
};

Node *first = NULL;   // Head pointer for the first linked list
Node *second = NULL;  // Head pointer for the second linked list
Node *third = NULL;   // Head pointer for the third linked list

// Function to display the linked list
void Display(Node *p) {
    while (p != NULL) {
        cout << p->data << " ";  // Print the data of the current node
        p = p->next;             // Move to the next node
    }
}

// Function to create a linked list from an array
void create(int A[], int n) {
    Node *t, *last;   // t for temporary node, last for pointing to the last node

    first = new Node;  // Create the first node
    first->data = A[0];  // Assign the first element of the array to the data of the first node
    first->next = NULL;  // Set the next pointer to NULL
    last = first;        // Point 'last' to the first node

    // Loop through the array starting from the second element
    for (int i = 1; i < n; i++) {
        t = new Node;     // Create a new node
        t->data = A[i];   // Assign the current element of the array to the data of the new node
        t->next = NULL;   // Set the next pointer of the new node to NULL
        last->next = t;   // Link the last node to the new node
        last = t;         // Move 'last' to the newly added node
    }
}

// Function to remove duplicates from a sorted linked list
void RemoveDuplicate(Node *p) {
    Node *q = p->next;  // q points to the node next to p

    while (q != NULL) {
        if (p->data != q->data) {
            p = q;
            q = q->next;
        } else {
            p->next = q->next;
            delete q;  // Free the memory allocated to the duplicate node
            q = p->next;


        }
    }
    
    
    }

int main() {
    int A[] = {10, 20, 20, 40, 50, 50, 50, 60};
    create(A, 8);  // Create a linked list from the array

    RemoveDuplicate(first);  // Remove duplicates from the linked list
    Display(first);          // Display the modified linked list

    return 0;
}
