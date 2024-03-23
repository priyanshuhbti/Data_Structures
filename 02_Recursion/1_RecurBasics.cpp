#include<iostream>
using namespace std;

void fun(int n){

    if(n>0)
    {
        //We can also consider the fun(n-1) at the front , not considering on the back as well .
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