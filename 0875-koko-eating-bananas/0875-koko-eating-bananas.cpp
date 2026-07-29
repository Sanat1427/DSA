class Solution {
public:
    long long func(vector<int>& piles, int speed) {
        long long t = 0;

        for (int pile : piles) {
            t += (pile + speed - 1) / speed;   // ceil(pile / speed)
        }

        return t;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1;
        int high = *max_element(piles.begin(), piles.end());
        int ans = high;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            long long totalh = func(piles, mid);

            if (totalh <= h) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        return ans;
    }
};