class Solution {
public:
    int numOfStrings(vector<string>& patterns, string word) {
        int n = patterns.size();
        vector<string>sub;
        unordered_set<string>st;
        for(int i =0;i<word.size();i++){
            for(int j =1;j<=word.size()-i;j++){
                st.insert(word.substr(i,j));
            }
        }
            int cnt =0;
            for(int i =0;i<n;i++){
                string s = patterns[i];
                if(st.find(s)!=st.end())
                cnt++;
            }

            
            return cnt;
        
    }
};