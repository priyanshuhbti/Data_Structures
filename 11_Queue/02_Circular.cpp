#include <iostream>

using namespace std;
 
class Queue {
private:
    int size;
    int front;
    int rear;
    int* Q;
public:
    Queue(int size);
    ~Queue();
    bool isFull();
    bool isEmpty();
    void enqueue(int x);
    int dequeue();
    void display();
};
 
Queue::Queue(int size) {
    this->size = size;
    front = -1;
    rear = -1;
    Q = new int[size];
}
 
Queue::~Queue() {
    delete[] Q;
}
 
bool Queue::isEmpty() {
    return front == rear;
}
 
bool Queue::isFull() {
    return rear == size - 1;
}
 
void Queue::enqueue(int x) {
    if (isFull()) {
        cout << "Queue Overflow" << endl;
        return;
    }
    rear++;
    Q[rear] = x;
}
 
int Queue::dequeue() {
    if (isEmpty()) {
        cout << "Queue Underflow" << endl;
        return -1; // Return a meaningful value to indicate underflow
    }
    front++;
    int x = Q[front];
    return x;
}
 
void Queue::display() {
    if (isEmpty()) {
        cout << "Queue is empty" << endl;
        return;
    }
    for (int i = front + 1; i <= rear; i++) {
        cout << Q[i] << flush;
        if (i < rear) {
            cout << " <- " << flush;
        }
    }
    cout << endl;
}
 
int main() {
    int A[] = {1, 3, 5, 7, 9};
    Queue q(sizeof(A) / sizeof(A[0]));
 
    // Enqueue
    for (int i = 0; i < sizeof(A) / sizeof(A[0]); i++) {
        q.enqueue(A[i]);
    }
 
    // Display
    q.display();
 
    // Overflow
    q.enqueue(10);
 
    // Dequeue
    for (int i = 0; i < sizeof(A) / sizeof(A[0]); i++) {
        q.dequeue();
    }
 
    // Underflow
    q.dequeue();
    
    return 0;
}
