class Solution {
    bool isVowel(char ch) {
        ch = tolower(ch);
        return (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u');
    }

public:
    bool doesAliceWin(string s) {
        int cnt = 0;
        for (char ch : s) {
            if (isVowel(ch)) cnt++;
        }
        if (cnt == 0) return false;
        if (cnt % 2 == 1) return true;
        return true;
    }
};
