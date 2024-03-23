#include<iostream>
using namespace std;
//This is the code of the Taylor using Horner Rule ...

int e(int m,int n){
    static int s=1;
    if(n==0)
    return s;
    else{
        s=1+m/n *s;
        return e(m ,n-1);

    }
}
int main()
{

    cout<<e(2,10)<<endl;

    return 0;
}