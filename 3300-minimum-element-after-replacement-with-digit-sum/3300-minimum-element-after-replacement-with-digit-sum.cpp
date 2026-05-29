class Solution {
public:
    int minElement(vector<int>& nums) {
     int n = nums.size();
     vector<int>ans(n,0);
     for(int i =0;i<n;i++){
        if(nums[i]<10){
            ans[i]=nums[i];

        }
        else{
            int sum =0;
            while(nums[i]>0){
                 sum+=nums[i]%10;
                 nums[i]= nums[i]/10;

            }
            ans[i]= sum;
        }

     }
     sort(ans.begin(),ans.end());
     return ans[0];
    
    }
};