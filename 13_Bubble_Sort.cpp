# include<iostream>
# include<vector>

using namespace std;

void bubbleSort(int *arr, int n){
    bool swapped = false;
    for(int i=1; i<n; i++){
        for(int j=0; j<n-i; j++){
            if(arr[j]>arr[j+1]){
                swap(arr[j], arr[j+1]);
                swapped = true;
            }
        }
        if(swapped == false) {
            break;
        }
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

    bubbleSort(arr, n);

    return 0;
}