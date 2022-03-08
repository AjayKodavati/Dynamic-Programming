int getMinEnergy(int currIdx ,int k, vector<int>& height){
    
    int n = height.size();
    if(currIdx == n - 1)
        return 0;
    
    if(currIdx >= n)
        return 10001;
    int ans = INT_MAX;
    for(int i = 1; i <= k; i++){
        if(currIdx + i < n){
            int steps = abs(height[currIdx + i] - height[currIdx]) + getMinEnergy(currIdx + i, k, height);
            ans = min(ans, steps);
        }
    }
    return ans;
}

//tabulation approach

int getMinEnergy(int n, int k, vector<int>& height){
  vector<int> dp(n);
  dp[0] = 0;
  
  for(int i = 1; i < n; i++){
    int minEne = INT_MAX;
    for(int j = 1; j <= k; j++){
      if(i - j >= 0){
          int jump = dp[i - j] + abs(height[i] - height[i - j]);
          minEne = min(minEne, jump);
      }
    }
    dp[i] = minEne;
  }
  return dp[n-1];
}
    
