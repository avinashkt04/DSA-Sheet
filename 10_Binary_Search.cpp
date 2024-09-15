#include<iostream>
using namespace std;

int binarySearch(int *arr, int size, int key){
    int start = 0;
    int end = size-1;

    int mid = start + (end-start)/2;

    while(start <= end){
        if(arr[mid] == key){
            return mid;
        }
        if(arr[mid]>key){
            end = mid-1;
        }
        else{
            start = mid+1;
        }

        mid = start + (end-start)/2;
    }
    return -1;
}

int firstOcc(int arr[], int n, int key){
    int s = 0, e = n-1;
    int mid = s + (e - s)/2;
    int ans = -1;
    while (s <= e)
    {
        if(arr[mid] == key){
            ans = mid;
            e = mid - 1;
        }
        else if(key > arr[mid]){
            s = mid + 1;
        }
        else{
            e = e - 1;
        }
        mid = s + (e - s)/2;
    }
    return ans;
}

int lastOcc(int arr[], int n, int key){
    int s = 0, e = n-1;
    int mid = s + (e - s)/2;
    int ans = -1;
    while (s <= e)
    {
        if(arr[mid] == key){
            ans = mid;
            s = mid + 1;
        }
        else if(key > arr[mid]){
            s = mid + 1;
        }
        else{
            e = e - 1;
        }
        mid = s + (e - s)/2;
    }
    return ans;
}

int peakIndex(int *arr, int n){
    int s = 0;
    int e = n-1;
    int mid = s + (e - s)/2;

    while(s<e){
        if(arr[mid] < arr[mid+1]){
            s = mid + 1;
        }
        else{
            e = mid;
        }
        mid = s + (e - s)/2;
    }
    return e;
}

int getPivot(int *arr, int n){
    int s = 0;
    int e = n-1;
    int mid = s + (e - s)/2;

    while(s<e){
        if(arr[mid] >= arr[0]){
            s = mid + 1;
        }
        else{
            e = mid;
        }
        mid = s + (e - s)/2;
    }
    return s;
}

long long int sqrtInteger(int n){
    int s = 0;
    int e = n;
    long long int ans = -1;

    while(s<=e){
        long long int mid = s + (e - s)/2;
        long long int square = mid * mid;
        if(square == n){
            return mid;
        }
        if(square < n){
            ans = mid;
            s = mid + 1;
        }
        else{
            e = mid - 1;
        }
    }
    return ans;
}

double morePrecision(int n, int precision, int tempSol){
    double factor = 1;
    double ans = tempSol;

    for(int i=0; i<precision; i++){
        factor = factor/10;
        for(double j=ans; j*j<n; j=j+factor){
            ans = j;
        }
    }
    return ans;
}

int main(){
    /*
    int even[6] = {2, 4, 6, 8, 12, 18};
    int odd[5] = {3, 8, 11, 14, 16};

    int index = binarySearch(even, 6, 18);

    cout<<"Index of 18 is "<<index;
    */

    /*
    // Find First and Last Position of Element in Sorted Array
    int even[11] = {1, 2, 3, 3, 3, 3, 3, 3, 3, 3, 5};
    cout << "First occurence of 3 is at Index "<< firstOcc(even, 11, 3) << endl;
    cout << "Last occurence of 3 is at Index "<< lastOcc(even, 11, 3);

    // Total no. of occurence --> (lastOcc - firstOcc) + 1;
    */

    /*
    // Peak Index in a Mountain Array
    int arr[5] = {3, 4, 5, 6, 2};
    cout << "Peak element in arr is at index " << peakIndex(arr, 5);
    */

    /*
    // Pivot element
    int arr[5] = {8, 10, 17, 1, 3};
    cout << "Pivot is " << getPivot(arr, 5) << endl; 
    */

    /**/
    int n;
    cout << "Enter the number: ";
    cin >> n;

    int tempSol = sqrtInteger(n);

    cout << "Answer is: " << morePrecision(n, 3, tempSol);

    return 0;
}


/*

// Square root of a number upto precision
#include<iostream>
int sqrtInteger(int n){
    int s = 0;
    int e = n;
    int ans = -1;

    while(s<=e) {
        int mid = s + (e-s)/2;
        if(mid * mid == n){
            return mid;
        } else if(mid * mid < n){
            ans = mid;
            s = mid + 1;
        } else {
            e = mid -1;
        }
    }
    return ans;
}

double morePrecision(int n, int precision, int tempSol) {
    double factor = 1;
    double ans = tempSol;
    for(int i = 0; i<precision; i++){
        factor = factor/10;
        for(double j=ans; j*j<n; j += factor){
            ans = j;
        }
    }
    return ans;
}

int main(){
    int n;
    std::cout << "Enter the value of n: ";
    std::cin >> n;
    int tempSol = sqrtInteger(n);
    std::cout << "Square root of " << n << " is " << morePrecision(n, 3, tempSol);
    return 0;
}

*/