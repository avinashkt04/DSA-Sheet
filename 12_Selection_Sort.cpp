# include<iostream>
# include<vector>

using namespace std;

void selectionSort(int *arr, int n){
    for(int i=0; i<n-1; i++){
        int minIndex = i;

        for(int j=i+1; j<n; j++){
            if(arr[minIndex] > arr[j]){
                minIndex = j;
            }
        }
        swap(arr[minIndex], arr[i]);
    }
    cout << "Sorted array: ";
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

    selectionSort(arr, n);

    return 0;
}