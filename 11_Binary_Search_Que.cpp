#include<iostream>
#include<vector>

using namespace std;

bool isPossible(vector<int>&arr, int n, int m, int mid){
    int studentCount = 1;
    int pageSum = 0;

    for(int i=0; i<n; i++){
        if((pageSum + arr[i])<=mid){
            pageSum += arr[i];
        }
        else{
            studentCount++;
            if(studentCount > m || mid < arr[i]){
                return false;
            }
            pageSum = arr[i];
        }
    }
    return true;
}

int findPages(vector<int>&arr, int n, int m){
    if(m>n){
        return -1;
    }

    int sum = 0;
    for(int i=0; i<n; i++){
        sum += arr[i];
    }

    int start = 0;
    int end = sum;
    int ans = -1;
    while(start <= end){
        int mid = start + (end-start)/2;

        if(isPossible(arr, n, m, mid)){
            end = mid - 1;
            ans = mid;
        }
        else{
            start = mid + 1;
        }
    }
    return ans;
}

int main() {
    vector<int> pages = {12, 34, 67, 90};
    int n = pages.size(); 
    int m = 2;

    int result = findPages(pages, n, m);
    cout << "Minimum number of pages: " << result << endl;

    return 0;
}