class Solution {
public:
   void func(int ind , vector<int>&nums,vector<int>&arr,vector<vector<int>>&ans){
    if(ind == nums.size()){
        ans.push_back(arr);
        return ;
    }

    arr.push_back(nums[ind]);
    func(ind+1,nums,arr,ans);
    arr.pop_back();
    for(int i = ind+1;i<nums.size();i++){
        if(nums[ind]!=nums[i]){
            func(i,nums,arr,ans);
            return;
        }
    }
     func(nums.size(),nums,arr,ans);
    
   }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        vector<int>arr;
        vector<vector<int>>ans;
        func(0,nums,arr,ans);
        return ans;
    }
};