class Solution {
public:
int func(int ind, vector<int>&arr,vector<int>&dp){
    if(ind==0)
    return arr[ind];
    if(ind<0)
    return 0;
    if(dp[ind]!=-1)
    return dp[ind];
    int pick = arr[ind]+func(ind-2,arr,dp);
    int nonpick=0+func(ind-1,arr,dp);
    return dp[ind]=max(pick,nonpick);
}
    int rob(vector<int>& nums) {
        int n = nums.size();
       vector<int>arr1;
       vector<int>arr2;
       if(n==1)
       return nums[0];
       
      
        vector<int> dp(n, -1);
      
       int ans1= func(n-1,nums,dp);
      
       return ans1;
    }
};