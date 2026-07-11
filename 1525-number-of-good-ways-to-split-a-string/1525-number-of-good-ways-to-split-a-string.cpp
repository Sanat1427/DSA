class Solution {
public:
 
    int numSplits(string s) {
         int n = s.size();
         vector<int>prefix(n);
         vector<int>suffix(n);
         unordered_map<char,int>l;
         unordered_map<char,int>r;
         for(int i =0;i<n;i++){
            l[s[i]]++;
            prefix[i]=l.size();
         }
         for(int i = n-1;i>=0;i--){
            r[s[i]]++;
            suffix[i]=r.size();
         }
         int cnt =0;
         for(int i =0;i<n-1;i++){
            if(prefix[i]==suffix[i+1])
            cnt++;
         }
         return cnt;
              
    }
};