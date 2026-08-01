class Solution {
public:
    void func(int open , int close, string s, vector<string>&ans,int n){
        if(open==close  && open+close==2*n ){
            ans.push_back(s);
        }
        if(open<n){
          
            func(open+1,close,s+'(',ans,n);
        }
        if(close<open){
            
            func(open,close+1,s+')',ans,n);
        }

    }
    vector<string> generateParenthesis(int n) {
        vector<string>ans;
        
        func(0,0,"",ans,n);
        return ans;
    }
};