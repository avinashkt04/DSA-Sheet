#include<iostream>
using namespace std;

int factorial(int n){
    // Base Case
    if(n==0){
        return 1;
    }

    return n * factorial(n-1);
}

int power(int n){
    // Base Case
    if(n==0){
        return 1;
    }

    return 2 * power(n-1);
}

int main() {
    int n;
    cin >> n;

    /*
    int ans = factorial(n);

    cout << ans << endl;
    */

    int ans = power(n);

    cout << ans << endl;

    return 0;
}