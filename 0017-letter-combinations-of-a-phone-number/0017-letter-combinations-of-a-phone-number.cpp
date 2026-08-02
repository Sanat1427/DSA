class Solution {
    void func(int ind , string s, string digits, vector<string>&ans,string combo[]){
        if(ind == digits.size()){
            ans.push_back(s);
            return;
        }
        int next = digits[ind]-'0';
        for(int i =0;i<combo[next].size();i++){
            func(ind+1,s+combo[next][i],digits,ans,combo);
        }
    }
public:
    vector<string> letterCombinations(string digits) {
    string combo[] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        string s="";
        vector<string>ans;
        if(digits=="")
        return ans;
        func(0,s,digits,ans,combo);
        return ans;
    }
};