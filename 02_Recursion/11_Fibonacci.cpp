#include<iostream>
using namespace std;

//THis is code for the Recursive Fibonaaci Series as well .. You can get itervative version as well ...
int rfib(int n)
{
    if(n<=1)
    return n;
    return rfib(n-2)+rfib(n-1);


}
int main()
{
    cout<<rfib(6)<<endl;
    
    
    return 0;
}