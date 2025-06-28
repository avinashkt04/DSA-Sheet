#include<iostream>
#include<vector>
using namespace std;

// Print subarray with maximum subarray sum

// Kadane's algo

vector<int> maxSubarraySum(vector<int> &nums){
    int n = nums.size();

    int ansStart = -1;
    int ansEnd = -1;

    int start = -1;

    int maxi = INT_MIN;
    int currSum = 0;

    for(int i=0; i<n; i++){
        if(currSum==0) start = i;
        currSum += nums[i];

        if(currSum > maxi){
            maxi = currSum;
            ansStart = start;
            ansEnd = i;
        }

        if(currSum < 0){
            currSum = 0;
        }
    }

    vector<int> ans;

    for(int i=ansStart; i<=ansEnd; i++){
        ans.push_back(nums[i]);
    }

    return ans;
}

int main() {
    vector<int> nums = {-2,1,-3,4,-1,2,1,-5,4};

    vector<int> ans = maxSubarraySum(nums);

    for(int i=0; i<ans.size(); i++){
        cout << ans[i] << " ";
    }

    cout << endl;

    return 0;
}