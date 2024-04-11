#include <iostream> // Include the necessary libraries
#include <stack>
#include <cstring> // For string manipulation

using namespace std;

// Define a Node structure for the stack
struct Node {
    char data;
    Node* next;
};

Node* top = nullptr; // Initialize top of stack

// Function to push an element onto the stack
void push(char x) {
    Node* t = new Node; // Create a new node
    t->data = x; // Assign data to the new node
    t->next = top; // Set the next of the new node to the current top
    top = t; // Update top to point to the new node
}

// Function to pop an element from the stack
char pop() {
    if (top == nullptr) {
        cout << "Stack is Empty" << endl; // If stack is empty, print error message
        return -1; // Return -1 to indicate failure
    } else {
        Node* t = top; // Store the current top
        char x = t->data; // Store the data of the top node
        top = top->next; // Update top to point to the next node
        delete t; // Delete the old top node
        return x; // Return the popped element
    }
}

// Function to check if parentheses are balanced in an expression
int isBalanced(char* exp) {
    int i;
    for (i = 0; exp[i] != '\0'; i++) {
        if (exp[i] == '(') {
            push(exp[i]); // Push opening parentheses onto the stack
        } else if (exp[i] == ')') {
            if (top == nullptr) {
                return 0; // If closing parentheses encountered and stack is empty, return 0 (unbalanced)
            }
            pop(); // Pop matching opening parentheses
        }
    }
    return (top == nullptr) ? 1 : 0; // If stack is empty, return 1 (balanced), otherwise return 0
}

// Function to determine the precedence of operators
int pre(char x) {
    if (x == '+' || x == '-') {
        return 1;
    } else if (x == '*' || x == '/') {
        return 2;
    }
    return 0;
}

// Function to check if a character is an operand
int isOperand(char x) {
    return (x == '+' || x == '-' || x == '*' || x == '/') ? 0 : 1;
}

// Function to convert infix expression to postfix
char* InToPost(char* infix) {
    int i = 0, j = 0;
    char* postfix;
    int len = strlen(infix);
    postfix = new char[len + 2]; // Allocate memory for the postfix expression

    while (infix[i] != '\0') {
        if (isOperand(infix[i])) {
            postfix[j++] = infix[i++]; // If operand, append it to postfix expression
        } else {
            if (pre(infix[i]) > pre(top->data)) {
                push(infix[i++]); // If operator, push onto stack if precedence is higher than top of stack
            } else {
                postfix[j++] = pop(); // Pop operators from stack and append to postfix until precedence is lower
            }
        }
    }
    while (top != nullptr) {
        postfix[j++] = pop(); // Pop remaining operators from stack and append to postfix
    }
    postfix[j] = '\0'; // Null terminate the postfix expression
    return postfix;
}

int main() {
    char* infix = "a+b*c-d/e"; // Define the infix expression
    push('#'); // Push a special character '#' onto the stack

    char* postfix = InToPost(infix); // Convert infix to postfix

    cout << postfix << endl; // Print the postfix expression

    return 0;
}
