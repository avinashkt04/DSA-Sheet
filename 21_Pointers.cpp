#include<iostream>

using namespace std;

int main () { 
    /*
    int num = 5;
    cout << num << endl;

    // address of operator - &
    cout << "Address of num is " << &num << endl;
    int *ptr = &num;

    cout << "Value is: " << ptr << endl;
    cout << "Value is: " << *ptr << endl;

    double d = 4.3;
    double *p2 = &d;

    cout << "Address is: " << p2 << endl;
    cout << "Value is: " << *p2 << endl;
    */

    /*
    // pointer to int is created, and pointing to some garbage address
    // int *p; // bad practice

    int i = 5;
    int *p = 0;
    p = &i;

    cout << p << endl;
    cout << *p << endl;
    */

    int num = 5;
    int a = num;
    a++;

    cout << "a before: " << num << endl;

    int *p = &num;
    (*p)++;

    cout << "a after: " << num << endl;

    // copying a pointer
    int *q = p;
    cout << p << " - " << q << endl;
    cout << *p << " - " << *q << endl;

    // important concept
    int i = 3;
    int *t = &i;
    // cout << (*t)++ << endl;
    *t = *t + 1;
    cout << *t << endl;
    cout << "before t: " << t << endl;
    t = t+1;
    cout << "after t: " << t << endl;

    return 0;
}