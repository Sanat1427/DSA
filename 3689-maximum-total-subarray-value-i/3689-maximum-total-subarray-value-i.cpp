class Solution {
public:
    long long maxTotalValue(vector<int>& nums, int k) {
        int n = nums.size();
        int l =0;
        int r=0;
        long long mini = *min_element(nums.begin(),nums.end());
        long long maxi =*max_element(nums.begin(),nums.end());
        return (maxi-mini)*k;
    }
};