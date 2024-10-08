#include<iostream>
using namespace std;

#define PI 3.14

int score = 15;

void a(int& i) {
    cout << score << " in a" << endl;
    cout << i << endl;
}

void b(int& i) {
    cout << score << " in b" << endl;
    cout << i << endl;
}

void func(int a, int b) {
    a++;
    b++;
    cout << a << b << endl;
}

inline int getMax(int& a, int& b) {
    return (a>b) ? a : b;
}

int main() {
    /*
    // Macros
    int r = 5;
    // double pi = 3.14;
    double area = PI * r * r;
    cout << "Area is " << area << endl;
    */

    /*
    // Global Variable
    cout << score << " in main" << endl;
    int i=5;
    a(i);
    b(i);
    */

    // Inline Functions
    int a = 1, b = 2;
    int ans = 0;

    ans = getMax(a, b);
    cout << ans << endl;

    a = a + 3;
    b = b + 1;

    ans = getMax(a, b);
    cout << ans << endl;
    
    return 0;
}