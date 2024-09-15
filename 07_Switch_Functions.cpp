#include<iostream>
#include<math.h>
using namespace std;

int pow(){
    int a, b;
    cin >> a >> b;
    int ans = 1;

    for(int i=0; i<b; i++){
        ans = ans * a;
    }

    return ans;
}

int factorial(int n){
    int fact = 1;

    for(int i=1; i<=n; i++){
        fact = fact * i;
    }
    return fact;
}

int nCr(int n, int r){
    int num = factorial(n);
    int denom = factorial(r)*factorial(n-r);
    return num/denom;
}

int AP(int n){
    return (3*n + 7);
}

int bin(int n){
    // int ans = 0, i=0;
    int count = 0;
    while(n!=0){
        int bit = n&1;
        if(bit==1){
            count++;
        }
        n = n >> 1;
    }
    return count;
}

int setBits(int a, int b){
    int x = bin(a);
    int y = bin(b);
    
    return (x+y);
}

int indexFib(int n){
    int first = 0;
    int second = 1;
    int sum;
    if(n==1){
        return 0;
    }
    for(int i=3; i<=n; i++){
        sum = first + second;
        first = second;
        second = sum;
    }
    return second;
}

int main(){
    /*
    char ch = '1';
    int num = 1;

    switch(ch){
        case 1: cout << "First" << endl;
                cout << "First again" << endl;
                break;

        case '1': switch(num){
                    case 1: cout << "Value of num is " << num << endl;
                    break;
                }
                break;

        default: cout << "It is default case" << endl;
    }
    */

    /*
    while (1){
        int num = 1;
        switch(num){
            case 1: cout << "Hey, how are you?";
                break;
            default: cout << "Hello";
        }
        exit(0);
    }
    */

    /*
    int a, b;
    cout << "Enter the value of a: ";
    cin >> a;
    cout << "Enter the value of b: ";
    cin >> b;
    char op;
    cout << "Enter the operator: ";
    cin >> op;

    switch(op){
        case '+': cout << "a + b is " << a+b;
            break;
        case '-': cout << "a - b is " << a-b;
            break;
        case '*': cout << "a * b is " << a*b;
            break;
        case '/': cout << "a / b is " << a/b;
            break;
        case '%': cout << "a % b is " << a%b;
            break;
        default: cout << "Enter the valid operator";
    }
    */

    /*
    cout << pow();
    */

    /*
    int n, r;
    cout << "Enter the value of n & r: ";
    cin >> n >> r;

    cout << "Answer is: " << nCr(n, r); 
    */

    /*
    int n;
    cout << "Enter the value of n: ";
    cin >> n;

    cout << "nth term of AP is " << AP(n);
    */

    /*
    int a, b;
    cout << "Enter the value of a & b: ";
    cin >> a >> b;

    cout << "Answer: " << setBits(a,b);
    */

    int n;
    cout << "Enter the value of n: ";
    cin >> n;
    cout << "Fibonacci number at " << n << " is " << indexFib(n);

    return 0;
}