class Solution {
public:
    int maxFreqSum(string s) {
        int n =  s.size();
        map<char,int>mpp;
        for(char ch : s){
            mpp[ch]++;
        }
        int cnt1=0;
        int cnt2=0;
        for(auto it : mpp){
            char ch = it.first;
            int freq = it .second;
            if(ch =='a'||ch=='i'||ch=='e'||ch=='o'||ch=='u'){
                cnt1=max(it.second,cnt1);
            }
            else{
                cnt2=max(it.second,cnt2);
            }
        }
        return cnt1+cnt2;
    }
};