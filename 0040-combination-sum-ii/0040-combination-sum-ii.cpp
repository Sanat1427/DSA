class Solution {
    void func(int ind, int sum, vector<int>&nums,vector<int>&candidates,vector<vector<int>>&ans){
        int n = candidates.size();
        if(sum==0){
            ans.push_back(nums);
            return;
        }
        if(sum<0 || ind == candidates.size()){
            return;
        }
        nums.push_back(candidates[ind]);
        func(ind+1,sum-candidates[ind],nums,candidates,ans);
        nums.pop_back();
        for(int i = ind+1;i<n;i++){
            if(candidates[i]!=candidates[ind]){
                func(i,sum,nums,candidates,ans);
                break;
            }
        }

    }
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        int n = candidates.size();
        vector<vector<int>>ans;
        vector<int>nums;
        sort(candidates.begin(),candidates.end());
        func(0,target,nums,candidates,ans);
        return ans;
    }
};