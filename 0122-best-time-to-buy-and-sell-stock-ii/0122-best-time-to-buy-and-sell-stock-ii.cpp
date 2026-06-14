class Solution {
public:
    int func(int ind, int buy, int n, vector<int>&prices,vector<vector<int>>&dp){
        if(ind==n)
        return 0;
        if(dp[ind][buy]!=-1)
        return dp[ind][buy];
        int price =0;
        //buy
        if(buy==0){
            price =max(func(ind+1,0,n,prices,dp),-1*prices[ind]+func(ind+1,1,n,prices,dp) );
        }
        //sell
        else if (buy==1){
             price =max(func(ind+1,1,n,prices,dp),prices[ind]+func(ind+1,0,n,prices,dp) );
        }
        return dp[ind][buy]=price;
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>>dp(n,vector<int>(2,-1));
        return func(0,0,n,prices,dp);
    }
};