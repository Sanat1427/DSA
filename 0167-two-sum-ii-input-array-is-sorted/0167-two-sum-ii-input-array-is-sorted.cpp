class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int n = numbers.size();
       
        int l =0;
        int r =n-1;
        int sum =0;
        vector<int>ans;
        while(l<r){
            sum=numbers[l]+numbers[r];
            if(sum==target){
                ans.push_back(l+1);
                ans.push_back(r+1);
            }
            if(sum>target){
                r--;
            }
            else{
                l++;
            }
            

        }
        return ans;
    }
};