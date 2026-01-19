class Solution {
public:
int func(int ind, vector<int>&nums,int target){
    vector<vector<int>>dp(ind+1,vector<int>(target+1,0));
    if( nums[0]==0)
    dp[0][0]=2;
    else 
    dp[0][0]=1;
    if(nums[0]!=0 && nums[0]<=target)
    dp[0][nums[0]]=1;
    for(int i =1;i<ind;i++){
        for(int tar=0;tar<=target;tar++){
            int nottaken = dp[i-1][tar];
            int taken = 0;
            if(nums[i]<=tar)
            taken=dp[i-1][tar-nums[i]];

            dp[i][tar]=(taken+nottaken);
            
        }
    }
return dp[ind-1][target];
}
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        int totalsum=0;
        for(int i =0;i<n;i++)
        totalsum+=nums[i];
        if(totalsum-target<0 || (totalsum-target)%2==1) return 0;
        int s2= (totalsum-target)/2;
        int ans = func(n,nums,s2);
        return ans;
    }
};