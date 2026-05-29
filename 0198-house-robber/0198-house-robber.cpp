class Solution {
public:
int func(vector<int>&dp,vector<int>&nums,int ind){
    if(ind ==0){
        return nums[ind];
    }
    if(ind<0)
    return 0;
    if(dp[ind]!=-1){
        return dp[ind];
    }
     int np = 0+func(dp,nums,ind-1);
     int p = nums[ind]+func(dp,nums,ind-2);
     return dp[ind]= max(p,np);

}
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int>dp(n,-1);
        return func(dp,nums,n-1);
    }
};