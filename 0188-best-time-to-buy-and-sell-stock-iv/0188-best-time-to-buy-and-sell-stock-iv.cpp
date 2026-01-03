class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>>dp(n+1,vector<vector<int>>(2,vector<int>(k+1,0)));
        for(int i = n-1;i>=0;i--){
            for(int b=0;b<=1;b++){
                for(int c=1;c<=k;c++){
                    if(b==0)
                    dp[i][b][c]=max(dp[i+1][0][c],-1*prices[i]+dp[i+1][1][c]);
                    if(b==1)
                    dp[i][b][c]=max(dp[i+1][1][c],prices[i]+dp[i+1][0][c-1]);
                }
            }
        }
        return dp[0][0][k];
    }
};