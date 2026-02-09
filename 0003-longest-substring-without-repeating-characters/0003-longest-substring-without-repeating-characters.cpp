class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        int hashlen = 256;
        int hash[hashlen];
        for(int i =0;i<256;i++)
        hash[i]=-1;
        int l=0;
        int r=0;
        int maxi=0;
        while(r<n){
        if(hash[s[r]]!=-1){
            l=max(hash[s[r]]+1,l);
        }
        int len =r-l+1;
        maxi=max(maxi,len);
         hash[s[r]]=r;
         r++;
        }
        return maxi;
    }
};