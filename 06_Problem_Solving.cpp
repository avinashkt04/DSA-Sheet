#include<iostream>
#include<math.h>

using namespace std;

int main(){
    /*
    // Reverse Integer
    int n;
    cout << "Enter the value of n: ";
    cin >> n;

    float rev = 0;

    while(n!=0){
        int digit= n%10;
        rev = (rev * 10) + digit;
        n = n/10;
    }
    if(rev > INT32_MAX/10 || rev < INT32_MIN/10){
        cout << "Reverse number: 0" ;
    }
    else{
        cout << "Reverse number: " << rev;
    }
    */

    /*
    // Compliment of Base 10 integer
    int n;
    cout << "Enter the value of n: ";
    cin >> n;
    int m = n;
    int mask = 0;
    while(m!=0){
        mask = (mask << 1) | 1;
        m = m >> 1;
    }
    int ans = (~n) & mask;
    cout << "Answer: " << ans;
    */

    // Power of two 
    int n;
    cout << "Enter the value of n: ";
    cin >> n;
    int count = 0;
    // Method 1
    /*
        while(n!=1){
            if(n%2==0){
                count++;
            }
            else{
                count = 0;
                break;
            }
            n = n/2;
        }
        cout << "Answer: " << count;
    */

    // Method 2
    while (n)
    {
        count += n & 1;
        n = n >> 1;
    }

    if(count == 1){
        cout << "n is power of 2" << endl;
    }
    else{
        cout << "n is not the power of 2" << endl;
    }

    return 0;
}