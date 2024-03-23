#include<iostream>

//One of the Basics Point to Excel in the coding is not cheat from the code :: Write the all codes from yourselves only ...
using namespace std;
void fun(int x){

    if(x>0){
     cout<<x<<" ";
     fun(x-1);
     fun(x-1);

    }
}
int main()
{
    
    fun(3);

    return 0;
}