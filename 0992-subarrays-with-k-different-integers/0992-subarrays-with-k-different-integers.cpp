class Solution {
public:
int func(vector<int>&nums, int k){
    int n = nums.size();
    int l =0;
    int cnt =0;
    unordered_map<int,int>mpp;
    for(int right =0; right<n;right++){
        if(mpp[nums[right]]==0){
            //means we got the distinct element
             k--;
        }
             mpp[nums[right]]++;
        
        while(k<0){
            mpp[nums[l]]--;
            if(mpp[nums[l]]==0){
                mpp.erase(nums[l]);
               k++;
            }
            l++;
            
        }
        cnt+=right-l+1;
        
    }
    return cnt;

}
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        int n = nums.size();
        return func(nums,k)-func(nums,k-1);
    }
};