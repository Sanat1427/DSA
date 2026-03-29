class Solution {
public:
    bool canBeEqual(string s1, string s2) {
        int n = s1.size();
        unordered_map<char,int>e1,e2;
        unordered_map<char,int>o1,o2;
        for(int i =0;i<n;i++){
            if(i%2){
                e1[s1[i]]++;
                e2[s2[i]]++;
            }
            else{
                o1[s1[i]]++;
                o2[s2[i]]++;
            }
        }
        return (e1==e2 && o1==o2);

    }
};