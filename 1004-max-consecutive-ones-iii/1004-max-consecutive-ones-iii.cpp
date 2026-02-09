class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n = nums.size();
        int l =0;
        int r=0;
        int maxi=0;
        int zeores=0;
        while(r<n){
            if(nums[r]==0){
                zeores++;
            }
            if(zeores>k){
                if(nums[l]==0){
                    zeores--;
                }
                l++;
            }
            if(zeores<=k){
             int len = r-l+1;
             maxi=max(maxi,len);
            }
            r++;
        }
        return maxi;
    }
};