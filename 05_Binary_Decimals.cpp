#include<iostream>
#include<math.h>
using namespace std;

int main(){
    /*
    int n;
    cout << "Enter the value of n: ";
    cin >> n;

    float i = 0, ans = 0;

    while(n!=0){
        int bit = n&1;
        ans = (bit * pow(10, i)) + ans;
        n = n >> 1;
        i++;
    }

    cout << "Answer: " << ans;
    */
   
    int n;
    cout << "Enter the value of n: ";
    cin >> n;

    int num_bits = sizeof(int) * 8; // Number of bits in an int

    // Use a union to reinterpret the bits of the integer
    union {
        int integer;
        unsigned int binary;
    } data;

    data.integer = n;

    // Print the binary representation
    cout << "Binary representation: ";
    for (int i = num_bits - 1; i >= 0; i--) {
        bool bit = (data.binary >> i) & 1;
        cout << bit;
    }

    cout << endl;







    return 0;
}