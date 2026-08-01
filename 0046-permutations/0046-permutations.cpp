class Solution {
public:
  void func(int ind,vector<int>&nums,vector<vector<int>>&ans){
    if(ind==nums.size()){
        ans.push_back(nums);
        return ;
    }
    for(int i = ind;i<nums.size();i++){
        swap(nums[ind],nums[i]);
        func(ind+1,nums,ans);
        swap(nums[i],nums[ind]);
    }
  }
    vector<vector<int>> permute(vector<int>& nums) {
        int n = nums.size();
       
        vector<vector<int>>ans;
        func(0,nums,ans);
        return ans;
    }
};