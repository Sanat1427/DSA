class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows==1 || numRows>=s.size())
        return s;
        vector<string>result(numRows);
        int curr=0;
        bool down = false;
        for(char ch :s){
            result[curr]+=ch;
            if(curr==0 || curr== numRows-1)
            down=!down;
            curr+=down?1:-1;
        }
        string ans;
        for(string&r:result){
            ans+=r;
        }

        return ans;
    }
};