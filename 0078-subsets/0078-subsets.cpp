class Solution {
public:
   void func(int ind, vector<int>&nums,vector<int>&arr,vector<vector<int>>&ans){
    int n = nums.size();
    if(ind == n){
        ans.push_back(arr);
        return ;
    }
   
    func(ind+1,nums,arr,ans);
     arr.push_back(nums[ind]);
      func(ind+1,nums,arr,ans);
     arr.pop_back();
    
   }
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();
        vector<int>arr;
        vector<vector<int>>ans;
        func(0,nums,arr,ans);
        return ans;
    }
};