class Solution {
public:
    bool areAnagrams(const string &s1, const string &s2) {
        if (s1.length() != s2.length()) return false;
        string a = s1, b = s2;
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());
        return a == b;
    }

    vector<string> removeAnagrams(vector<string>& words) {
        vector<string> result;
        if (words.empty()) return result;

        result.push_back(words[0]);

        for (int i = 1; i < words.size(); i++) {
            if (!areAnagrams(words[i], result.back())) {
                result.push_back(words[i]);
            }
        }

        return result;
    }
};