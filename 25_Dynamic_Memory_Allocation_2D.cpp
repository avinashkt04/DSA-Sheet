#include<iostream>
using namespace std;

int main(){
    /*
    int n;
    cin >> n;

    // Array Creation
    int** arr = new int*[n];
    for(int i=0; i<n; i++){
        arr[i] = new int[n];
    }

    // Taking Input
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin >> arr[i][j];
        }
    }

    // Printing Values
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
    */

    /*
    int row;
    cin >> row;

    int col;
    cin >> col;
    
    // Creating a 2D Array
    int** arr = new int*[row];
    for(int i=0; i<row; i++){
        arr[i] = new int[col];
    }

    // Taking Input
    for(int i=0; i<row; i++){
        for(int j=0; j<col; j++){
            cin >> arr[i][j];
        }
    }

    // Printing Output
    for(int i=0; i<row; i++){
        for(int j=0; j<col; j++){
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }

    // Releasing Memory
    for(int i=0; i<row; i++){
        delete []arr[i];
    }
    delete []arr;
    */

    // Jagged Array
    int n;
    cin >> n;

    // Allocate memory for the row size array
    int* rowArr = new int[n];
    // Input the number of columns for each row
    for(int i=0; i<n; i++){
        cin >> rowArr[i]; 
    }

    // Allocate memory for jagged array
    int** arr = new int*[n];
    for(int i=0; i<n; i++){
        arr[i] = new int[rowArr[i]];
    }

    // Input elements for each row
    for(int i=0; i<n; i++){
        for(int j=0; j<rowArr[i]; j++){
            cin >> arr[i][j];
        }
    }

    // Print the jagged array
    for(int i=0; i<n; i++){
        for(int j=0; j<rowArr[i]; j++){
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }

    // Releasing Memory
    for(int i=0; i<n; i++){
        delete []arr[i];
    }
    delete []arr;
    delete []rowArr;

    return 0;
}