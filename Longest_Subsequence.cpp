#include<iostream>
#include<bits/stdc++.h>

using namespace std;

string printLongestSubstring(string a, string b) {
    int n = a.length();
    int m = b.length();

    vector<vector<int>> dp(n+1, vector<int> (m+1, 0));

    for(int i=0; i<=n; i++) dp[i][0] = 0;
    for(int j=0; j<=m; j++) dp[0][j] = 0;

    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            if(a[i-1] == b[j]) dp[i][j] = 1 + dp[i-1][j-1];
            else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        }
    }

    string ans = "";
    int i=n; 
    int j=m;

    while(i>0 && j>0){
        if(a[i-1]==b[j-1]){
            ans += a[i-1];
            i--;
            j--;
        }
        else if(dp[i-1][j]>dp[i][j-1]){
            j--;
        } else {
            i--;
        }
    }

    reverse(ans.begin(), ans.end());

    return ans;
}

int main() {
    string a = "abcde";
    string b = "ace";

    cout << printLongestSubstring(a, b);

    return 0;
}