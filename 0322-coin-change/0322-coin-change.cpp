class Solution {
public:
    int func(int ind, vector<int>&coins,vector<vector<int>>&dp, int target){
       if(ind==0){
        if(target%coins[0]==0)
        return target/coins[0];
        else
        return 1e9;
       }
       if(dp[ind][target]!=-1)
       return dp[ind][target];
       int nottaken = func(ind-1,coins,dp,target);
       int taken =1e9;
       if(coins[ind]<=target){
        taken= 1+func(ind,coins,dp,target-coins[ind]);
       }
        return dp[ind][target]= min(taken,nottaken);
    }
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>>dp(n,vector<int>(amount+1,-1));
        int ans = func(n-1,coins,dp,amount);
          return (ans >= 1e9) ? -1 : ans;
    }
};