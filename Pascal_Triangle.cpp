#include<iostream>
using namespace std;

// There can be three questions asked:
// 1. They give the row(n) and col(r) and ask to find the element at given row and col
// 2. They can ask to print the specific row
// 3. Given N print the entire pascal triangle


// 1. Question
long long funNCR(int n, int r){
    long long res = 1;

    for(int i=0; i<r; i++){
        res = (res * (n-i))/(i+1);
    }

    return res;
}

// 2. Question 
// (r-1)C(c-1)
void printRow(int n){
    // Brute force approach
    // for(int i=1; i<=n; i++){
    //     cout << funNCR(n-1, i-1) << " ";
    // }
    // cout << endl;

    // Optimised
    long long ans = 1;
    cout << ans << " ";
    for(int i=1; i<n; i++){
        ans = (ans*(n-i))/(i);
        cout << ans << " ";
    }
    cout << endl;
}


int main(){
    int n, r;

    cout << "Enter n: ";
    cin >> n;

    cout << "Enter r: ";
    cin >> r;

    cout << "Result: " << funNCR(n, r) << endl;
    printRow(n);

    return 0;
}