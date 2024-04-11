#include<bits/stdc++.h>
using namespace std;

struct Matrix
{
    int A[10];
    int n;

};

//These function set the value of some functions at a specific value ...
void Set(struct Matrix *m, int i, int j, int x)
{
  if(i==j)
  m->A[i-1]=x;

}
//This function is used to get the value at a specific number or part of a Aij Value ...
int Get(struct Matrix m,int i, int j)
{
    if(i==j)
    return m.A[i-1];
    else
      return 0;

}
//This is function to display the value of a Diagonal Matrices...
void Display(struct Matrix m)
{
 int i,j;
 for(i=0;i<m.n;i++)
 {
 for(j=0;j<m.n;j++)
 {
 if(i==j)
 printf("%d ",m.A[i]);
 else
 printf("0 ");
 }
 printf("\n");
 }
}


int main()
{

    struct Matrix m;
    m.n=4;
    Set(&m,1,1,5);Set(&m,2,2,8);Set(&m,3,3,9);Set(&m,
4,4,12);
 printf("%d \n",Get(m,2,2));
 Display(m);
    
    return 0;
}




// HEre is the Whole CPP COde for this .. You may visit and Explore the cpp code as well ..

#include <iostream>
using namespace std;

class Diagonal {
private:
    int *A;
    int n;
public:
    Diagonal(int dimension = 2) : n(dimension) {
        A = new int[n];
        for (int i = 0; i < n; ++i)
            A[i] = 0;
    }

    ~Diagonal() {
        delete[] A;
    }

    void set(int i, int j, int x) {
        if (i == j)
            A[i - 1] = x;
    }

    int get(int i, int j) {
        return (i == j) ? A[i - 1] : 0;
    }

    void display() {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j)
                cout << ((i == j) ? A[i] : 0) << " ";
            cout << endl;
        }
    }

    int getDimension() {
        return n;
    }
};

int main() {
    int dimensions;
    cout << "Enter Dimensions: ";
    cin >> dimensions;

    Diagonal dm(dimensions);

    cout << "Enter All Elements: ";
    for (int i = 1; i <= dimensions; ++i)
        for (int j = 1; j <= dimensions; ++j) {
            int x;
            cin >> x;
            dm.set(i, j, x);
        }

    dm.display();
    return 0;
}
