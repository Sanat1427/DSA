class Solution {
public:
int func(vector<int>&nums, int req, vector<vector<int>>&dp ){
    int n=nums.size();
    if(nums[0]==0){
        dp[0][0]=2;

    }
    else 
    dp[0][0]=1;
    if(nums[0]!=0 && nums[0]<=req)
    dp[0][nums[0]]=1;
    for(int ind =1; ind<n;ind++){
        for(int tar = 0;tar<=req;tar++){
            int nottake = dp[ind-1][tar];
            int take = 0;
            if(nums[ind]<=tar){
            take = dp[ind-1][tar-nums[ind]];
            }
           dp[ind][tar]=(nottake+take);
        }
    }
    return dp[n-1][req];
}
    int findTargetSumWays(vector<int>& nums, int target) {
        //same approach as count subset in 2 partitions
        // s1-s2=target i.e. let => s1= all + values
        // s2= all -ve values
        // so s1+(-s2)
        // s1-s2=target
        int  n = nums.size();
        //vector<vector<int>>dp(n,vector<int>(target+1,0));
        int totalsum=0;
        for(int i =0;i<n;i++){
            totalsum+=nums[i];
        }
        if(totalsum-target<0||(totalsum-target)%2==1)
        return 0;
        int req= (totalsum-target)/2;
        vector<vector<int>>dp(n,vector<int>(req+1,0));
        return func(nums,req,dp);
    }
};