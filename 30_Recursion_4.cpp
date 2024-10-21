#include<iostream>
using namespace std;

void reverse(string &str, int i, int j){
    if(i>j){
        return;
    }

    swap(str[i], str[j]);
    i++;
    j--;
    reverse(str, i, j);
}

bool checkPalindrome(string str, int i, int j){
    if(i>j){
        return  true;
    }
    if(str[i]!=str[j]){
        return false;
    } else {
        return checkPalindrome(str, i+1, j-1);
    }
}

int power(int a, int b){
    if(b==0){
        return 1;
    }

    if(b==1){
        return a;
    }

    int ans = power(a, b/2);

    if(b&1==0){
        return ans * ans;
    }
    else {
        return a * ans * ans;
    }
}

void sortArray(int *arr, int n){
    if(n==0 || n==1){
        return;
    }

    for(int i=0; i<n-1; i++){
        if(arr[i]>arr[i+1]){
            swap(arr[i], arr[i+1]);
        }
    }

    sortArray(arr, n-1);
}

int main() {
    /*
    // Reverse the string
    string name = "avinash";
    reverse(name, 0, name.length()-1);
    cout << "Name: " << name << endl;
    */

    /*
    // Palindrome
    string name = "abbccbba";
    bool isPalindrome = checkPalindrome(name, 0, name.length()-1);
    if(isPalindrome){
        cout << "Its a palindrome" << endl;
    } else {
        cout << "Its not a palindrome" << endl;
    }
    */

    /*
    // Power Calculation
    int a, b;
    cin >> a >> b;
    int ans = power(a, b);
    cout << "Answer is " << ans << endl;
    */

    // Bubble Sort
    int arr[5] = {2, 5, 1, 6, 9};

    sortArray(arr, 5);

    for(int i=0; i<5; i++){
        cout << arr[i] << " ";
    }

    return 0;
}