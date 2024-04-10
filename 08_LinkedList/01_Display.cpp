#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

struct Node
{
    int data;
    struct Node *next;

}*first=NULL;

void create(int A[],int n)
{
    int i;
    struct Node *t,*last ;
  Node* first =new Node;
  first->data=A[0];
  first->next=NULL;
  last=first;

  for(i=1; i<n; i++)
  {
    Node* t=new Node;
    t->data=A[i];
    t->next=NULL;
    last->next=t;
    last=t;

  }


}

void Display(struct Node *p)
{
    while(p !=NULL)
    {
        cout<<p->data;
        p=p->next;

    }
}

void RDisplay(struct Node *p)
{
    if(p !=NULL)
    {
        RDisplay(p->next);
        cout<<p->data;

    }
}



int main()
{
    struct Node *temp;
    int A[]={3,35,22,123,55,32};
    create(A,8);
    Display(first);
    



    return 0;
}