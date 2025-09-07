class Solution {
public:
    vector<int> sumZero(int n) {
        vector<int>ans;
     for(int i =0;i<n-1;i++){
        ans.push_back(i+1);
     }
     int sum=0;
     for(int i =0;i<n-1;i++){
          sum+=ans[i];
     }
     ans.push_back(-sum);
     return ans;
    }
};