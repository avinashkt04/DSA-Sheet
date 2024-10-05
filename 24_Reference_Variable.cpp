#include<iostream>
using namespace std;

// BAD PRACTICE
int& func(int a){
    int num = a;
    int& ans = num;
    return ans;
}

void update2(int& n){
    n++;
}

void update1(int n){
    n++;
}

int getSum(int* arr, int n){
    int sum = 0;
    for(int i=0; i<n; i++){
        sum += arr[i];
    }
    return sum;
}

int main(){
    /*
    int i=5;

    // create a ref variable

    int& j = i;

    cout << i << endl;
    i++;
    cout << i << endl;
    j++;
    cout << i << endl;

    int n=5;
    cout << "Before " << n << endl;
    update2(n);
    cout << "After " << n << endl;

    cout << func(n);
    */

    int n;
    cin >> n;

    // variable size array
    int* arr = new int[n];

    for(int i=0; i<n; i++){
        cin >> arr[i];
    }

    int ans = getSum(arr, n);

    cout << "answer is " << ans << endl;

    // Deleting element manually from dynamic memory
    // int* p = new int;
    // delete p;

    // int* arr = new int[5];
    // delete []arr;

    return 0;
}