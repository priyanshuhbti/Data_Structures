#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* createLinkedList(int A[], int n) {
    Node *first = nullptr, *last = nullptr;
    if (n == 0) return nullptr;

    first = new Node;
    first->data = A[0];
    first->next = nullptr;
    last = first;

    for (int i = 1; i < n; i++) {
        Node* t = new Node;
        t->data = A[i];
        t->next = nullptr;
        last->next = t;
        last = t;
    }

    return first;
}

void displayLinkedList(Node* head) {
    while (head) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

void insertAtIndex(Node*& head, int index, int value) {
    if (index < 0) {
        cout << "Invalid index" << endl;
        return;
    }

    Node* newNode = new Node;
    newNode->data = value;

    if (index == 0) {
        newNode->next = head;
        head = newNode;
    } else {
        Node* current = head;
        for (int i = 0; i < index - 1 && current; i++) {
            current = current->next;
        }
        if (!current) {
            cout << "Invalid index" << endl;
            return;
        }
        newNode->next = current->next;
        current->next = newNode;
    }
}

int main() {
    int A[] = {3, 4, 5, 6, 7, 8, 9, 20};
    int n = sizeof(A) / sizeof(A[0]);

    Node* first = createLinkedList(A, n);
    cout << "Linked List created: ";
    displayLinkedList(first);

    int index, value;
    cout << "Enter the index where you want to insert the element: ";
    cin >> index;
    cout << "Enter the value to be inserted: ";
    cin >> value;

    insertAtIndex(first, index, value);

    cout << "Linked List after insertion: ";
    displayLinkedList(first);

    return 0;
}
