#include<iostream>
using namespace std;
int e(int x,int n){
    static int p=1,f=1;
    int r;
    if(n==0)
    return 1;
    else{
        r=e(x,n-1);
        p=p*x;
        f=f*n;
        return r+ p/f;

    }

}
int main()
{
    //For Generating the value of the e with the just write the function as well ...
    //Here n denotes ki kb tk ...

    cout<<e(3,10)<<endl;



    return 0;
}