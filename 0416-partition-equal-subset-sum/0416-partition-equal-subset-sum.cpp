class Solution {
public:
bool func(int ind,vector<int>& nums,  vector<vector<int>>&dp,int k){
  if(k==0)
  return true;
  if(ind==0)
  return nums[0]==k;
  if(dp[ind][k]!=-1)
  return dp[ind][k];
  bool notaken = func(ind-1,nums,dp,k);
  bool taken = false;
  if(nums[ind]<=k)
  taken=func(ind-1,nums,dp,k-nums[ind]);
  return dp[ind][k]=notaken||taken;
}
    bool canPartition(vector<int>& nums) {
        int n= nums.size();
        int totalsum =0;
        for(int i =0;i<n;i++){
            totalsum+=nums[i];
        }
        if(totalsum%2==1)
        return false;
        else{
            int k = totalsum/2;
            vector<vector<int>>dp(n,vector<int>(k+1,-1));
            return func(n-1,nums,dp,k);

        }
    }
};