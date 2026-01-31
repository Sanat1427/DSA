class Solution {
public:
int func(int i, int prev, vector<int>&nums,vector<vector<int>>&dp){
    if(i==nums.size()-1){
        if(prev==-1 || nums[prev]<nums[i])
        return 1;
        return 0;
    }
    if(dp[i][prev+1]!=-1)
    return dp[i][prev+1];
    int notake=func(i+1,prev,nums,dp);
    int take=0;
    if(prev==-1||nums[i]>nums[prev])
    take=func(i+1,i,nums,dp)+1;
    return dp[i][prev+1]=max(notake,take);
}
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>>dp(n,vector<int>(n+1,-1));
        return func(0,-1,nums,dp);
    }
};