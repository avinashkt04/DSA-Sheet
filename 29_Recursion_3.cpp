#include <iostream>
using namespace std;

bool isSorted(int *arr, int size)
{
    if (size == 0 || size == 1)
        return true;

    if (arr[0] > arr[1])
        return false;
    else
    {
        bool remainingPart = isSorted(arr + 1, size - 1);
        return remainingPart;
    }
}

int getSum(int *arr, int size){
    if(size==0)
        return 0;
    
    if(size==1)
        return arr[0];

    int sum = arr[0] + getSum(arr+1, size-1);
    return sum;
}

void print(int *arr, int n){
    cout << "Size of array is: " << n << endl;

    for(int i=0; i<n; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}
bool linearSearch(int *arr, int size, int key){
    print(arr, size);
    if(size==0)
        return false;

    if(arr[0]==key){
        return true;
    }
    else{
        bool remainingPart = linearSearch(arr+1, size-1, key);
        return remainingPart;
    }
}

bool binarySeach(int *arr, int s, int e, int k){
    if(s>e)
        return false;
    
    int mid = s + (e-s)/2;

    if(arr[mid] == k)
        return true;
    
    if(arr[mid] < k){
        return binarySeach(arr, mid+1, e, k);
    }
    else {
        return binarySeach(arr, s, mid-1, k);
    }
}

int main()
{
    // int arr[5] = {3, 5, 1, 2, 6};
    // int size = 5;
    /*
    bool ans = isSorted(arr, size);

    if (ans)
    {
        cout << "Array is sorted";
    }
    else
    {
        cout << "Array is not sorted";
    }
    */

    /*
    int sum = getSum(arr, size);

    cout << "Sum is " << sum << endl;
    */

    /*
    int key = 2;
    bool ans = linearSearch(arr, size, key);
    
    if(ans){
        cout << "Present" << endl;
    }
    else{
        cout << "Absent" << endl;
    }
    */

    int arr[6] = {2, 4, 6, 10, 14, 18};
    int size = 6;
    int key = 18;

    cout << "Present or not "<< binarySeach(arr, 0, 6, key);

    return 0;
}