class Solution {
public:
    int minPartitions(string n) {
       int maxi=-1;
        for(char ch :n){
            int digit=ch-'0';
            if(digit>maxi){
                maxi=digit;
            }
        }
        return maxi;
    }
};