//This method uses Pascal's Triangle method for implementing the ncr in the code as well ..
//It will makes calls form the bottom to the top using the tree diagram as well ...

#include<iostream>

using namespace std;
int fac(int n){
    if(n==0)
    return 1;
    return fac(n-1)*n;

}
int nCr(int n,int r){
    int num= fac(n);
    int den= fac(r)*fac(n-r);
    return num/den;

}
int main()
{

    cout<<nCr(5,3)<<endl;
    return 0;
}