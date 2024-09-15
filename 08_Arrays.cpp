#include<iostream>
using namespace std;

void printArray(int arr[], int size){
      for (int i = 0; i < size; i++)
      {
         cout << arr[i] << " ";
      }
}

int getMax(int arr[], int n){
   int maxi = INT_MIN;

   for (int i = 0; i < n; i++)
   {

      maxi = max(maxi, arr[i]);

      // if(arr[i]>maxi){
      //    maxi = arr[i];
      // }
   }
   
   return maxi;
}

int getMin(int arr[], int n){
   int mini = INT_MAX;

   for (int i = 0; i < n; i++)
   {

      mini = min(mini, arr[i]);

      // if(arr[i]<mini){
      //    mini = arr[i];
      // }
   }
   
   return mini;
}

bool search(int arr[], int size, int key){
   for (int i = 0; i < size; i++)
   {
      if(arr[i] == key){
         return 1;
      }
   }
   
   return 0;
}

void reverse(int arr[], int n){
   int start = 0;
   int end = n-1;

   while(start<end){
      swap(arr[start], arr[end]);
      start++;
      end--;
   }
}

int main(){

   // Declare
   int number[15] = {1};

   // printArray(number, 15);
   int numberSize = sizeof(number)/sizeof(int);
   // cout << endl << numberSize << endl;
   

   // Max and Min element of Array
   /*
      int size;
      cin >> size;

      int arr[size];

      // Taking input in Array
      for (int i = 0; i < size; i++)
      {
         cin >> arr[i];
      }

      cout << "Maximum value is " << getMax(arr, size) << endl;
      cout << "Minimum value is " << getMin(arr, size) << endl;
   */

   // Linear Search
   /*
      int key;
      cout << "Enter the key to search for: ";
      cin >> key;

      bool found = search(arr, size, key);

      if(found){
         cout << "Key is present" << endl;
      }
      else{
         cout << "Key is absent" << endl;
      }
   */

   // Reverse an Array
   int arr[6] = {1, 4, 0, 5, -2, 15};
   int brr[5] = {2, 6, 3, 9, 5};

   reverse(arr, 6);
   reverse(brr, 5);

   printArray(arr, 6);
   cout << endl;
   printArray(brr, 5);

   return 0;
}