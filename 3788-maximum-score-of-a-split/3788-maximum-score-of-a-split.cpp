class Solution {
public:
    long long maximumScore(vector<int>& nums) {
        int n = nums.size();
        long long sum =0;
        for(auto it : nums){
            sum+=it;
        }
       int   mini= INT_MAX;
        long long  ans = INT_MIN;
        for(int i =n-1;i>=1;i--){
            sum-=nums[i];
            mini=min(mini,nums[i]);
            long long x = sum-mini;
            ans= max(ans,x);
        } 
        
        return ans;
        
    }
};