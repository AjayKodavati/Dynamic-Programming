//Memoisation
int getMaxSum(vector<int>&nums, int currIdx, vector<int>& dp){
    if(currIdx >= nums.size())
        return 0;
    
    if(dp[currIdx] != -1)
        return dp[currIdx];
    
    int consider = nums[currIdx] + getMaxSum(nums, currIdx + 2, dp);
    int notConsider = getMaxSum(nums, currIdx + 1, dp);
    
    dp[currIdx] = max(consider, notConsider);
    
    return dp[currIdx];
}

//tabulation
int n = nums.size();
    vector<int> dp(n, -1);
    dp[0] = nums[0];
    dp[1] = nums[1];
    for(int i = 2; i < n; i++){
        int consider = dp[i - 2] + nums[i];
        int notConsider = dp[i - 1];
        dp[i] = max(consider, notConsider);
    }
    return dp[n-1];
}
