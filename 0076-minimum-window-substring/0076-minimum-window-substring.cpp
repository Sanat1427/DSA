class Solution {
public:
    string minWindow(string s, string t) {
        int n = s.size();
        int mini  = INT_MAX;
        int l =0;
        int r =0;
        int si =-1;
        int hash[256]={0};
        int cnt =0;
        for (char c :t){
            hash[c]++;
        }
        while(r<n){
            if(hash[s[r]]>0){
                cnt++;
            }
            hash[s[r]]--;
           while (cnt==t.size()){
              if(mini>r-l+1){
                mini =  r-l+1;
                si = l ; 
              }
                hash[s[l]]++;
            
              
            if(hash[s[l]] > 0) {
                    cnt--;
                }
            l++;
           }
            r++;

        }
        return (si==-1)?"":s.substr(si,mini);
    }
};