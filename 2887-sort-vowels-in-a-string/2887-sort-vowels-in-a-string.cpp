class Solution {
    bool isvowel(char ch) {
        if (ch=='a'||ch=='A'||ch=='e'||ch=='E'||ch=='i'||ch=='I'||ch=='o'||ch=='O'||ch=='u'||ch=='U')
            return true;
        return false;
    }
public:
    string sortVowels(string s) {
        int n = s.size();
        map<char,int> mpp;

     
        for (int i = 0; i < n; i++) {
            if (isvowel(s[i])) {
                mpp[s[i]]++;
            }
        }

     
        int idx = 0;
        for (auto it : mpp) {
            char vowel = it.first;
            int cnt = it.second;
            while (cnt > 0 && idx < n) {
                if (isvowel(s[idx])) {
                    s[idx] = vowel;
                    cnt--;
                }
                idx++;
            }
        }
        return s;
    }
};
