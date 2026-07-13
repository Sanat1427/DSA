class Solution {
public:
    vector<int>compute(string s){
        int n = s.size();
        vector<int>lps(n,0);
        int j=0;
        int i =1;
        while(i<n){
            if(s[i]==s[j]){
                lps[i]=j+1;
                i++;
                j++;
            }
            else{
                while(j>0 && s[i]!=s[j]){
                    j=lps[j-1];
                }
                if(s[i]==s[j]){
                    lps[i]=j+1;
                    j++;
                }
                i++;
            }
        }
        return lps;
    }
    string longestPrefix(string s) {
        vector<int>lps=compute(s);
        return s.substr(0,lps[s.size()-1]);
    }
};