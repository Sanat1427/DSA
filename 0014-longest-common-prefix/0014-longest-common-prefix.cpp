class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int n = strs.size();
        sort(strs.begin(),strs.end());
        string ans="";
        string f= strs[0];
        string l = strs[n-1];
        int mini=min(f.size(),l.size());
        for(int i =0;i<mini;i++){
            if(f[i]!=l[i]){
                return ans;
            }
            ans+=f[i];
        }
        return ans;
    }
};