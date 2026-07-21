class Solution {
public:
    string minWindow(string s, string t) {
         int n = s.size();
         int m = t.size();
         int start =0;
         int hash[256]={0};
         for(int i =0;i<m;i++){
             hash[t[i]]++;
         }  
         int l = 0;
         int r =0;
         int cnt =0;
         int mini = INT_MAX;
        while(r<n){
            if(hash[s[r]]>0){
                cnt++;
            }
            hash[s[r]]--;
            while(cnt==t.size()){
                    if (r - l + 1 < mini) {
                    mini = r - l + 1;
                    start = l;
                }
                hash[s[l]]++;
                if(hash[s[l]]>0){
                    cnt--;
                }
                l++;

            }
            r++;
        }
        if(mini == INT_MAX)
        return "";
        return s.substr(start,mini);     
    }
};