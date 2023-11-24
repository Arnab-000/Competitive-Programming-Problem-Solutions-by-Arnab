#include <bits/stdc++.h> 

int memo(vector<int> &nums, vector<int> &dp, int n){
    if(n == 0) return dp[n] = nums[0];
    if(dp[n] != -1) return dp[n];

    int incl = memo(nums, dp, n-2) + nums[n];
    int excl = memo(nums, dp, n-1);
    dp[n] = max(incl, excl);
    return dp[n];
}

int tabl(vector<int> &nums){
    int n = nums.size();
    vector<int> dp(n+1, -1);
    dp[0] = nums[0];
    dp[1] = max(nums[0], nums[1]);
    for(int i = 2; i < n; i++){
        int incl = nums[i] + dp[i - 2];
        int excl = dp[i - 1];
        dp[i] = max(incl,excl);
    }
    return dp[n-1];
}


int maximumNonAdjacentSum(vector<int> &nums){
    // Write your code here.
    // int n = nums.size();
    // vector<int> dp(n+1, -1);
    // memo(nums, dp, n-1);
    // return dp[n-1];
    return tabl(nums);
}