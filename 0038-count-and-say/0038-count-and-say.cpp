class Solution {
public:
    string countAndSay(int n) {
        if(n==1)
        return "1";
        string res="";
        string prev= countAndSay(n-1);
        int len = prev.size();
        int cnt =1;
        for(int i =1;i<len;i++){
            if(prev[i]==prev[i-1]){
                cnt++;
            }
            else{
                res.push_back('0'+cnt);
                res.push_back(prev[i-1]);
                cnt=1;
            }
        }
        res.push_back('0'+ cnt);
        res.push_back(prev[len-1]);
        return res;
    }
};