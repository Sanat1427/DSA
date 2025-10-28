class Solution {
public:
    int beautySum(string s) {
        int n = s.size();
        int sum =0;
        for(int i =0;i<n;i++){
            unordered_map<char,int>mpp;
            for(int j =i;j<n;j++){
                mpp[s[j]]++;

                int mx =INT_MIN;
                int mn =INT_MAX;
                for(auto it:mpp){
                    mx=max(mx,it.second);
                    mn=min(mn,it.second);

                }
                sum+=(mx-mn);
            }
        }
        return sum;
    }
};