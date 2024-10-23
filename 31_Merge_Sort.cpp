#include<iostream>
using namespace std;

/*
// Create new array and copy it
void merge(int *arr, int s, int e){
    int mid = s + (e-s)/2;

    int len1 = mid - s + 1;
    int len2 = e - mid;

    int *first = new int[len1];
    int *second = new int[len2];

    // copy values
    int mainArrayIndex = s;
    for(int i=0; i<len1; i++){
        first[i] = arr[mainArrayIndex++];
    }

    mainArrayIndex = mid + 1;
    for(int i=0; i<len2; i++){
        second[i] = arr[mainArrayIndex++];
    }

    int index1 = 0;
    int index2 = 0;
    mainArrayIndex = s;

    while(index1 < len1 && index2 < len2) { 
        if(first[index1]  < second[index2]){
            arr[mainArrayIndex++] = first[index1++];
        }
        else{
            arr[mainArrayIndex++] = second[index2++];
        }
    }

    while(index1 < len1){
        arr[mainArrayIndex++] = first[index1++];
    }

    while(index2 < len2){
        arr[mainArrayIndex++] = second[index2++];
    }

    delete []first;
    delete []second;
}
*/

// Use index
void merge(int *arr, int s, int e){
    int mid = s + (e - s)/2;

    int index1 = s;
    int index2 = mid + 1;

    while(index1 <= mid && index2 <= e){
        if (arr[index1] <= arr[index2]) {
            index1++;
        } else {
            int value = arr[index2];
            int tempIndex = index2;

            while (tempIndex > index1) {
                arr[tempIndex] = arr[tempIndex - 1];
                tempIndex--;
            }

            arr[index1] = value;

            index1++;
            mid++;
            index2++;
        }
    }
}

void mergeSort(int *arr, int s, int e){
    // base case
    if(s>=e){
        return;
    }

    int mid = s + (e-s)/2;
    // left part sorting
    mergeSort(arr, s, mid);

    // right part sorting
    mergeSort(arr, mid+1, e);

    // merge
    merge(arr, s, e);
}


int main() {
    int arr[5] = {2, 5, 1, 6, 9};
    int n = 5;

    mergeSort(arr, 0, n-1);

    for(int i=0; i<n; i++){
        cout << arr[i] << " ";
    }

    return 0;
}