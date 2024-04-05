#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

struct Array
{
    int A[20];

    int size;
    int length=0;

};


//Lecture NUmber 2 ::For Appending the element in the code
void Append(struct Array *arr,int x
){
 if(arr->length< arr->size)
   arr ->A[arr->length++]=x;
   
}

void Display(struct Array arr){
    cout<<"Elements are :-";
    for(int i=0; i<arr.length; i++)
    cout<<arr.A[i]<<"  ";

}

int Delete(struct Array *arr,int index)
{
    int x=0;
    if(index>=0 && index<arr->length){
        x=arr->A[index];

    }
    return 0;
    
}

void Insert(struct Array *arr,int index,int x){
    if(index>=0 &&index<=arr->length){
        for(int i=arr->length; i>index; i--)
        arr->A[i]=arr->A[i-1];
arr->A[index]=x;
arr->length++;

    }
}
int main()
{
    
struct Array arr ={12,3,4,3,2};
Append(&arr,10);
Insert(&arr,5,10);//If the index is not valid the element will never will be inserted;



Display(arr);







    return 0;
}