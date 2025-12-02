class Solution {
    const int mod = 1e9 + 7;

public:
    int countTrapezoids(vector<vector<int>>& points) {
        unordered_map<int, int> freq;
        for (auto& p : points)
            freq[p[1]]++;

        vector<long long> vals;
        for (auto& [y, cnt] : freq) {
            if (cnt >= 2) {
                long long c = 1LL * cnt * (cnt - 1) / 2;
                vals.push_back(c % mod);
            }
        }

        long long sum = 0, sumSq = 0;
        for (auto v : vals) {
            sum = (sum + v) % mod;
            sumSq = (sumSq + v * v % mod) % mod;
        }

        long long ans = (sum * sum % mod - sumSq + mod) % mod;
        ans = ans * ((mod + 1) / 2) % mod;  

        return ans;
    }
};
