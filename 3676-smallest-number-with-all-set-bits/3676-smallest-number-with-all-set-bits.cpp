class Solution {
public:
    int smallestNumber(int n) {
        int ans = 1;
        for (int i = 0; i <= n; i++) {
            if ((1 << i) - 1 >= n) { 
                ans = (1 << i) - 1;
                break;
            }
        }
        return ans;
    }
};