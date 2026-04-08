class Solution {
public:
int mod= 1e9+7;
     long long powmod(long long base, long long exp){
        base%=mod;
        long long res=1;
        while(exp>0){
            if(exp%2==1){
                res=(res*base)%mod;
            }
            base= (base*base)%mod;
            exp/=2;
        }
        return res;
     }
    int countGoodNumbers(long long n) {
    
        long long even=(n+1)/2;
        long long odd= n/2;
        long long ans = powmod(5,even)*powmod(4,odd);
        return ans%mod;
    }
};