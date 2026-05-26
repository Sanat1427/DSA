class Solution {
public:
    int numberOfSpecialChars(string word) {
        int n = word.size();
        set<char>lower,upper;
        for(char ch : word){
            if(islower(ch)){
                lower.insert(ch);
            }
            else if(isupper(ch)){
                upper.insert(tolower(ch));
            }
        }
        int cnt =0;
        for(char ch : lower){
            if(upper.count(ch))
            cnt++;
        }
        return cnt;
    }
};