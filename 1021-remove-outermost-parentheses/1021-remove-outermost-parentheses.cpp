class Solution {
public:
    string removeOuterParentheses(string s) {
        string res ="";
        int b=0;
        for(char ch:s){
            if(ch=='('){
                if(b>0){
                    res+=ch;
                }
                b++;
            }
            else if(ch==')'){
                b--;
                if(b>0)
                res+=ch;
                            }

        }
        return res;
    }
};