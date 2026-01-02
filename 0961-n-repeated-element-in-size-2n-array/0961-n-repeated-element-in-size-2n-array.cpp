class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        int n = nums.size();
        int rep = n/2;
        int ans =0;
        unordered_map<int,int>mpp;
        for(auto it:nums){
            mpp[it]++;
        }
        for(auto it :mpp){
            if(it.second==rep)
            ans= it.first;
        }
        return ans;
    }
};