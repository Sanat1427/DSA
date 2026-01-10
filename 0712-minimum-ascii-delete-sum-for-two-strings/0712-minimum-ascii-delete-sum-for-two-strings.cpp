class Solution {
public:
int solve(int i , int j ,string &s1, string &s2, vector<vector<int>>&dp){
    int n = s1.size();
    int m = s2.size();
    if(i>=n && j>=m)
    return 0;
  
    if(i>=n)
    return dp[i][j]=s2[j]+solve(i,j+1,s1,s2,dp);
    if(j>=m)
    return dp[i][j]= s1[i]+solve(i+1,j,s1,s2,dp);
    if(dp[i][j]!=-1)
    return dp[i][j];
    if(s1[i]==s2[j])
    return dp[i][j]= solve(i+1,j+1,s1,s2,dp);
    // two option 
    int des1= s1[i]+solve(i+1,j,s1,s2,dp);
    int des2=s2[j]+solve(i,j+1,s1,s2,dp);
    return dp[i][j]=min(des1,des2);
}
    int minimumDeleteSum(string s1, string s2) {
         int n = s1.size();
    int m = s2.size();
         vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
        return solve(0,0,s1,s2,dp);
    }
};