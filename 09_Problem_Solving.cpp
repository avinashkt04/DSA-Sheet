#include<iostream>
using namespace std;

void printArray(int *arr, int n){
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";                                     
    }cout << endl;
    
}

void swapAlternate(int *arr, int size){

    for(int i=0; i<size; i+=2){
        if(i+1 < size){
            swap(arr[i], arr[i+1]);
        }
    }

}

int findUnique(int *arr, int size){
    int ans = 0;

    for(int i=0; i<size; i++){
        ans = ans ^ arr[i];
        // cout << ans;
    }

    return ans;
}

int findDuplicate(int *arr, int size){
    int ans = 0;

    // XOR ing all array element
    for(int i=0; i<size; i++){
        ans = ans ^ arr[i];
    }

    cout << endl;
    // XOR [1, n-1]
    for(int i=1; i<size; i++){
        ans = ans ^ i;
    }

    return ans;
}

int main(){
    /*
    // Alternate Swapping
        int even[8] = {5, 2, 9, 4, 7, 6, 1, 0};
        int odd[5] = {11, 33, 9, 76, 43};

        swapAlternate(even, 8);
        printArray(even, 8);
        swapAlternate(odd, 5);
        printArray(odd, 5);
    */

    // /*
    // Find unique element
    int arr[] = {2, 4, 6, 7, 4, 2, 6};

    cout << findUnique(arr, 8);
    // */

    // Unique no. of occurence 
    
    /*
    // Find Duplicate
    int arr[] = {8, 7, 2, 5, 4, 7, 1, 3, 6};

    cout << findDuplicate(arr, 9);
    */

    /**/
    // Intersection of TWO Arrays
    
    // found solution in notebook and on code studio
    

    return 0;
}