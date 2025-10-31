class Solution {
public:
    vector<int> getSneakyNumbers(vector<int>& nums) {
        int n = nums.size();
        vector<int>result;
        unordered_map<int,int>mpp;
        for(auto it:nums)
        mpp[it]++;
        for(auto it:mpp){
            if(it.second==2)
            result.push_back(it.first);
        }
        return result;
    }
};