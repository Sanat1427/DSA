class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size();
        vector<int>ans;
        vector<int>dp(n,1);
        vector<int>parent(n);
        int maxi=0;
        int last=0;
        sort(nums.begin(),nums.end());
        for(int i =0;i<n;i++){
            parent[i]=i;
            for(int j =0;j<i;j++){
                if(nums[i]%nums[j]==0 && dp[i]<dp[j]+1){
                    dp[i]=dp[j]+1;
                    parent[i]=j;
                }
                if(dp[i]>maxi){
                    maxi=dp[i];
                    last=i;
                }
            }
            
        }
        int i = last;
            while(parent[i]!=i){
                ans.push_back(nums[i]);
                i=parent[i];
            }
            ans.push_back(nums[i]);
            return ans;
    }
};