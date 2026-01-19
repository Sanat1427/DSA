class Solution {
public:
int func(int ind,vector<int>&coins,vector<vector<int>>&dp,int amount){
    //base case
    if(ind==0){
        if(amount%coins[ind]==0)
        return amount/coins[ind];
        return 1e9;
    }
    if(dp[ind][amount]!=-1)
    return dp[ind][amount];
    int nottaken= func(ind-1,coins,dp,amount);
    int taken=1e9;
    if(coins[ind]<=amount){
        taken=1+func(ind,coins,dp,amount-coins[ind]);
    }

    return dp[ind][amount]=min(taken,nottaken);

}
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
     vector<vector<int>>dp(n,vector<int>(amount+1,-1));
     int ans = func(n-1,coins,dp,amount);
     if(ans>=1e9)
     return -1;
     return ans;
    }
};