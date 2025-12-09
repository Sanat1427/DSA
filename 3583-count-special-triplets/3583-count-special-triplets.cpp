class Solution {
public:
    int specialTriplets(vector<int>& nums) {
        const int MOD = 1e9 + 7;
        int n = nums.size();
        if (n < 3) return 0;

        long long cnt = 0;
        unordered_map<long long, int> leftFreq, rightFreq;

        for (int i = 0; i < n; ++i) {
            rightFreq[nums[i]]++;
        }

        for (int j = 0; j < n; ++j) {
            rightFreq[nums[j]]--;
            long long target = 2LL * nums[j];
            long long leftCount = leftFreq.count(target) ? leftFreq[target] : 0;
            long long rightCount = rightFreq.count(target) ? rightFreq[target] : 0;
            cnt = (cnt + (leftCount * rightCount) % MOD) % MOD;
            leftFreq[nums[j]]++;
        }

        return (int)cnt;
    }
};