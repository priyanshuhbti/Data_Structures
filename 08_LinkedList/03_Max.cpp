
//Only 14-15 Months Left ...You should believe that you are in IIT Kanpur ..
//Communication Skills(Most Important) +Personality +Confidence ..
//You need be good in Whole Computer Science and should be Good the DOmain ..
//First THing is DSA and Good CP Ratings ..
//Experience of Every Domain ..WEbD, AI/ML , Cloud Computing,Devops..
//And You should have strong depth in the CSE Fundamental as they are teached in IITs in depth ..They Research in that part as well ..


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

int Max(struct Node *p)
{
    int max = INT_MIN; // Initialize max to minimum possible value
    while (p)
    {
        if (p->data > max)
        {
            max = p->data;
        }
        p = p->next;
    }
    return max; // Return the maximum value found
}

int main()
{
    int A[] = {3, 4, 5, 6, 7, 8, 9, 20};
    create(A, 8);
    cout << "Max Element is : " << Max(first) << endl;

    return 0;
}
