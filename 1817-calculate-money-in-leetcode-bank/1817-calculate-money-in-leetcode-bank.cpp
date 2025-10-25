class Solution {
public:
    int totalMoney(int n) {
        int week = n / 7;
        int day = n % 7;

        // Sum for complete weeks
        int total_full_weeks = 28 * week + 7 * (week - 1) * week / 2;

        // Sum for remaining days
        int total_remaining = day * (week + 1) + day * (day - 1) / 2;

        return total_full_weeks + total_remaining;
    }
};
