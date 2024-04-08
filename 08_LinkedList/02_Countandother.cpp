#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

struct Node
{
    int data;
    struct Node *next;
}*first=NULL;

void create(int A[], int n)
{
    int i;
    struct Node *t, *last;
    first = new Node;
    first->data = A[0];
    first->next = NULL;
    last = first;
    for (i = 1; i < n; i++)
    {
        t = new Node;
        t->data = A[i];
        t->next = NULL;
        last->next = t;
        last = t;
    }
}

void Display(struct Node *p)
{
    while (p != NULL)
    {
        cout << p->data << " ";
        p = p->next;
    }
}

void RDisplay(struct Node *p)
{
    if (p != NULL)
    {
        RDisplay(p->next);
        cout << p->data << " ";
    }
}

//For Counting the Number of nodes ..
int count(struct Node *p)
{
    int l = 0;
    while (p)
    {
        l++;
        p = p->next;
    }
    return l;
}


//Recursive Counting ...
int Rcount (struct Node *p)
{
    if(p!=NULL)
    return Rcount(p->next)+1;
    else 
    return 0;


}

//Here we are showing the sum functions ::
int sum(struct Node *p)
{
    int s=0;
    while(p!=NULL)
    {
        s+=p->data;
        p=p->next;

    }
    return s;


}
int Rsum(struct Node *p)
{
    if(p==NULL)
    return 0;
    else
    return Rsum(p->next)+p->data;
    
}
int main()
{
    struct Node *temp;
    int A[] = {3, 35, 22, 123, 55, 45,32};
    int n = sizeof(A) / sizeof(A[0]); // Calculate the size of the array
    create(A, n);
    // cout << "Length is : " << count(first) << endl;
    cout<<"THe SUm of the functions is : "<<sum(first)<<endl;

    return 0;
}
