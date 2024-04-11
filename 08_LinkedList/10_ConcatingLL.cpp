#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

void Display(Node* p) {
    while (p != NULL) {
        cout << p->data << " ";
        p = p->next;
    }
}

void create(Node*& first, int A[], int n) {
    Node *t, *last;
    first = new Node;
    first->data = A[0];
    first->next = nullptr;
    last = first;

    for (int i = 1; i < n; i++) {
        t = new Node;
        t->data = A[i];
        t->next = nullptr;
        last->next = t;
        last = t;
    }
}

void create2(Node*& second, int B[], int n) {
    Node *t, *last;
    second = new Node;
    second->data = B[0];
    second->next = nullptr;
    last = second;

    for (int i = 1; i < n; i++) {
        t = new Node;
        t->data = B[i];
        t->next = nullptr;
        last->next = t;
        last = t;
    }
}

Node* Merge(Node* p, Node* q) {
    Node *last, *third;
    if (p->data < q->data) {
        third = last = p;
        p = p->next;
        third->next = nullptr;
    } else {
        third = last = q;
        q = q->next;
        third->next = nullptr;
    }

    while (p && q) {
        if (p->data < q->data) {
            last->next = p;
            last = p;
            p = p->next;
            last->next = nullptr;
        } else {
            last->next = q;
            last = q;
            q = q->next;
            last->next = nullptr;
        }
    }
    if (p) last->next = p;
    if (q) last->next = q;

    return third;
}

int main() {
    Node *first = nullptr, *second = nullptr, *third = nullptr;

    int A[] = {10, 20, 40, 50, 60};
    int B[] = {15, 18, 25, 30, 55};
    create(first, A, 5);
    create2(second, B, 5);

    third = Merge(first, second);
    Display(third);

    return 0;
}
