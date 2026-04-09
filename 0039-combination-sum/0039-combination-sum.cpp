class Solution {
public:
void func(int ind, vector<int>& candidates, int sum ,   vector<vector<int>>& ans,vector<int>& arr){
    
        if(sum==0){
            ans.push_back(arr);
            return;
        }
        if(sum<0)
        return ;
        if(ind<0)
        return;
       func(ind-1,candidates,sum,ans,arr);
       arr.push_back(candidates[ind]);
       func(ind,candidates,sum-candidates[ind],ans,arr);
       arr.pop_back();
    }
  

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        int n = candidates.size();
        vector<vector<int>>ans;
        vector<int>arr;
        func(n-1,candidates,target,ans,arr);
        return ans;
    }
};