class Solution {
public:
    int myAtoi(string s) {
        int n = s.size();
        int sign =1;
        int i =0;
        while(i<n && s[i]==' ')
        i++;
        if(s[i]=='-'){
            sign*=-1;
            i++;
        }
        else if( s[i]=='+'){
            sign*=1;
            i++;
        }
        long long r =0;
        while(i<n && isdigit(s[i])){
            r= r*10+s[i]-'0';
            i++;
            if(r*sign>=INT_MAX)
            return INT_MAX;
            else if( r*sign<=INT_MIN)
            return INT_MIN;
             
        }
        return r*sign;
        

    }
};