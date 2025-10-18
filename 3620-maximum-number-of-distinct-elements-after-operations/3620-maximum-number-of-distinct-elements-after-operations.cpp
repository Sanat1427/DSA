class Solution {
public:
    int maxDistinctElements(vector<int>& nums, int k) {
     int n = nums.size();
     int cnt=0;
     sort(nums.begin(),nums.end());
     int prev=INT_MIN;
     for(int i =0;i<n;i++){
        int minval= nums[i]-k;
        if(prev<minval){
            prev=minval;
            cnt++;
        }
        else if(prev<nums[i]+k){
            prev=prev+1;
            cnt++;
        }
     }
     return cnt;
    }
};