#include<iostream>
using namespace std;
//Do not copyRight the code :: Try to solve all the codes by yourselves and only refer to it when you are stuck at some Part ..
//It also makes your coding speed bit a fast as well ...
//Always use the full screen of the VS Code or any code editor + NCS 
int power(int m, int n){
    if(n==0)
    return 1;
    return power(m,n-1)*m;

}
int main()
{
    
    int r;
    r=power(2,4);
    cout<<r<<endl;

    return 0;
}