#include<iostream>
using namespace std;

int fun (int n){

    static int x=0;
    if(n>0){

        x++;
        return fun(n-1)+x;

    }
    return 0;

}

int main()
{
    //Here we are coding the static as well as global variable ..
    //The static variable reinialise itself everytime when the function is called ... and in global variable the value remains the same and does not changes and become global as well ..
    
    int r;
    r=fun(5);
    cout<<r<<endl;

    r=fun(5);
    cout<<r<<endl;

    
  


    
    
    
    return 0;
}