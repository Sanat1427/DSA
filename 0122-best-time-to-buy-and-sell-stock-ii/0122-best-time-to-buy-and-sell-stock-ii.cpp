class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
       vector<vector<int>>dp(n+1,vector<int>(2,-1));
       dp[n][0]=0;
       dp[n][1]=0;
       int profit =0;
       for(int i = n-1;i>=0;i--){
        for(int b=0;b<=1;b++){
            if(b==0)
            profit = max(dp[i+1][0],-1*prices[i]+dp[i+1][1]);
            if(b==1)
            profit=max(dp[i+1][1],prices[i]+dp[i+1][0]);
            dp[i][b]=profit;
        }
       }
       return dp[0][0];
    }
};