class Solution {
public:
    int func ( int n ,vector<int>&coins,vector<vector<int>>&dp, int amount){
        for(int i =0;i<=amount;i++){
            if(i%coins[0]==0 && coins[0]!=0)
            dp[0][i]=1;
        }
        for(int i = 1;i<n;i++){
            for(int tar= 0;tar<=amount;tar++){
                long long  nottake = dp[i-1][tar];
                long long take =0;
                if(coins[i]<=tar){
                    take= dp[i][tar-coins[i]];
                }
                dp[i][tar]= (take+nottake);
            }
        }
        return dp[n-1][amount];
    }
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>>dp(n,vector<int>(amount+1,0));
        return func(n,coins,dp,amount);
    }
};