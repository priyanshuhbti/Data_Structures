#include<iostream>
using namespace std;

void fun(int n){

    if(n>0)
    {
        cout<<n<<" ";
        fun(n-1);

    }
}

int main()
{
    //Recursion basically uses the Stack to store out the data as well..
   int x=3;
   fun(x);

   
    return 0;
}