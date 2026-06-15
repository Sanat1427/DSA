class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>>dp(n+2,vector<int>(2,0));
        for(int i= n-1;i>=0;i--){
            for(int h =0;h<=1;h++){
                //holding the stock
                // i+2 as if we sell today so we need cooldown for next day that's why i+2
                if(h==1){
            dp[i][1]=max(prices[i]+dp[i+2][0],dp[i+1][1]);
                }
                else if (h==0){
                    dp[i][0]=max(-prices[i]+dp[i+1][1],dp[i+1][0]);
                }
            }
        }
        return dp[0][0];
    }
};