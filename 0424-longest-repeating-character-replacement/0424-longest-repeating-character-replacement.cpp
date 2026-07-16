class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.size();
        int l =0;
        int r= 0;
        int hash[26]={0};
        int maxi = 0;
             int ans =0;
        while(r<n){
          hash[s[r]-'A']++;
          maxi= max(maxi, hash[s[r]-'A']);
         // know to check the changes
         while((r-l+1)-maxi>k){
            hash[s[l]-'A']--;
            l++;
         }
         int len = r-l+1;
    
         ans = max(ans,r-l+1);
         r++;

        }
        return ans;
    }
};