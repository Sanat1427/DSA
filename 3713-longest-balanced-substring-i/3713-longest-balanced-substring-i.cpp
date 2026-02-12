#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestBalanced(string s) {
        int n = s.size();
        int ans = 0;

        for (int i = 0; i < n; i++) {
            unordered_map<char, int> mpp;
            for (int j = i; j < n; j++) {
                mpp[s[j]]++;
                int mn = INT_MAX, mx = 0;
                for (auto &it : mpp) {
                    mn = min(mn, it.second);
                    mx = max(mx, it.second);
                }
                if (mn == mx) ans = max(ans, j - i + 1);
            }
        }
        return ans;
    }
};
