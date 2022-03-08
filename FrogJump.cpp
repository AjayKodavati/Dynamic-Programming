//memoization Approach

#include<bits/stdc++.h>
int dp[100001];

int getMinimumEnergyRequired(int n, vector<int>& heights, int currIdx){
    if(currIdx == n - 1)
        return 0;
    if(dp[currIdx] != -1)
        return dp[currIdx];
  
    int oneStep = 10001, twoSteps = 10001;
  
    if(currIdx + 1 < n)
    	 oneStep = abs(heights[currIdx] - heights[currIdx + 1]) + getMinimumEnergyRequired(n, heights, currIdx + 1);
    if(currIdx + 2 < n)
       twoSteps = abs(heights[currIdx] - heights[currIdx + 2]) + getMinimumEnergyRequired(n, heights, currIdx + 2);
    
    dp[currIdx] = min(oneStep, twoSteps);
    
    return dp[currIdx];
}

int frogJump(int n, vector<int> &heights){
    // Write your code here.
    memset(dp, -1, sizeof dp);
    return getMinimumEnergyRequired(n, heights, 0);
}

//tabulation approach
int frogJump(int n, vector<int> &height){
    // Write your code here.
    vector<int> dp(n + 1, -1);
    dp[n] = 0;// forg is intially at nth starir
    dp[n - 1] = abs(height[n - 1] - height[n - 2]); //energy required by frog to reach nth stair from (n-1)th stair
    
    for(int i = n - 2; i >= 0; i--){
        int oneStep = dp[i + 1] + abs(height[i] - height[i-1]);
        int twoSteps = dp[i + 2] + abs(height[i-1] - height[i+1]);
        
        dp[i] = min(oneStep, twoSteps);
    }
    return dp[1];
}
