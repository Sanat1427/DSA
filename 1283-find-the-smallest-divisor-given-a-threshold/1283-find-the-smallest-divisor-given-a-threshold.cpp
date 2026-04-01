class Solution {
public:
bool possible(vector<int>&nums,int di , int sum){
    int ans=0;
    int n = nums.size();
    for(int i =0;i<n;i++){
     ans+=(nums[i]+di-1)/di;
    }
    return ans<=sum;
}
    int smallestDivisor(vector<int>& nums, int threshold) {
        int  n = nums.size();
        int low= 1;
        int high = *max_element(nums.begin(),nums.end());
        int div=1;
        while(low<=high){
            int mid=(low+high)/2;
            if(possible(nums,mid,threshold)){
                div=mid;
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return div;
    }
};