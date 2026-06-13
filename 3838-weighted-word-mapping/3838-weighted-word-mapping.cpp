class Solution {
public:
    string mapWordWeights(vector<string>& words, vector<int>& weights) {
        string ans;

        for (string &word : words) {
            int weight = 0;

            // Calculate word weight
            for (char ch : word) {
                weight += weights[ch - 'a'];
            }

            int rem = weight % 26;

            // Reverse alphabetical mapping:
            // 0 -> z, 1 -> y, ..., 25 -> a
            ans.push_back('z' - rem);
        }

        return ans;
    }
};