class Solution {
public:
    bool rotateString(string s, string goal) {
        int n = s.size();
        for(int i =0;i<n;i++){
            string res = s.substr(i)+s.substr(0,i);
            if(res==goal)
            return true;
        }
        return false;
    }
};