class Solution {
public:
    bool canship(vector<int>& nums, int capacity, int days){
        int rdays = 1;
        int currload = 0;

        for(int w : nums){
            if(currload + w > capacity){
                rdays++;
                currload = w;   // ✅ FIX
            }
            else{
                currload += w;
            }
        }
        return rdays <= days;
    }

    int shipWithinDays(vector<int>& weights, int days) {
        int low = *max_element(weights.begin(), weights.end());
        int high = accumulate(weights.begin(), weights.end(), 0);
        int ans = high;

        while(low <= high){
            int mid = (low + high) / 2;

            if(canship(weights, mid, days)){
                ans = mid;
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }
        }
        return ans;
    }
};