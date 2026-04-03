class Solution {
public:
int canpart(vector<int>&nums, int maxi){
    int paritions=1;
    long long sub =0;
    int n = nums.size();
    for(int i =0;i<n;i++){
        if(sub+nums[i]<=maxi){
            sub+=nums[i];
        }
        else{
            paritions++;
            sub=nums[i];
        }
    }
    return paritions;
}
    int splitArray(vector<int>& nums, int k) {
        int n = nums.size();
        int low = *max_element(nums.begin(),nums.end());
        int high = accumulate(nums.begin(),nums.end(),0);
        while(low<=high){
            int mid= (low+high)/2;
            int partitions= canpart(nums,mid);
            if(partitions>k){
                low=mid+1;
            }
            else{
                high=mid-1;
            }
        }
        return low;
    }
};