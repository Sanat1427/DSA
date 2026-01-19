class Solution {
public:
int ways( int amount,vector<int>& coins ){
    int n =coins.size();
    vector<vector<int>>dp(n,vector<int>(amount+1,0));
    for(int i =0;i<=amount;i++){
        if(i%coins[0]==0)
        dp[0][i]=1;
    }
    for(int ind =1;ind<n;ind++){
        for(int tar=0;tar<=amount;tar++){
            int notake= dp[ind-1][tar];
            int take = 0;
            if(coins[ind]<=tar){
              take=dp[ind][tar-coins[ind]];
            }
            dp[ind][tar]=(take+notake);
        }
    }
    return dp[n-1][amount];
}
    int change(int amount, vector<int>& coins) {
        int ans = ways(amount,coins);
        return ans;

    }
};