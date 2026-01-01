class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size();

        for (int i = n - 1; i >= 0; i--) {
            if (digits[i] < 9) {
                digits[i]++;   // simple increment
                return digits;
            }
            digits[i] = 0;      // carry over
        }
        digits.insert(digits.begin(), 1);
        return digits;
    }
};
