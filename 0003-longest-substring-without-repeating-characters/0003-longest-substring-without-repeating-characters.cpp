class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        if (n == 0) return 0;

        unordered_map<char, int> mpp;
        mpp[s[0]]++;

        int l = 0;
        int len = 1;

        for (int r = 1; r < n; r++) {
            mpp[s[r]]++;

            while (mpp[s[r]] > 1) {
                mpp[s[l]]--;
                l++;
            }

            len = max(len, r - l + 1);
        }

        return len;
    }
};