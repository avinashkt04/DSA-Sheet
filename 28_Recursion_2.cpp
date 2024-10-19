#include<iostream>
using namespace std;

// Count Ways To Reach The N-th Stairs
int countDistinctWays(int nStairs) {
    if(nStairs < 0) { 
        return 0;
    }
    if(nStairs == 0){
        return 1;
    }
    int ans = countDistinctWays(nStairs-1) + countDistinctWays(nStairs-2);
    return ans;
}

void sayDigit(int n, string arr[]){
    if(n==0)
        return;
    
    int digit = n%10;
    n = n/10;
    
    sayDigit(n, arr);

    cout << arr[digit] << " ";
}

int main() {
    int n;
    cin >> n;

    /*
    cout << countDistinctWays(n);
    */

    string arr[10] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};

    sayDigit(n, arr);

    return 0;
}