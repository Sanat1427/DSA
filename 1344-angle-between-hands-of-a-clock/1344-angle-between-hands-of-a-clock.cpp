class Solution {
public:
    double angleClock(int hour, int minutes) {
        double ans =0;
        int ma= minutes*6;
        double ha = 30*hour+0.5*minutes;
        double diff= abs(ha-ma);
        ans= min(360-diff,diff);
        return ans;
    }
};