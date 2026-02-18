class Solution {
public:
    bool hasAlternatingBits(int n) {
        int currbit =-1;
        while(n>0){
            if(currbit==n%2)
            return false;
            currbit=n%2;
            n=n/2;
        }
        return true;
    }
};