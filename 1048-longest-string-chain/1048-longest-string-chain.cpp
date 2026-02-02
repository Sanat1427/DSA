class Solution {
public:
bool checkpossible(string &s1, string &s2) {
    if (s1.size() != s2.size() + 1)
        return false;

    int i = 0, j = 0;

    while (i < s1.size() && j < s2.size()) {
        if (s1[i] == s2[j]) {
            i++;
            j++;
        } else {
            i++;
        }
    }

    return j == s2.size();
}

bool static compare(string &s1,string &s2){
      return s1.size()<s2.size();
}
    int longestStrChain(vector<string>& words) {
       
        int n = words.size();
         if(n==1)
        return 1;
        sort(words.begin(),words.end(),compare);
        vector<int>dp(n,1);
        int maxi=0;
        for(int i =0;i<n;i++){
            for(int j =0;j<i;j++){
                if(checkpossible(words[i],words[j])&&dp[i]<dp[j]+1){
                    dp[i]=dp[j]+1;
                }
                if(maxi<dp[i])
                maxi=dp[i];
                }
            }
        
        return maxi;
    }
};