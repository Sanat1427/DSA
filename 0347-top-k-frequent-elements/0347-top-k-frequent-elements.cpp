class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int,int>mpp;
        for(auto it :nums){
            mpp[it]++;
        }
    vector<pair<int, int>> ans;
        for(auto it :mpp){
            ans.push_back({it.second,it.first});
        }
        sort(ans.begin(),ans.end());
        n= ans.size();
        vector<int>a;
        for(int i =n-1;i>=n-k;i-- ){
            a.push_back(ans[i].second);
        }
        return a;
    }
};