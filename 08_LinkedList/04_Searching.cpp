//Tip No. 1

//Avoid Listening to Music :: Be in Cool and Silent Atmosphere ...



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


struct Node * LSearch(struct Node *p, int key ){
    while(p !=NULL)
    {
        if(key==p->data)
        return p;
        p=p->next;


    }
    return NULL;

}


//This is the Recursive Search Function ::
struct Node * RSearch(struct Node *p, int key )
{
    if(p==NULL)
     return NULL;
    if(key==p->data)
      return p;
    return RSearch(p->next,key);
      
}

int main()
{
    struct Node *temp;

    int A[] = {3, 4, 5, 6, 7, 8, 9, 20};
    create(A, 8);
    int key;
    cout<<"Enter the key ,which you want to find out .."<<endl;

    cin>>key;

   
   temp=LSearch(first,key);
   if(temp)
   cout<<"Key is Found : "<<temp->data<<endl;
   else
   cout<<"Key is not Found "<<endl;

    return 0;
}
