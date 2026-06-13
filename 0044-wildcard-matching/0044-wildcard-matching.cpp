class Solution {
public:
    bool isMatch(string s, string p) {

        int n = s.size();   // String length
        int m = p.size();   // Pattern length

        // dp[i][j]
        // = Can first i chars of pattern match first j chars of string?
        vector<vector<bool>> dp(m + 1, vector<bool>(n + 1, false));

        // Empty pattern matches empty string
        dp[0][0] = true;

        // First column initialization
        // Matching pattern with empty string
        for (int i = 1; i <= m; i++) {

            // Only consecutive '*' can match an empty string
            // Example:
            // "*"   -> true
            // "**"  -> true
            // "*a"  -> false
            dp[i][0] = (p[i - 1] == '*') && dp[i - 1][0];
        }

        // Fill DP table
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {

                // Case 1:
                // Current characters match
                // OR pattern has '?'
                if (p[i - 1] == s[j - 1] || p[i - 1] == '?') {

                    // Consume one character from both
                    dp[i][j] = dp[i - 1][j - 1];
                }

                // Case 2:
                // Pattern contains '*'
                else if (p[i - 1] == '*') {

                    // dp[i-1][j]
                    // '*' matches empty string
                    //
                    // dp[i][j-1]
                    // '*' matches one more character
                    dp[i][j] = dp[i - 1][j] || dp[i][j - 1];
                }

                // Case 3:
                // Characters don't match
                else {
                    dp[i][j] = false;
                }
            }
        }

        // Entire pattern matches entire string?
        return dp[m][n];
    }
};