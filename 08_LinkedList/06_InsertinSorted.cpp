// Here we will take insertion in the Sorted list and we will try to insert the element in the sorted linked list so it can be used by someone for their wprk as well ...
 
 
 #include <iostream>
using namespace std;

// Define a structure for a node in a linked list
struct Node
{
    int data;
    Node *next;
}*first=nullptr,*second=nullptr,*third=nullptr; // Define three pointers to nodes: first, second, third

// Function to display the linked list
void Display(Node *p)
{
    // Iterate through the linked list and print each element
    while(p!=nullptr)
    {
        cout << p->data << " ";
        p=p->next;
    }
}

// Function to create a linked list from an array
void create(int A[],int n)
{
    int i;
    Node *t,*last;

    // Allocate memory for the first node and assign its data
    first=new Node;
    first->data=A[0];
    first->next=nullptr;
    last=first;

    // Iterate through the array and create nodes for each element
    for(i=1;i<n;i++)
    {
        t=new Node;
        t->data=A[i];
        t->next=nullptr;
        last->next=t;
        last=t;
    }
}

// Function to insert a node into a sorted linked list
void SortedInsert(Node *p, int x)
{
    Node *t,*q=nullptr;

    // Allocate memory for the new node and assign its data
    t=new Node;
    t->data=x;
    t->next=nullptr;

    // If the linked list is empty, set the new node as the first node
    if(first==nullptr)
        first=t;
    else
    {
        // Traverse the linked list until finding the appropriate position to insert the new node
        while(p && p->data<x)
        {
            q=p;
            p=p->next;
        }
        // If the new node is to be inserted at the beginning
        if(p==first)
        {
            t->next=first;
            first=t;
        }
        // If the new node is to be inserted in the middle or end
        else
        {
            t->next=q->next;
            q->next=t;
        }
    }
}

int main()
{
    int A[]={10,20,30,40,50};
    create(A,5); // Create a linked list from the array

    SortedInsert(first,15); // Insert 15 into the sorted linked list

    Display(first); // Display the sorted linked list

    return 0;
}
