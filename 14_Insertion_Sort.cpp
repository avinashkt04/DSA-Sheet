# include<iostream>

using namespace std;

void insertionSort(int *arr, int n){
    // for(int i=1; i<n; i++){
    //     int temp = arr[i];
    //     int j = i-1;
    //     for(;j>=0; j--){
    //         if(arr[j]>temp){
    //             arr[j+1] = arr[j];
    //         }
    //         else{
    //             break;
    //         }
    //     }
    //     arr[j+1] = temp;
    // }

    int i=1;
    while(i<n){
        int temp = arr[i];
        int j = i-1;
        while(j>=0 && arr[j]>temp){
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = temp;
        i++;
    }

    cout << "Sorted Array: " ;
    for(int i=0; i<n; i++){
        cout << arr[i] << " ";
    }
}

int main() {
    int n;
    cout << "Enter the value of n: ";
    cin >> n;

    int arr[n];
    cout << "Enter the value of array: ";
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }

    insertionSort(arr, n);

    return 0;
}