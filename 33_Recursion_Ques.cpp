#include<iostream>
#include<vector>
using namespace std;

void printSubsets(vector<vector<int>>& ans){
    for(int i=0; i<ans.size(); i++){
        cout << "[ ";
        for(int j=0; j<ans[i].size(); j++){
            cout << ans[i][j] << " ";
        }
        cout << "]";
    }
}

void printSubs(vector<string> ans){
    for(int i=0; i<ans.size(); i++){
        cout << ans[i] << " "; 
    }
}

void subsets(vector<int> nums, vector<int> output, vector<vector<int>>& ans, int index){
    // base case
    if(index >= nums.size()){
        ans.push_back(output);
        return;
    }

    // exclusive
    subsets(nums, output, ans, index+1);

    // inclusive
    int element = nums[index];
    output.push_back(element);
    subsets(nums, output, ans, index+1);
}

void subsequences(string str, string output, vector<string>& ans, int index){
    // base case
    if(index >= str.length()){
        if(output.length()>0){
			ans.push_back(output);
		}
        return;
    }

    // exclusive
    subsequences(str, output, ans, index+1);

    // inclusive
    char element = str[index];
    output.push_back(element);
    subsequences(str, output, ans, index+1);
}

void permutation(vector<int> nums, vector<vector<int>>& ans, int index){
    // base case
    if(index >= nums.size()){
        ans.push_back(nums);
        return;
    }

    for(int j=index; j<nums.size(); j++){
        swap(nums[index], nums[j]);
        permutation(nums, ans, index+1);
        // backtrack
        swap(nums[index], nums[j]);
    }
}

int main() {

    /*
    // Subsets
    vector<int> nums = {1, 2, 3};
    vector<vector<int>> ans;
    vector<int> output;
    int index = 0;
    subsets(nums, output, ans, index);

    printSubsets(ans);
    */

    /*
    // Subsequences
    string str = "abc";
    string output = "";
    vector<string> ans;
    int index = 0;
    subsequences(str, output, ans, index);

    printSubs(ans);
    */

    // Permutaion
    vector<int> nums = {1,2,3};
    vector<vector<int>> ans;
    int index = 0;
    permutation(nums, ans, index);
    
    printSubsets(ans);

    return 0;
}