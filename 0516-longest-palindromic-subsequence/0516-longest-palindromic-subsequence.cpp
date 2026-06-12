class Solution {
public:
    int func(string t, string s, int n,int m,vector<vector<int>>&dp){
        int ans =0;
        for(int ind1=1;ind1<=n;ind1++){
            for(int ind2=1;ind2<=n;ind2++){
                if(t[ind1-1]==s[ind2-1]){
                    dp[ind1][ind2]=1+dp[ind1-1][ind2-1];
                    ans=max(ans,dp[ind1][ind2]);
                }
                else {
                    dp[ind1][ind2] = max(dp[ind1 - 1][ind2],
                                   dp[ind1][ind2 - 1]);
                }
            }
        }
        return dp[n][n];
    }
    int longestPalindromeSubseq(string s) {
        string t = s;// if empty it will return void
          reverse(t.begin(),t.end());
        int n = t.size();
        vector<vector<int>>dp(n+1,vector<int>(n+1,0));
        return func(t,s,n,n,dp);
    }
};