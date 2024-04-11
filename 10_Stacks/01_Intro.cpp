#include<iostream>
using namespace std;

struct Stack
{
    int size;
    int top;
    int *S;

};

void Create(struct Stack *st){
    cout<<"ENter the Size";
    cin>>&st->size;
    st->top=-1;
    st->S =new int


}

int main()
{
    
    return 0;
}