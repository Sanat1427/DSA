class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n = s1.size();
        int  m = s2.size();
        vector<int>a1(26,0);
       for(int i =0;i<n;i++){
        a1[s1[i]-'a']++;
       }
       int l =0;
       int r =0;
      vector<int>a2(26,0);
       while(r<m){
        a2[s2[r]-'a']++;
        if(r-l+1==n){
            if(a1==a2)
           return true;
           a2[s2[l]-'a']--;
           l++;
        }
        r++;
        


       }
        return false;
    }
};