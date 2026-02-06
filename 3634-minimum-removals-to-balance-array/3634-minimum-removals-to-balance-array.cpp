class Solution {
public:
    int minRemoval(vector<int>& nums, int k) {
        int n = nums.size();
        sort(nums.begin(), nums.end());

        int ans = n;
        int l = 0;

        for (int r = 0; r < n; r++) {
            while (nums[r] > (long long)nums[l] * k) {
                l++;
            }
            int window = r - l + 1;
            ans = min(ans, n - window);
        }
        return ans;
    }
};
