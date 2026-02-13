class Solution {
public:
    int distinct(vector<int>& nums, int k){
        int n = nums.size();
        int l = 0, r = 0;
        int ans = 0;
        unordered_map<int,int> mpp;

        while(r < n){
            if(mpp[nums[r]]++ == 0){
                k--;
            }

            while(k < 0){
                mpp[nums[l]]--;
                if(mpp[nums[l]] == 0){
                    k++;
                }
                l++;
            }

            ans += r - l + 1;
            r++;
        }
        return ans;
    }

    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return distinct(nums, k) - distinct(nums, k - 1);
    }
};
