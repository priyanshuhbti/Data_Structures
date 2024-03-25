#include <iostream>
using namespace std;
//Static Array vs Dynamic Array 

int main() {
    int A[5] = {2, 4, 6, 8, 10};
    int *p;
    int i;
//Pointer Array
    p = new int[5];
    p[0] = 3;
    p[1] = 5;
    p[2] = 7;
    p[3] = 9;
    p[4] = 11;

  //Static Array 
    for (i = 0; i < 5; i++)
        cout << A[i] << " ";

  //Code for the Dynamic Array :: Just take two pointer for pointing as well ...      

    cout << endl;
    for (i = 0; i < 5; i++)
        cout << p[i] << " ";

    delete[] p;

    return 0;
}