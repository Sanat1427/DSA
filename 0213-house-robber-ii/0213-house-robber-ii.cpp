class Solution {
public:
    int func(vector<int>& arr) {
        int n = arr.size();

        vector<int> dp(n, -1);
        dp[0] = arr[0];

        for(int i = 1; i < n; i++) {
            int p = arr[i];
            if(i > 1)
                p += dp[i - 2];

            int np = dp[i - 1];

            dp[i] = max(p, np);
        }

        return dp[n - 1];
    }

    int rob(vector<int>& nums) {
        int n = nums.size();

        if(n == 1) return nums[0];

        vector<int> arr1, arr2;

        for(int i = 0; i < n; i++) {
            if(i != 0) arr1.push_back(nums[i]);
            if(i != n - 1) arr2.push_back(nums[i]);
        }

        int ans1 = func(arr1);
        int ans2 = func(arr2);

        return max(ans1, ans2);
    }
};