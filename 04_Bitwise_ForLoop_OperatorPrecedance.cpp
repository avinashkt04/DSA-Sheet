#include<iostream>
using namespace std;

int main(){
    /*
    int a = 4;
    int b = 6;
    cout << " a&b " << (a&b) << endl;
    cout << " a|b " << (a|b) << endl;
    cout << " ~a " << ~a << endl;
    cout << " a^b " << (a^b) << endl;

    cout << (17>>1) << endl;
    cout << (17>>2) << endl;
    cout << (19<<1) << endl;
    cout << (21<<2) << endl;

    int x, y = 1;
    x = 10;
    if(++x){
        cout << y;
    }
    else{
        cout << ++y;
    }
    */

    /*
    int n;
    cout << "Enter the value of n: ";
    cin >> n;

    int i = 1;
    for(; ;){
        if(i<=n){
            cout << i << endl;
        }
        else{
            break;
        }
        i++;
    }
    */

    /*
    for(int a = 0, b = 1; a>=0 && b>=1; a--, b--){
        cout << a << " " << b <<endl;
    }
    */

    /*
    // Fibonacci number
    int n;
    cout << "Enter the value of n: ";
    cin >> n;

    int a = 0; 
    int b = 1;

    cout << a << " " << b << " ";

    for(int i=1; i<=n; i++){
        int nextNumber = a+b;
        cout << nextNumber << " ";
        a = b; 
        b = nextNumber;
    }
    */

    /*
    for(int i = 0; i<=15; i += 2){
        cout << i << " ";
        if(i&1){
            continue;
        }
        i++;
    }
    */

    /*
    // Leetcode first question
    int n;
    cout << "Enter the value of n: ";
    cin >> n;

    int sum = 0, prd = 1, rem;

    while(n!=0){
        rem = n%10;
        sum += rem;
        prd *= rem;
        n = n/10;
    }

    cout << "Answer: " << (prd-sum);
    */

    // Leetcode second question
    int n, count=0;
    cout << "Enter the integer: ";
    cin >> n;

    while(n!=0){
        // int digit = n % 10;
        // if(digit==1){
        //     count++;
        // }
        // n = n/10;
        if(n&1){
            count++;
        }
        n = n >> 1;
    }

    cout << "Number of 1 bits in given integer: " << count;

    return 0;
}