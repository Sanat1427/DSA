class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        int n = values.size();
         int first = values[0]+0;
         int ans =0;
         for(int i=1;i<n;i++){
            ans = max(ans, first+values[i]-i);
            first = max(first,values[i]+i);

         }
         return ans;
    }
};