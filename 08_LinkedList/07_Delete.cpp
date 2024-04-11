#include <iostream>
using namespace std;

// Define a structure for a node in a linked list
struct Node {
    int data;
    Node* next;
};

// Function to create a linked list from an array
Node* createLinkedList(int A[], int n) {
    Node *first = nullptr, *last = nullptr; // Pointers to keep track of the first and last nodes

    // Check if the array is empty
    if (n == 0) 
        return nullptr;

    // Create the first node with the first element of the array
    first = new Node;
    first->data = A[0];
    first->next = nullptr;
    last = first; // Point 'last' to the first node

    // Iterate through the array to create nodes for each element
    for (int i = 1; i < n; i++) {
        Node* t = new Node; // Create a new node
        t->data = A[i]; // Assign data from the array
        t->next = nullptr; // Set next pointer to nullptr
        last->next = t; // Link the new node to the last node
        last = t; // Update 'last' to point to the newly created node
    }

    return first; // Return the pointer to the first node of the linked list
}

// Function to display the elements of a linked list
void displayLinkedList(Node* head) {
    while (head) { // Loop until the end of the list (head != nullptr)
        cout << head->data << " "; // Print the data of the current node
        head = head->next; // Move to the next node
    }
    cout << endl; // Print newline after printing all elements
}

// Function to delete a node at a specified index in the linked list
int deleteAtIndex(Node*& head, int index) {
    if (index < 0) // Check if the index is invalid
        return -1;

    Node* q = nullptr; // Pointer to the node before the node to be deleted
    int x = -1; // Variable to store the data of the deleted node

    if (index == 0) { // If the node to be deleted is the first node
        q = head; // Set q to point to the first node
        x = head->data; // Store the data of the first node
        head = head->next; // Update head to point to the next node
        delete q; // Delete the first node
        return x; // Return the data of the deleted node
    } else {
        Node* p = head; // Pointer to traverse the list
        // Traverse the list to find the node at index - 1
        for (int i = 0; i < index && p; i++) {
            q = p; // Update q to point to the node before p
            p = p->next; // Move p to the next node
        }
        // Check if the index is out of bounds
        if (!p)
            return -1;
        // Delete the node at index
        q->next = p->next; // Link the node before p to the node after p
        x = p->data; // Store the data of the deleted node
        delete p; // Delete the node at index
        return x; // Return the data of the deleted node
    }
}


int main() {
    int A[] = {3, 4, 5, 6, 7, 8, 9, 20};
    int n = sizeof(A) / sizeof(A[0]); // Calculate the size of the array

    // Create a linked list from the array
    Node* first = createLinkedList(A, n);
    cout << "Linked List created: ";
    displayLinkedList(first); // Display the created linked list

    // Get index from user for deletion
    int delIndex;
    cout << "Enter the index of the element to delete: ";
    cin >> delIndex;

    // Delete the element at the specified index
    int deleted = deleteAtIndex(first, delIndex);
    if (deleted != -1)
        cout << "Element deleted: " << deleted << endl;
    else
        cout << "Invalid index" << endl;

    // Display the linked list after deletion
    cout << "Linked List after deletion: ";
    displayLinkedList(first);

    return 0;
}
