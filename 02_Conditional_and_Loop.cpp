#include<iostream>
using namespace std;

int main(){
    /*
    int a;
    cout << "Enter value of a ";
    cin >> a;
    if(a>0){
        cout << a << " is a positive number" << endl;
    }
    else{
        cout << a << " is a negative number" << endl;
    }

    a = cin.get();
    cout << "Value of a is " << a <<endl;
    */

    /*
    int a = 2;
    int b = a+1;
    if((a=3)==b){
        cout << a;
    }
    else{
        cout << a+1;
    }
    */

    /*
    int a = 24;
    if(a>20){
        cout << "Love";
    }
    else if(a==24){
        cout << "Lovely";
    }
    else{
        cout << "Babbar";
    }
    */

    /*
    char ch;
    cout << "Enter a character ";
    cin >> ch;
    if(ch>=65 && ch<=90){
        cout << "Upper Case" << endl;
    }
    else if(ch>=97 && ch<=122){
        cout << "Lower Case" << endl;
    }
    else if(ch>=48 && ch<=57){
        cout << "Numeric value" << endl;
    }
    */

    /*
    int n, sum = 0;
    cout << "Enter the value of n ";
    cin >> n;

    int i = 1;
    while(i<=n){
        sum += i;
        i++;
    }
    cout << "Sum upto " << n << " is " << sum;
    */

    /*
    int n, sum = 0;
    cout << "Enter the value of n ";
    cin >> n;

    int i = 1;
    while(i<=n){
        if(i%2==0){
            sum += i;
        }
        i++;
    }
    cout << "Sum of even numbers upto " << n << " is " << sum;
    */

    int n;
    cout << "Enter the value of n ";
    cin >> n;

    bool isPrime = 1;

    for(int i = 2; i<n; i++){
        if(n%i==0){
            isPrime = 0;
            break;
        }
    }

    if(isPrime==0){
        cout << n << " is not a prime number";
    }
    else{
        cout << n << " is a prime number";
    }

    return 0;
}