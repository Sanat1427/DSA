class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int n = gain.size();
        vector<int>ans(n+1);
        ans[0]=0;
        int maxi = INT_MIN;
        for(int i =0;i<n;i++){
            ans[i+1]=gain[i]+ans[i];
           

        }
        for(int i =0;i<n+1;i++){
            if(maxi<ans[i])
             maxi= ans[i];
        }
         return maxi;
    }
};