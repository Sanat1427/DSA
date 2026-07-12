class Solution {
public:
    bool isPalindrome(string s) {
        int n = s.size();
        string r ="";
        for(int i =0;i<n;i++){
            if(isalnum(s[i])){
            r.push_back(s[i]);
            }
        }
       for (int i = 0; i < r.size(); i++) {
        
    r[i] = tolower(r[i]);
}
        string a =r;
        reverse(r.begin(),r.end());
        if(a==r)
        return true;
        else 
        return false;
    }
};