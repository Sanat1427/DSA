class Solution {  
public:  
    int prefixConnected(vector<string>& words, int k) {  
        int n = words.size();  
        unordered_map<string, int> mpp;  
        int cnt = 0;  

        for (int i = 0; i < n; i++) {  
            if (words[i].size() >= k) {   // safety check
                string sub = words[i].substr(0, k);  
                mpp[sub]++;  
            }
        }  

        for (auto it : mpp) {  
            if (it.second >= 2)  
                cnt++;  
        }  

        return cnt;  
    }  
};
