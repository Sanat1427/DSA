class Solution {
public:
     void func(int ind, vector<int>& candidates,vector<int>&arr,vector<vector<int>>&ans,int target){
        int n = candidates.size();
        if(target ==0){
            ans.push_back(arr);
            return;
        }
        if(target<0)
        return ;
        if(ind<0)
        return ;
        func(ind-1,candidates,arr,ans,target);
        arr.push_back(candidates[ind]);
        // not ind-1 , as we take element unlimited times --- 
        func(ind,candidates,arr,ans,target-candidates[ind]);
        arr.pop_back();

        
     }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        int n = candidates.size();
        vector<int>arr;
        vector<vector<int>>ans;
        func(n-1,candidates,arr,ans,target);
        return ans;
    }
};