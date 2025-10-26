

class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        int n = nums.size();
        vector<int> squares;
        for (int num : nums)
            squares.push_back(num * num);
        sort(squares.begin(), squares.end());
        long long score = 0;
        for (int i = 0; i < n / 2; i++) {
            score += squares[n - 1 - i] - squares[i];
        }
        if (n % 2 == 1)
            score += squares[n / 2];
        return score;
    }
};
