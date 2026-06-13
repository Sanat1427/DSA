class Solution {
public:
    int numDistinct(string s, string t) {

        int n = s.size();
        int m = t.size();

        // dp[i][j] = Number of ways to form
        // first j characters of t
        // using first i characters of s
      vector<vector<unsigned long long>> dp(
    n + 1,
    vector<unsigned long long>(m + 1, 0)
);

        // Base Case:
        // Empty string t can always be formed
        // from any prefix of s by deleting all characters.
        for (int i = 0; i <= n; i++) {
            dp[i][0] = 1;
        }

        // dp[0][j] = 0 for j > 0
        // Already initialized to 0 because
        // non-empty t cannot be formed from empty s.

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {

                // Current characters match
                if (s[i - 1] == t[j - 1]) {

                    // Choice 1: Use s[i-1] to match t[j-1]
                    // => dp[i-1][j-1]

                    // Choice 2: Skip s[i-1]
                    // => dp[i-1][j]

                    dp[i][j] =
                        dp[i - 1][j - 1] +
                        dp[i - 1][j];
                }
                else {

                    // Characters don't match
                    // Cannot use s[i-1]
                    // Only option is to skip it
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }

        // Number of ways to form entire t from entire s
        return (int)dp[n][m];
    }
};