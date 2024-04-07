#include <iostream>
using namespace std;
//This code is for the Introduction of all the cpp codes installed in the codes as well ..
//This Code Contains all codes related to the Sparse Matrix using C...
//It contains all the codes related to Sparse from displaying to adding two sparse Matrices in an order ....

struct Element {
    int i;
    int j;
    int x;
};

struct Sparse {
    int m;
    int n;
    int num;
    Element *ele;
};

void create(Sparse *s) {
    int i;

    cout << "Enter Dimensions: ";
    cin >> s->m >> s->n;
    cout << "Number of non-zero: ";
    cin >> s->num;

    s->ele = new Element[s->num];
    cout << "Enter non-zero Elements: ";
    for (i = 0; i < s->num; i++)
        cin >> s->ele[i].i >> s->ele[i].j >> s->ele[i].x;
}

void display(Sparse s) {
    int i, j, k = 0;

    for (i = 0; i < s.m; i++) {
        for (j = 0; j < s.n; j++) {
            if (i == s.ele[k].i && j == s.ele[k].j)
                cout << s.ele[k++].x << " ";
            else
                cout << "0 ";
        }
        cout << endl;
    }
}

Sparse* add(Sparse *s1, Sparse *s2) {
    Sparse *sum;
    int i, j, k;
    i = j = k = 0;

    if (s1->n != s2->n || s1->m != s2->m)
        return NULL;
    
    sum = new Sparse;
    sum->ele = new Element[(s1->num + s2->num) * sizeof(Element)];

    while (i < s1->num && j < s2->num) {
        if (s1->ele[i].i < s2->ele[j].i)
            sum->ele[k++] = s1->ele[i++];
        else if (s1->ele[i].i > s2->ele[j].i)
            sum->ele[k++] = s2->ele[j++];
        else {
            if (s1->ele[i].j < s2->ele[j].j)
                sum->ele[k++] = s1->ele[i++];
            else if (s1->ele[i].j > s2->ele[j].j)
                sum->ele[k++] = s2->ele[j++];
            else {
                sum->ele[k] = s1->ele[i];
                sum->ele[k++].x = s1->ele[i++].x + s2->ele[j++].x;
            }
        }
    }
    for (; i < s1->num; i++) sum->ele[k++] = s1->ele[i];
    for (; j < s2->num; j++) sum->ele[k++] = s2->ele[j];

    sum->m = s1->m;
    sum->n = s1->n;
    sum->num = k;

    return sum;
}

int main() {
    Sparse s1, s2, *s3;

    create(&s1);
    create(&s2);

    s3 = add(&s1, &s2);

    cout << "First Matrix\n";
    display(s1);
    cout << "Second Matrix\n";
    display(s2);
    cout << "Sum Matrix\n";
    display(*s3);

    delete[] s1.ele;
    delete[] s2.ele;
    delete[] s3->ele;
    delete s3;

    return 0;
}
