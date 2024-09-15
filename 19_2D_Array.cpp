#include <iostream>

using namespace std;

bool isPresent(int arr[][3], int target, int row, int col)
{
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            if (arr[i][j] == target)
            {
                return 1;
            }
        }
    }
    return 0;
}

// to print row wise sum
void printSum(int arr[][3], int row, int col)
{
    for (int i = 0; i < row; i++)
    {
        int sum = 0;
        for (int j = 0; j < col; j++)
        {
            sum += arr[i][j];
        }
        cout << sum << " ";
    }
}

int largestRowSum(int arr[][3], int row, int col)
{
    int maxi = INT_MIN;
    int rowIndex = -1;
    for (int i = 0; i < row; i++)
    {
        int sum = 0;
        for (int j = 0; j < col; j++)
        {
            sum += arr[i][j];
        }
        if (maxi < sum)
        {
            maxi = sum;
            rowIndex = i;
        }
    }
    cout << "The maximum sum is: " << maxi << endl;
    return rowIndex;
}

int main()
{
    // create 2d array
    // int arr[3][3] = {1, 2, 3, 3, 5, 6, 7, 8, 9, 10, 11, 12};
    // int arr[3][3] = {{1, 11, 111, 1111}, {2, 22, 222, 2222}, {3, 33, 333, 3333}};
    int arr[3][3];

    // taking input -> row wise input
    cout << "Enter the elements: ";
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cin >> arr[i][j];
        }
    }

    /*
    // taking input -> column wise input
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            cin >> arr[j][i];
        }
    }
    */

    /*
    // print
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
     */

    /*
    int target;
    cout << "Enter the target: ";
    cin >> target;
    if(isPresent(arr, target, 3, 3)){
        cout << "Element found";
    } else {
        cout << "Element not found";
    }

   printSum(arr, 3, 3);
    */

    int ansIndex = largestRowSum(arr, 3, 3);
    cout << "Max row is at index: " << ansIndex;

    return 0;
}