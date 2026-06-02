class Solution {
public:
 bool func(vector<int>&arr, vector<vector<bool>>&dp,int ind , long long target){ 
    int n = arr.size();
   for(int i =0;i<n;i++){
    dp[i][0]= true; // target ==0
   }
   if(arr[0]<=target){
    dp[0][arr[0]]= true;
   }
   for(int ind =1;ind<n;ind++){
    for(int i=1;i<=target;i++){
        bool nott = dp[ind-1][i];
        bool taken = false;
        if(arr[ind]<=i){
            taken = dp[ind-1][i-arr[ind]];
        }
        dp[ind][i]= nott || taken;
    }
   }
   return dp[n-1][target];
 }
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        long long total =0;
        for(int i =0;i<n;i++){
            total+=nums[i];
        }
        if(total%2!=0)
        return false;
        else{
            long long k = total/2;
            vector<vector<bool>>dp(n,vector<bool>(k+1,false));
            return func(nums,dp,n-1,k);
        }
    }
};