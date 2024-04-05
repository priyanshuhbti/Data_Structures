#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

struct Array
{
    int *A;
    int size;
    int length;

};


void Display(struct Array arr){
    cout<<"Elements are :-";
    for(int i=0; i<arr.length; i++)
    cout<<arr.A[i]<<"  ";



}
int main()
{
    
struct Array arr; 
int i,n;

cout<<"Enter the Size of the Array"<<endl;
cin>>arr.size;
arr.A=new int[arr.size];

arr.length=0;

cout<<"ENter the number of elements"<<endl;
cin>>n;
cout<<"Enter all the elements of Array"<<endl;
for(i=0; i<n; i++)
    cin>>arr.A[i];
arr.length=n;



Display(arr);




    return 0;
}